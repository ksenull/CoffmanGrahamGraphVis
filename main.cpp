#include <iostream>
#include <CoffmanGrahamAlgorithm.h>

int main() {
	Graph g({Edges({ Vertex(5) }),
			 Edges({ Vertex(0), Vertex(3) }),
			 Edges({ }),
			 Edges({ Vertex(4), Vertex(5) }),
			 Edges({ }),
			 Edges({ })
	});
	PrintGraph(g);

	CoffmanGrahamAlgorithm algorithm(g, LayeringWidth(2));
	algorithm.Apply();

	PrintGraph(algorithm.GetReversed());

	for (int label : algorithm.GetLabels()) {
		cout << label << " ";
	}
	cout << endl;
	return 0;
}