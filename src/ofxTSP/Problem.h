#pragma once

#include <vector>
#include <stdint.h>

using namespace std;

namespace ofxTSP {
	struct Journey {
		Journey(uint16_t start, uint16_t end) {
			this->start = start;
			this->end = end;
		}
		uint16_t start;
		uint16_t end;
		bool operator<(const Journey & other) const {
			return this->asInt32() < other.asInt32();
		}
		uint32_t asInt32() const {
			return start << 16 + end;
		}
	};

	/** A travelling salesman problem is defined
	by a start index, and the distance between inidices
	**/
	struct Problem {
		int destinationCount;
		map<Journey, float> distance;
	};
}