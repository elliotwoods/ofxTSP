#pragma once
#include "ofxTSP/Journey.h"

#include <vector>
#include <map>
#include <stdint.h>

using namespace std;

namespace ofxTSP {
	/** A travelling salesman problem is defined
	by a start index, and the distance between inidices
	**/
	struct Problem {
		int destinationCount;
		map<Journey, float> distance;
	};
}