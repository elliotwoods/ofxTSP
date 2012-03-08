#include "RouteFind.h"

namespace ofxTSP {
	RouteFind::RouteFind(int start, int end) {
		this->start = start;
		this->end = end;
	}

	vector<int> RouteFind::solve(const Problem & problem) {
		for (int i=0; i<problem.nodeCount; i++) {

		}
		return vector<int>();
	}
}