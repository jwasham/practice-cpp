#include <string>
#include "Graph.h"

#ifndef PROJECT_DIRECTEDGRAPH_H
#define PROJECT_DIRECTEDGRAPH_H

namespace jw {

class DirectedGraph : public Graph {
 public:
  DirectedGraph(const std::string);
  ~DirectedGraph() = default;
  DirectedGraph(const DirectedGraph &) = delete;
  DirectedGraph &operator=(const DirectedGraph &) = delete;

  void AddEdge(const int source, const int destination) {}
  void DFS() {}
  void PrintDebug() {}
};

}  // namespace jw

#endif  // PROJECT_DIRECTEDGRAPH_H
