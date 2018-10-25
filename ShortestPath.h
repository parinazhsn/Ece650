#pragma once
#include <iostream>
#include <vector>
#include "Graph.h"
#include "VisitedPath.h"


using namespace std;

class ShortestPath
{
public:
	ShortestPath();
	~ShortestPath();

	void findShortestPath(Graph g, int src, int dst);
};

