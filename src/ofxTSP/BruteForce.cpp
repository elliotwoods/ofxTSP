#include "ofxTSP/BruteForce.h"
namespace ofxTSP {
	//---------
	vector<int> BruteForce::solve(const Problem & problem) {
		this->solutions.clear();
		vector<int> visited;
		this->bestCost = std::numeric_limits<float>::infinity();
		step(problem, visited, 0);
		ofLogNotice("ofxTSP::BruteForce") << "Traversed " << solutions.size() << " possible routes (assymetric).";

		return this->bestSolution;
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
	void BruteForce::step(const Problem & problem, vector<int> visited, float runningCost) {
		//check whether we're already losing. If so don't continue to step down this branch
		if (runningCost > bestCost)
			return;

		if (visited.size() == problem.nodeCount) {
			//we've visited all destinations
			//if we're better let's add this solution
			if(runningCost < bestCost) {
				bestSolution = visited;
				bestCost = runningCost;
			}
			return;
		}

		for (int i=0; i<problem.nodeCount; i++) {
			if (!hasVisited(i, visited)) {

				vector<int> visitBranch(visited);
				visitBranch.push_back(i);

				if (visitBranch.size() == 1) {
					//this is our start location
					step(problem, visitBranch, 0);
				} else {
					float cost = problem.getSymmetricCost(Journey(visited.back(), i));
					if (cost != -1) {
						step(problem, visitBranch, cost + runningCost);
					} else {
						//no journey found
						continue;
					}
				}
			}
		}
	}

}