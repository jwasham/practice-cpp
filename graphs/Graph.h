#include <iostream>
#include <string>
#include "GraphRepresentation.h"

#ifndef PROJECT_GRAPH_H
#define PROJECT_GRAPH_H

namespace jw {

class Graph {
 public:
  Graph() {};
  Graph(const std::string) {}
  ~Graph() = default;
  Graph(const Graph &) = delete;
  Graph &operator=(const Graph &) = delete;

  virtual void AddEdge(const int source, const int destination) = 0;
  virtual void DFS() = 0;
  virtual void BFS() = 0;
  virtual void PrintDebug() = 0;

  std::unique_ptr<GraphRepresentation> representation_;
  int vertices_;
};

}  // namespace jw

#endif  // PROJECT_GRAPH_H
