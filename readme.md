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
		uint16_t start;
		uint16_t end;
	};
```

Then apply an `ofxTSP::Solver` using the function:


```c++
vector<int> solve(const Problem & problem)
```

The returned `vector<int>` has ordered elements which define the route

Currently the only available solver is `ofxTSP::BruteForce` as i've got a pretty simple problem here. Others will come later as necessary.