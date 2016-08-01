#include <iostream>
#include <string>
#include <vector>

#ifndef PROJECT_GRAPH_REPRESENTATION_H
#define PROJECT_GRAPH_REPRESENTATION_H

namespace jw {

class GraphRepresentation {
 public:
  static const std::string kRepresentationTypeList;
  static const std::string kRepresentationTypeMatrix;
  static const std::string kGraphTypeDirected;
  static const std::string kGraphTypeUndirected;

  static std::unique_ptr<jw::GraphRepresentation> GetRepresentation(
      const std::string representation_type, const std::string graph_type);

  GraphRepresentation() {}
  GraphRepresentation(const std::string graph_type);
  ~GraphRepresentation() = default;
  GraphRepresentation(const GraphRepresentation &) = delete;
  GraphRepresentation &operator=(const GraphRepresentation &) = delete;

  virtual void AddEdge(const int source, const int destination) = 0;

  std::string type_;
  int vertices_;
};

class GraphRepresentationList : public GraphRepresentation {
 public:
  GraphRepresentationList(const std::string graph_type)
      : GraphRepresentation(graph_type) {}
  void AddEdge(const int source, const int destination);

  std::vector<std::vector<int>> adj_list_;
};

class GraphRepresentationMatrix : public GraphRepresentation {
 public:
  GraphRepresentationMatrix(const std::string graph_type)
      : GraphRepresentation(graph_type) {}
  void AddEdge(const int source, const int destination);
};

}  // namespace jw

#endif  // PROJECT_GRAPH_REPRESENTATION_H
