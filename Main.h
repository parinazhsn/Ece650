#pragma once


#include <vector>
#include "Graph.h"
#include "VisitedPath.h"
#include "ShortestPath.h"
#include <string>
#include "Edge.h"

using namespace std;

class Main
{
private:
	vector<string> split(string str, string delim);

public:
	vector<Edge> parseEdges(string edges);

	Main();
	~Main();
};

