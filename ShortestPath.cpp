
#include "ShortestPath.h"


ShortestPath::ShortestPath()
{
}


ShortestPath::~ShortestPath()
{
}

void ShortestPath::findShortestPath(Graph g, int src, int dst)
{
	
		vector<VisitedPath> visitedPath;
		vector<int> queue;

		for (int i = 0; i < g.vertices.size(); i++) {
			VisitedPath vp;
			vp.visited = false;
			visitedPath.push_back(vp);
		}

		queue.push_back(src);
		int previous = src;
		int current = src;

		while (!queue.empty() && current != dst) {
			previous = current;
			current = queue[0];
			queue.erase(queue.begin());

			visitedPath[current].path.push_back(current);
			for (int i = 0; i < g.vertices[current].neighbors.size(); i++) {
				if (visitedPath[g.vertices[current].neighbors[i]].visited == false) {
					queue.push_back(g.vertices[current].neighbors[i]);
					visitedPath[g.vertices[current].neighbors[i]].visited = true;
					for (int j = 0; j < visitedPath[current].path.size(); j++)
						visitedPath[g.vertices[current].neighbors[i]].path.push_back(visitedPath[current].path[j]);
				}
			}

		}
		if (current == dst) {
			for (int i = 0; i < visitedPath[current].path.size() - 1; i++)
				cout << visitedPath[current].path[i] << "-";
			cout << visitedPath[current].path[visitedPath[current].path.size() - 1]<<endl;
		}
		else {
			cout << "Error: There is no path from "<<src<<" to "<<dst<<endl;
		}
}
