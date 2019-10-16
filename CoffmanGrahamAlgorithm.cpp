#include <CoffmanGrahamAlgorithm.h>


void CoffmanGrahamAlgorithm::Apply() {
	buildReversed();
	labelLexicographically();
	fillLayers();
}

void CoffmanGrahamAlgorithm::buildReversed() {
	reversed.get().resize(graph.get().size(), {Edges({})});
	for (int i = 0; i < graph.get().size(); i++) {
		for (auto e: graph.get()[i].get()) {
			reversed.get()[e.get()].get().push_back(Vertex(i));
		}
	}
}

void CoffmanGrahamAlgorithm::labelLexicographically() {

}

void CoffmanGrahamAlgorithm::fillLayers() {

}
