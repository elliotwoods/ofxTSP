#pragma once
#include "Solver.h"

namespace ofxTSP {
	//strictly NOT a TSP solver
	//but works on same data set

	/**
	RouteFind

	find the cheapest route between 2 nodes on the graph
	**/
	class RouteFind : public Solver {
	public:
		RouteFind(int start, int end);
		Route solve(const Problem & problem);
	protected:
		bool hasVisited(int i, const vector<int> & visited);
		int start, end;
		Route bestSolution;
		void step(const Problem & problem, Route visited);
	};
};
