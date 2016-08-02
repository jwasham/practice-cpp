#include "DirectedGraph.h"
#include "Graph.h"
//#include "experiments.h"

int main(int argc, char* argv[]) {
  using namespace jw;

  //  print_vector();
  //  print_random();
  //  string_fun();
  //  input_test();
  //  vectors();

  auto dg = new DirectedGraph(GraphRepresentation::kRepresentationTypeList);

  dg->AddEdge(0, 1);
  dg->AddEdge(0, 5);
  dg->AddEdge(1, 2);
  dg->AddEdge(2, 4);
  dg->AddEdge(2, 6);
  dg->AddEdge(3, 2);
  dg->AddEdge(5, 8);
  dg->AddEdge(6, 5);
  dg->AddEdge(7, 5);

  dg->DFS();
  dg->BFS();

  return 0;
}
