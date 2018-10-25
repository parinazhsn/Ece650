
#include "Main.h"
#include "Graph.h"
#include "VisitedPath.h"
#include "ShortestPath.h"

#include "Edge.h"


Main::Main()
{
}


Main::~Main()
{
}

vector<Edge> Main::parseEdges(string edgesString)
{
	vector<string> result=split(edgesString, "{<");
	result = split(result[1], ">}");
	result = split(result[0], ">,<");
	vector<Edge> edges;
	for (int i = 0; i < result.size(); i++) {
		vector<string> edgeVector = split(result[i], ",");
		int src = stoi(edgeVector[0]);
		int dst = stoi(edgeVector[1]);
		Edge edge;
		edge.source = src;
		edge.destination = dst;
		edges.push_back(edge);	
	}		
	return edges;
}

vector<string> Main::split(string str, string delim)
{
	vector<string> result;

	auto start = 0U;
	auto end = str.find(delim);
	while (end != string::npos)
	{
		result.push_back(str.substr(start, end - start));
		start = end + delim.length();
		end = str.find(delim, start);
	}

	result.push_back(str.substr(start, end));
	return result;
}

int main()
{
	Main main;

	string edgeString = "{<0,2>,<2,1>,<2,3>,<3,4>,<4,1>}";
	//string edgeString = "{<2,6>,<2,8>,<2,5>,<6,5>,<5,8>,<6,10>,<10,8>}";

	Graph g;

	for (int i = 0; i < 15; i++) {
		Vertex v;
		v.vertex = i;
		g.vertices.push_back(v);
	}

	vector<Edge> edges = main.parseEdges(edgeString);
	for (int i = 0; i < edges.size(); i++) {
		Edge edge = edges[i];
		g.vertices[edge.source].neighbors.push_back(edge.destination);
		g.vertices[edge.destination].neighbors.push_back(edge.source);
	}
	
	ShortestPath sp;

	sp.findShortestPath(g, 4,0);
	//sp.findShortestPath(g, 2, 10);

}
