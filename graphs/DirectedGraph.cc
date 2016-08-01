#include "DirectedGraph.h"

namespace jw {

DirectedGraph::DirectedGraph(const std::string representation_type) {
  representation_ = GraphRepresentation::GetRepresentation(
      representation_type, GraphRepresentation::kGraphTypeDirected);
}

void DirectedGraph::AddEdge(const int source, const int destination) {
  representation_->AddEdge(source, destination);
}

void DirectedGraph::DFS() { std::cout << "running dfs" << std::endl; }

void DirectedGraph::PrintDebug() {
  std::cout << "print debugging" << std::endl;
}

}  // namespace jw