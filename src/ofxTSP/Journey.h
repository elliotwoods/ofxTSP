#pragma once

#include <vector>
#include <stdint.h>

namespace ofxTSP {
	struct Journey {
		Journey() {	}
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
			return (uint32_t)start << 16 + (uint32_t)end;
		}
	};
}