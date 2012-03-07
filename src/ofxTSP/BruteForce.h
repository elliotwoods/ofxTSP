#pragma once
#include "ofxTSP/Solver.h"

#include <map>
#include <vector>
#include <set>

using namespace std;

namespace ofxTSP {
	class BruteForce : public Solver {
	public:
		vector<int> solve(const Problem & problem);
	protected:
		void step(const Problem & problem, vector<int> visited, float distance);
		map<vector<int> , float> solutions;
	};
}