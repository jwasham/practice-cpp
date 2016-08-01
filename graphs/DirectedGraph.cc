#include "DirectedGraph.h"

namespace jw {

DirectedGraph::DirectedGraph(const std::string representation_type) {
  representation_ = GraphRepresentation::GetRepresentation(
      representation_type, GraphRepresentation::kGraphTypeDirected);
}

void AddEdge(const int source, const int destination) {
  std::cout << "adding an edge" << std::endl;
}

void DFS() { std::cout << "running dfs" << std::endl; }

void PrintDebug() { std::cout << "print debugging" << std::endl; }

}  // namespace jw