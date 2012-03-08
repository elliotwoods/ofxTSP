#pragma once
#include "ofxTSP/Solver.h"
#include "ofUtils.h"

#include <map>
#include <vector>
#include <set>

using namespace std;

namespace ofxTSP {
	/** Solve in a shitty but exact way.
	Presume all routes are symmetric (same cost in both directions)
	**/
	class BruteForce : public Solver {
	public:
		vector<int> solve(const Problem & problem);
	protected:
		void step(const Problem & problem, vector<int> visited, float runningCost);
		map<vector<int> , float> solutions;
	};
}