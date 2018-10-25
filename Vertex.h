 #pragma once
#include <vector>

class Vertex
{
public:

	int vertex;
	std::vector<int> neighbors;

	Vertex();
	~Vertex();
};

