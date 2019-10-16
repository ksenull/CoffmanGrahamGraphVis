#pragma once

#include <Graph.h>
#include <NamedType.h>
#include <set>

struct LayeringWidthParameter {};
using LayeringWidth = NamedType<int, LayeringWidthParameter>;

//using LayeringWidth = int;

class CoffmanGrahamAlgorithm {
public:
	CoffmanGrahamAlgorithm(const Graph& g, LayeringWidth w) : graph(g), width(w) {}
	void Apply();

	const Graph& GetReversed() { return reversed; }
	const vector<int>& GetLabels() { return labels; }
private:
	const Graph& graph;
	LayeringWidth width;
	Graph reversed;
	vector<int> labels;

	void buildReversed();
	void labelLexicographically();
	void fillLayers();

	set<int> getParentLabels(Vertex v);
	static bool lexicographicallyLess(const set<int>& a, const set<int>& b);
	static bool recursiveLess(set<int>&& a, set<int>&& b);
};

