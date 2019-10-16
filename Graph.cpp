#include <Graph.h>

#include <iostream>

void PrintGraph(const Graph& g) {
	for (int i = 0; i < g.get().size(); i++) {
		cout << i << "\t";
		for (auto v: g.get()[i].get()) {
			cout << v.get() << " ";
		}
		cout << endl;
	}
}
