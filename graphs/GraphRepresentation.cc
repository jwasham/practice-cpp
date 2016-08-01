#include "GraphRepresentation.h"

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
  } else if (representation_type == kRepresentationTypeMatrix) {
    return std::unique_ptr<GraphRepresentation>{
        new GraphRepresentationMatrix(graph_type)};
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
  unsigned long source_index = static_cast<unsigned long>(source);
  unsigned long size_required = source_index * 2 + 1;

  if (adj_list_.capacity() < size_required) {
    adj_list_.resize(size_required);
  }

  auto adjacent_vertices = adj_list_.at(source_index);

  if (adjacent_vertices.empty()) {
    vertices_++;
  }

  // find it so we don't add edge twice
  std::vector<int>::iterator it;
  it = std::find(adjacent_vertices.begin(), adjacent_vertices.end(),
                 destination);

  if (it != adjacent_vertices.end()) {
    adj_list_.at(source_index).push_back(destination);
  }
}

void GraphRepresentationMatrix::AddEdge(const int source,
                                        const int destination) {
  std::cout << "down in matrix " << std::endl;
}

}  // namespace jw