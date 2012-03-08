#include "RouteFind.h"

namespace ofxTSP {
	//---------
	RouteFind::RouteFind(int start, int end) {
		this->start = start;
		this->end = end;
	}

	//---------
	Route RouteFind::solve(const Problem & problem) {
		this->bestSolution.cost = std::numeric_limits<float>::infinity();
		this->step(problem, vector<int>(1, this->start));
		return bestSolution;
	}

	//---------
	bool hasVisited(int i, const vector<int> & visited) {
		vector<int>::const_iterator it;
		for (it = visited.begin(); it != visited.end(); it++) {
			if (*it == i)
				return true;
		}
		return false;
	}

	//---------
	void RouteFind::step(const Problem & problem, Route visited) {
		if (visited.cost > this->bestSolution.cost)
			return;

		if (visited.back() == this->end) {
			if (visited.cost < this->bestSolution.cost) {
				this->bestSolution = visited;
			}
			return;
		}

		for (int i=0; i<problem.nodeCount; i++) {
			if (!hasVisited(i, visited)) {
				float cost = problem.getSymmetricCost(Journey(visited.back(), i));
				if (cost == -1)
					continue;
				else {
					Route visitBranch(visited);
					visitBranch.addStep(i, cost);
					step(problem, visitBranch);
				}
			}
		}
	}
}