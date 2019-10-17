#include <iostream>
#include <CoffmanGrahamAlgorithm.h>

int main() {
	Graph g({Edges({ Vertex(5) }),
			 Edges({ Vertex(0), Vertex(3) }),
			 Edges(),
			 Edges({ Vertex(4), Vertex(5) }),
			 Edges(),
			 Edges()
	});
	PrintGraph(g);

	CoffmanGrahamAlgorithm algorithm(g, LayeringWidth(2));
	auto layers = algorithm.Apply();

//	// test reversing
//	PrintGraph(algorithm.GetReversed());
//
//	// test labeling
//	for (int label : algorithm.GetLabels()) {
//		cout << label << " ";
//	}
//	cout << endl;

	// print layers
	cout << layers.size() << endl;
	for (auto it = layers.rbegin(); it != layers.rend(); it++) {
	    for (auto v : *it) {
	        cout << v.get() << " ";
	    }
	    cout << endl;
	}


	return 0;
}