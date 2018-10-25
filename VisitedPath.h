#pragma once
#include <vector>

class VisitedPath
{
public:

	bool visited;
	std::vector<int> path;

	VisitedPath();
	~VisitedPath();
};

