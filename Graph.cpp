#include <Graph.h>

#include <iostream>

void PrintGraph(const Graph& g) {
    cout << g.get().size() << endl;
	for (int i = 0; i < g.get().size(); i++) {
//		cout << i << "\t";
		for (auto v: g.get()[i].get()) {
			cout << v.get() << " ";
		}
		cout << endl;
	}
}
