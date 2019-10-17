#include <CoffmanGrahamAlgorithm.h>
#include <set>
#include <map>


vector<vector<Vertex>> CoffmanGrahamAlgorithm::Apply() {
	buildReversed();
	labelLexicographically();
	fillLayers();
	return layers;
}

void CoffmanGrahamAlgorithm::buildReversed() {
	reversed.get().resize(graph.get().size());
	for (int i = 0; i < graph.get().size(); i++) {
		for (auto e: graph.get()[i].get()) {
			reversed.get()[e.get()].get().emplace_back( i );
		}
	}
}

void CoffmanGrahamAlgorithm::labelLexicographically() {
	auto rootEdgesIt = find( reversed.get().begin(), reversed.get().end(), Edges({}));
	Vertex root(static_cast<int>(std::distance(reversed.get().begin(), rootEdgesIt)));

	labels.resize(reversed.get().size(), 0);
	labels[root.get()] = 1;

	auto chooseNext = [&]() {
		Vertex minimum(root.get());
		set<int> minimumLabels;
		for (int i = 1; i <= labels.size(); i++) { // create the biggest set possible
			minimumLabels.emplace(i);
		}
		for (int i = 0; i < reversed.get().size(); i++) {
			if (labels[i] != 0) {
				continue;
			}
			set<int> vLabels = getParentLabels(Vertex(i));
			if (vLabels.find(0) != vLabels.end()) {
				continue;
			}

			if (lexicographicallyLess(vLabels, minimumLabels)) {
				minimum = Vertex(i);
				minimumLabels = vLabels;
			}
		}
		return minimum;
	};

	for (int k = 2; k <= graph.get().size(); k++) {
		auto v = chooseNext();
		labels[v.get()] = k;
	}
}

void CoffmanGrahamAlgorithm::fillLayers() {
    vector<Vertex> layer;
    map<int, Vertex> unvisited;

    // get all unvisited and order them by label
    for (int i = 0; i < labels.size(); i++) {
        unvisited.emplace(labels[i], Vertex(i));
    }

    while (!unvisited.empty()) {
        // get unvisited with maximum label
        Vertex v(unvisited.rbegin()->second);
        Edges children = graph.get()[v.get()];
        if (any_of(children.get().begin(), children.get().end(), [&](Vertex u) {
            return unvisited.find(labels[u.get()]) != unvisited.end();
        })) {
            continue;
        }
        if (layer.size() < width.get() and none_of(children.get().begin(), children.get().end(), [&](Vertex u) {
            return find(layer.begin(), layer.end(), u) != layer.end();
        })) { // children should be on previous layer means that they should not be in current layer
            layer.emplace_back(v);
        } else {
            layers.emplace_back(layer);
            layer.clear();
            layer.emplace_back(v);
        }
        unvisited.erase(unvisited.find(labels[v.get()]));
    }
    layers.emplace_back(layer);
}

set<int> CoffmanGrahamAlgorithm::getParentLabels( Vertex v ) {
	set<int> result;
	for (auto p : reversed.get()[v.get()].get()) {
		result.emplace(labels[p.get()]);
	}
	return result;
}

bool CoffmanGrahamAlgorithm::lexicographicallyLess(const set<int>& first, const set<int>& second ) {
	auto firstCopy = first;
	auto secondCopy = second;
	return recursiveLess( std::move(firstCopy), std::move(secondCopy));
}

bool CoffmanGrahamAlgorithm::recursiveLess( set<int>&& a, set<int>&& b ) {
	if (b.empty()) {
		return false;
	}
	if (a.empty()) {
		return !b.empty();
	}

	// last element is maximum in set
	int maxA = *a.rbegin();
	int maxB = *b.rbegin();
	if (maxA > maxB) {
		return false;
	}

	a.erase(a.find(maxA));
	b.erase(b.find(maxB));
	return (maxA < maxB) || recursiveLess(std::move(a), std::move(b));
}
