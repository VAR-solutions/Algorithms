/*

Jarvis March Algorithm also known as Gift Wrapping algorithm is a famous algorithm to find Convex Hull of given set of points
Ref: https://en.wikipedia.org/wiki/Gift_wrapping_algorithm
Video Tutorial: https://www.youtube.com/watch?v=Vu84lmMzP2o

Time Complexity:  O(n^2) n being number of points.

*/

#include<bits/stdc++.h>

using namespace std;

class ConvexHull {
public:
	vector< pair<int, int> > findConvexHull(vector< pair<int, int> >);
	int crossProduct(pair<int, int>, pair<int, int>, pair<int, int>);
	int distance(pair<int, int>, pair<int, int>, pair<int, int>);
};

int ConvexHull :: distance(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int y1 = a.second - b.second;
	int y2 = a.second - c.second;
	int x1 = a.first - b.first;
	int x2 = a.first - c.first;
	int distance1 = (y1 * y1 + x1 * x1);
	int distance2 = (y2 * y2 + x2 * x2);
	if(distance1 < distance2) {
		return -1;
	} else if(distance1 == distance2) {
		return 0;
	}
	return 1;
}

int ConvexHull :: crossProduct(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int y1 = a.second - b.second;
	int y2 = a.second - c.second;
	int x1 = a.first - b.first;
	int x2 = a.first - c.first;
	return ((y2 * x1) - (y1 * x2));
}

vector< pair<int, int> > ConvexHull :: findConvexHull(vector< pair<int, int> > points) {
	set< pair<int, int> > result;
	if(points.size() == 0) {
		return vector< pair<int, int> >();
	}
	pair<int, int> start = points[0];
	// find the leftmost point
	for(int i = 1; i < points.size(); i++) {
		if(points[i].first < start.first) {
			start = points[i];
		}
	}
	pair<int, int> current = start;
	result.insert(start);
	vector< pair<int, int> > collinearPoints;
	while(true) {
		pair<int, int> nextTarget = points[0];
		for(int i = 1; i < points.size(); i++) {
			if(points[i] == current) {
				continue;
			}
			int val = crossProduct(current, nextTarget, points[i]);
			if(val > 0) {
				nextTarget = points[i];
				collinearPoints.clear();
			} 
			else if(val == 0) {
				if(distance(current, nextTarget, points[i]) < 0) {
					collinearPoints.push_back(nextTarget);
					nextTarget = points[i];
				} else {
					collinearPoints.push_back(points[i]);
				}
			}
		}
		for(int i = 0; i < collinearPoints.size(); i++) {
			result.insert(collinearPoints[i]);
		}
		if(nextTarget == start) {
			break;
		}
		result.insert(nextTarget);
		current = nextTarget;
	}
	vector< pair<int, int> > convexHullPoints;
	for(auto point : result) {
		convexHullPoints.push_back(point);
	}
	return convexHullPoints;
}


int main()
{
	ConvexHull *C = new ConvexHull();
	vector< pair<int, int> > points;
	points.push_back(make_pair(1, 1));
	points.push_back(make_pair(2, 2));
	points.push_back(make_pair(2, 0));
	points.push_back(make_pair(2, 4));
	points.push_back(make_pair(3, 3));
	points.push_back(make_pair(4, 2));
	vector< pair<int, int> > result = C -> findConvexHull(points);
	for(auto pt : result) {
		cout << pt.first << ' ' << pt.second << '\n';
	}
	return 0;
}
