# Introduction

The Travelling Salesman Problem is a computational problem of finding the 'shortest route' between a set of nodes

# Usage

Define your problem with the class `ofxTSP::Problem` :


```
	struct Problem {
		int destinationCount;
		map<Journey, float> distance;
	};
```

wherein an `ofxTSP::Journey` is defined as:


```c++
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
```

Then apply an `ofxTSP::Solver` which returns a `vector<int>` whose ordered elements define the route

Currently the only available solver is `ofxTSP::BruteForce` as i've got a pretty simple problem here. Others will come later as necessary.