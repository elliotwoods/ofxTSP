#pragma once
#include "ofxTSP/Solver.h"

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
		vector<int> solve(const Problem & problem);
		float getCost() { return this->bestCost; }
	protected:
		void step(const Problem & problem, vector<int> visited, float runningCost);
		int start, end;
		vector<int> bestSolution;
		float bestCost;
	};
};