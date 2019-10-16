#include <iostream>
#include <CoffmanGrahamAlgorithm.h>

int main() {
	Graph g({Edges({Vertex(1), Vertex(2)}), Edges({}), Edges({})});
	PrintGraph(g);

	CoffmanGrahamAlgorithm algorithm(g, LayeringWidth(2));
	algorithm.Apply();

	PrintGraph(algorithm.GetReversed());
	return 0;
}