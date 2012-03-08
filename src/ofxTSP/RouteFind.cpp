#include "RouteFind.h"

namespace ofxTSP {
	//---------
	RouteFind::RouteFind(int start, int end) {
		this->start = start;
		this->end = end;
	}

	//---------
	vector<int> RouteFind::solve(const Problem & problem) {
		this->bestCost = std::numeric_limits<float>::infinity();
		this->step(problem, vector<int>(1, this->start), 0);
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
	void RouteFind::step(const Problem & problem, vector<int> visited, float runningCost) {
		if (runningCost > bestCost)
			return;

		if (visited.back() == this->end) {
			if (runningCost < this->bestCost) {
				this->bestSolution = visited;
				this->bestCost = runningCost;
			}
			return;
		}

		for (int i=0; i<problem.nodeCount; i++) {
			if (!hasVisited(i, visited)) {
				float cost = problem.getSymmetricCost(Journey(visited.back(), i));
				if (cost == -1)
					continue;
				else {
					vector<int> visitBranch(visited);
					visitBranch.push_back(i);
					step(problem, visitBranch, runningCost + cost);
				}
			}
		}
	}
}