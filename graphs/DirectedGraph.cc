#include "DirectedGraph.h"

namespace jw {

DirectedGraph::DirectedGraph(const std::string representation_type) {
  representation_ = GraphRepresentation::GetRepresentation(
      representation_type, GraphRepresentation::kGraphTypeDirected);
}

void DirectedGraph::AddEdge(const int source, const int destination) {
  representation_->AddEdge(source, destination);
}

void DirectedGraph::DFS() { representation_->DFS(); }

void DirectedGraph::BFS() { representation_->BFS(); }

void DirectedGraph::PrintDebug() { representation_->PrintDebug(); }

}  // namespace jw