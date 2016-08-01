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
  if (graph_type == kGraphTypeDirected) {
    type_ = kGraphTypeDirected;
  } else if (graph_type == kGraphTypeDirected) {
    type_ = kGraphTypeUndirected;
  }
}

}  // namespace jw