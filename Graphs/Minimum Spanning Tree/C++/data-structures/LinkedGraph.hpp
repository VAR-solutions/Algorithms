#ifndef MST_LINKEDGRAPH_HPP_
#define MST_LINKEDGRAPH_HPP_

#include <string>
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "LinkedGraphEdge.hpp"

class LinkedGraph {
	
public:
	ArrayList<LinkedList<LinkedGraphEdge*>*>* nodes = new ArrayList<LinkedList<LinkedGraphEdge*>*>();
	
	LinkedGraph() = default;
	LinkedGraph(int nodeCount);
	~LinkedGraph() = default;
	
	void addNodes(int count);
	void addEdge(int origin, int destination, int metric);
	void clear();
	std::string toString();
	int totalEdgeMetric();
	bool containsEdge(int from, int to);
	
};

#endif //MST_LINKEDGRAPH_HPP_
