#pragma once
#include "ofxTSP/Problem.h"
#include <vector>

using namespace std;

namespace ofxTSP {
	/** A solver solves a ofxTSP::Problem
	**/
	class Solver {
	public:
		virtual vector<int> solve(const Problem & problem) = 0;
	};
}