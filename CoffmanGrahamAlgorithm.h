#pragma once

#include <Graph.h>
#include <NamedType.h>

struct LayeringWidthParameter {};

using LayeringWidth = NamedType<int, LayeringWidthParameter>;

class CoffmanGrahamAlgorithm {
public:
	CoffmanGrahamAlgorithm(const Graph& g, LayeringWidth w) : graph(g), width(w), reversed({}) {}
	void Apply();

	const Graph& GetReversed() { return reversed; }
private:
	const Graph& graph;
	LayeringWidth width;
	Graph reversed;

	void buildReversed();
	void labelLexicographically();
	void fillLayers();
};

