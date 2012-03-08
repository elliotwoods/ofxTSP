#include "ofxTSP/BruteForce.h"
namespace ofxTSP {
	//---------
	vector<int> BruteForce::solve(const Problem & problem) {
		this->solutions.clear();
		vector<int> visited;
		step(problem, visited, 0);
		ofLogNotice("ofxTSP::BruteForce") << "Found " << solutions.size() << " possible routes (assymetric).";

		float best = std::numeric_limits<float>::infinity();
		
		map<vector<int>, float>::const_iterator it;
		map<vector<int>, float>::const_iterator solution;
		for (it = solutions.begin(); it != solutions.end(); it++) {
			if (it->second < best) {
				solution = it;
				best = solution->second;
			}
		}
		return solution->first;
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
		if (visited.size() == problem.nodeCount) {
			//we've visited all destinations, add to possible solutions
			solutions.insert(pair<vector<int>, float>(visited, runningCost));
			return;
		}

		for (int i=0; i<problem.nodeCount; i++) {
			if (!hasVisited(i, visited)) {

				vector<int> visitBranch = visited;
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