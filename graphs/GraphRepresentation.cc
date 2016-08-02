#include "GraphRepresentation.h"
#include <curses.h>

namespace jw {

const std::string GraphRepresentation::kRepresentationTypeList{"list"};
const std::string GraphRepresentation::kRepresentationTypeMatrix{"matrix"};
const std::string GraphRepresentation::kGraphTypeDirected{"directed"};
const std::string GraphRepresentation::kGraphTypeUndirected{"undirected"};

std::unique_ptr<jw::GraphRepresentation> GraphRepresentation::GetRepresentation(
    const std::string representation_type, const std::string graph_type) {
  if (representation_type == kRepresentationTypeList) {
    return std::unique_ptr<GraphRepresentation>{
        new GraphRepresentationList(graph_type)};
    //  } else if (representation_type == kRepresentationTypeMatrix) {
    //    return std::unique_ptr<GraphRepresentation>{
    //        new GraphRepresentationMatrix(graph_type)};
  } else {
    std::cerr << "Graph Representation type not supported.";
    exit(EXIT_FAILURE);
  }
}

GraphRepresentation::GraphRepresentation(const std::string graph_type) {
  vertices_ = {0};

  if (graph_type == kGraphTypeDirected) {
    type_ = kGraphTypeDirected;
  } else if (graph_type == kGraphTypeDirected) {
    type_ = kGraphTypeUndirected;
  }
}

void GraphRepresentationList::AddEdge(const int source, const int destination) {
  // todo when type_ undirected graph, make 2 edges

  unsigned long source_index = static_cast<unsigned long>(source);
  int size_required = std::max(source, destination) + 1;

  while (adj_list_.size() < size_required) {
    adj_list_.push_back(std::vector<int>());
  }

  auto adjacent_vertices = adj_list_.at(source_index);

  // find it so we don't add edge twice
  std::vector<int>::iterator it;
  it = std::find(adjacent_vertices.begin(), adjacent_vertices.end(),
                 destination);

  if (it == adjacent_vertices.end()) {
    adj_list_.at(source_index).push_back(destination);
  }

  vertices_ = static_cast<int>(adj_list_.size());
}

void GraphRepresentationList::DFS() {
  std::vector<int> components;

  const int NULL_PARENT = -1;
  int* parents = new int[vertices_]();
  assert(parents);
  std::fill_n(parents, vertices_, NULL_PARENT);

  std::cout << "\n------------\nDFS: " << std::endl;

  for (unsigned long i = 0; i < adj_list_.size(); ++i) {
    if (parents[i] == NULL_PARENT) {
      components.push_back(i);
    }

    std::stack<int> to_visit;

    to_visit.push(i);

    while (!to_visit.empty()) {
      int vertex = to_visit.top();
      to_visit.pop();

      std::cout << vertex << " ";

      for (unsigned long n = 0; n < adj_list_[vertex].size(); n++) {
        int neighbor = adj_list_[vertex].at(n);
        if (parents[neighbor] == NULL_PARENT) {
          parents[neighbor] = vertex;
          to_visit.push(neighbor);
        }
      }
    }
  }

  std::cout << "\n\nParents:\n";

  for (int i = 0; i < vertices_; ++i) {
    std::cout << i << " : " << parents[i] << std::endl;
  }

  std::cout << "\nComponents: " << components.size() << std::endl;
  for (auto it = components.begin(); it != components.end(); ++it) {
    std::cout << *it << " ";
  }

  putchar('\n');

  delete[] parents;
}

void GraphRepresentationList::BFS() {
  std::vector<int> components;

  const int NULL_PARENT = -1;
  int* parents = new int[vertices_]();
  assert(parents);
  std::fill_n(parents, vertices_, NULL_PARENT);

  std::cout << "\n------------\nBFS: " << std::endl;

  for (unsigned long i = 0; i < adj_list_.size(); ++i) {
    if (parents[i] == NULL_PARENT) {
      components.push_back(i);
    }

    std::queue<int> to_visit;

    to_visit.push(i);

    while (!to_visit.empty()) {
      int vertex = to_visit.front();
      to_visit.pop();

      std::cout << vertex << " ";

      for (unsigned long n = 0; n < adj_list_[vertex].size(); n++) {
        int neighbor = adj_list_[vertex].at(n);
        if (parents[neighbor] == NULL_PARENT) {
          parents[neighbor] = vertex;
          to_visit.push(neighbor);
        }
      }
    }
  }

  std::cout << "\n\nParents:\n";

  for (int i = 0; i < vertices_; ++i) {
    std::cout << i << " : " << parents[i] << std::endl;
  }

  std::cout << "\nComponents: " << components.size() << std::endl;
  for (auto it = components.begin(); it != components.end(); ++it) {
    std::cout << *it << " ";
  }

  putchar('\n');

  delete[] parents;
}

void GraphRepresentationList::PrintDebug() {
  std::cout << "Adjacency list:" << std::endl;
  std::cout << "Vertices: " << vertices_ << std::endl;

  for (unsigned long i = 0; i < adj_list_.size(); ++i) {
    std::cout << i << ":";
    for (unsigned long j = 0; j < adj_list_[i].size(); ++j) {
      std::cout << " " << adj_list_.at(i).at(j);
    }
    std::cout << std::endl;
  }
}

bool GraphRepresentationList::ContainsCycle() {
  bool contains_cycle = FALSE;
  const int STATUS_NEW = 0;
  const int STATUS_STARTED = 1;
  const int STATUS_FINISHED = 2;

  for (unsigned long i = 0; i < adj_list_.size(); ++i) {
    int* nodes = new int[vertices_]();
    assert(nodes);
    std::fill_n(nodes, vertices_, STATUS_NEW);
    std::stack<int> to_visit;

    to_visit.push(i);

    while (!(to_visit.empty() || contains_cycle)) {
      int vertex = to_visit.top();
      to_visit.pop();

      if (nodes[vertex] == STATUS_STARTED) {
        nodes[vertex] = STATUS_FINISHED;
        // std::cout << vertex << " finished" << std::endl;
        continue;
      }

      // std::cout << vertex << " started" << std::endl;
      nodes[vertex] = STATUS_STARTED;

      // push bach onto stack so we can tell when vertex is finished
      to_visit.push(vertex);

      for (unsigned long n = 0; n < adj_list_[vertex].size(); n++) {
        int neighbor = adj_list_[vertex].at(n);

        if (nodes[neighbor] == STATUS_NEW) {
          to_visit.push(neighbor);
        } else if (nodes[neighbor] == STATUS_STARTED) {
          contains_cycle = TRUE;
          break;
        } else if (nodes[neighbor] == STATUS_FINISHED) {
          // skip, already seen
        }
      }
    }

    delete[] nodes;
  }

  return contains_cycle;
}

// void GraphRepresentationMatrix::AddEdge(const int source,
//                                        const int destination) {
//  // todo when type_ undirected graph, make 2 edges
//}
//
// void GraphRepresentationMatrix::DFS() {
//  // todo make this
//}
//
// void GraphRepresentationMatrix::BFS() {
//  // todo make this
//}
//
// void GraphRepresentationMatrix::PrintDebug() {
//  // todo make this
//}

}  // namespace jw