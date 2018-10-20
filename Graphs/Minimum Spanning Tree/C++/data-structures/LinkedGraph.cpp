#include <sstream>
#include <limits>
#include "LinkedGraph.hpp"

LinkedGraph::LinkedGraph(int nodeCount) {
	addNodes(nodeCount);
}

void LinkedGraph::addNodes(int count) {
	for (int i = 0; i < count; i++) {
		nodes->add(new LinkedList<LinkedGraphEdge*>());
	}
}

void LinkedGraph::addEdge(int origin, int destination, int metric) {
	if (origin < nodes->getSize() && destination < nodes->getSize()
	    && origin >= 0 && destination >= 0 && metric > 0) {
		LinkedGraphEdge* edge = new LinkedGraphEdge(origin, destination, metric);
		nodes->get(origin)->add(edge);
		nodes->get(destination)->add(edge);
	}
}

void LinkedGraph::clear() {
	for (int i = 0; i < nodes->getSize(); i++) {
		delete nodes->get(i);
	}
	delete nodes;
	nodes = new ArrayList<LinkedList<LinkedGraphEdge*>*>();
}

std::string LinkedGraph::toString() {
	std::stringstream stringStream;
	for (int i = 0; i < nodes->getSize(); i++) {
		stringStream << std::to_string(i) << " : ";
		for (int k = 0; k < nodes->get(i)->getSize(); k++) {
			if (k > 0) {
				stringStream << ", ";
			}
			stringStream << "{";
			stringStream << std::to_string(nodes->get(i)->get(k)->originNode);
			stringStream << "->";
			stringStream << std::to_string(nodes->get(i)->get(k)->destinationNode);
			stringStream << ", ";
			stringStream << std::to_string(nodes->get(i)->get(k)->metric);
			stringStream << "}";
		}
		stringStream << "\n";
	}
	stringStream.flush();
	return stringStream.str();
}

int LinkedGraph::totalEdgeMetric() {
	int result = 0;
	for (int i = 0; i < nodes->getSize(); i++) {
		for (int k = 0; k < nodes->get(i)->getSize(); k++) {
			result += nodes->get(i)->get(k)->metric;
		}
	}
	result >>= 1;
	return result;
}

bool LinkedGraph::containsEdge(int from, int to) {
	if (from < nodes->getSize() && to < nodes->getSize()
			&& from >= 0 && to >= 0
			&& from != to) {
		LinkedList<LinkedGraphEdge*>* adjacencyList = nodes->get(from);
		for (int i = 0; i < adjacencyList->getSize(); i++) {
			if (adjacencyList->get(i)->originNode == to
					|| adjacencyList->get(i)->destinationNode == to) {
				return true;
			}
		}
	}
	return false;
}
