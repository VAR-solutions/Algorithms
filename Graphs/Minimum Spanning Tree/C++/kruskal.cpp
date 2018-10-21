#include <limits>
#include "data-structures/LinkedGraph.hpp"

LinkedGraph* findMstKruskal(LinkedGraph& graph) {
	ArrayList<LinkedList<LinkedGraphEdge*>*>* nodes = graph.nodes;
	
	LinkedGraph* result = new LinkedGraph(nodes->getSize());
	int treeId[nodes->getSize()];
	for (int i = 0; i < nodes->getSize(); i++) {
		treeId[i] = i;
	}
	int trees = nodes->getSize();
	LinkedList<LinkedGraphEdge*> remainingEdges = LinkedList<LinkedGraphEdge*>();
	for (int i = 0; i < nodes->getSize(); i++) {
		for (int k = 0; k < nodes->get(i)->getSize(); k++) {
			if (!remainingEdges.contains(nodes->get(i)->get(k))) {
				remainingEdges.add(nodes->get(i)->get(k));
			}
		}
	}
	
	while (trees > 1 && remainingEdges.getSize() > 0) {
		int lowestMetric = std::numeric_limits<int>::max();
		LinkedGraphEdge* lowestMetricEdge = nullptr;
		
		for (int i = 0; i < remainingEdges.getSize(); i++) {
			LinkedGraphEdge* edge = remainingEdges.get(i);
			if (edge->metric < lowestMetric) {
				lowestMetric = edge->metric;
				lowestMetricEdge = edge;
			}
		}
		
		if (lowestMetricEdge != nullptr) {
			remainingEdges.remove(lowestMetricEdge);
			if (treeId[lowestMetricEdge->originNode] != treeId[lowestMetricEdge->destinationNode]) {
				result->addEdge(lowestMetricEdge->originNode, lowestMetricEdge->destinationNode, lowestMetricEdge->metric);
				int mergedTreeId = treeId[lowestMetricEdge->destinationNode];
				for (int i = 0; i < nodes->getSize(); i++) {
					if (treeId[i] == mergedTreeId) {
						treeId[i] = treeId[lowestMetricEdge->originNode];
					}
				}
				--trees;
			}
		}
	}
	return result;
}
