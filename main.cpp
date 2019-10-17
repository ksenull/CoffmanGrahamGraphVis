#include <iostream>
#include <CoffmanGrahamAlgorithm.h>

int main() {
	Graph g({Edges({ Vertex(9) }),
			 Edges({ Vertex(0), Vertex(7), Vertex(8) }),
			 Edges({ Vertex(1),  Vertex(3) }),
			 Edges({ Vertex(5), Vertex(6), Vertex(7), Vertex(9) }),
			 Edges(),
			 Edges(),
			 Edges(),
			 Edges({ Vertex(8) }),
			 Edges({ Vertex(10), Vertex(11) }),
			 Edges({ Vertex(10) }),
			 Edges({ Vertex(12) }),
			 Edges({ Vertex(12), Vertex(13) }),
			 Edges({ Vertex(14) }),
			 Edges({ Vertex(14) }),
			 Edges()
	});
	PrintGraph(g);

	CoffmanGrahamAlgorithm algorithm(g, LayeringWidth(4));
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