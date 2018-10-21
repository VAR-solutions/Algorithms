#include <limits>
#include "data-structures/LinkedGraph.hpp"

LinkedGraph* findMstPrim(LinkedGraph& graph) {
	ArrayList<LinkedList<LinkedGraphEdge*>*>* nodes = graph.nodes;
	
	LinkedGraph* result = new LinkedGraph(nodes->getSize());
	bool nodeIncluded[nodes->getSize()] = {}; // { false ... }
	
	int cheapestConnectionMetric[nodes->getSize()];
	std::fill_n(cheapestConnectionMetric, nodes->getSize(), std::numeric_limits<int>::max());
	LinkedGraphEdge* cheapestConnectionEdge[nodes->getSize()];
	std::fill_n(cheapestConnectionEdge, nodes->getSize(), nullptr);
	
	int currentNode = 0;
	for (int nodesRemaining = nodes->getSize(); nodesRemaining > 0 && currentNode != -1; nodesRemaining--) {
		nodeIncluded[currentNode] = true;
		if (cheapestConnectionEdge[currentNode] != nullptr) {
			LinkedGraphEdge* edge = cheapestConnectionEdge[currentNode];
			result->addEdge(edge->originNode, edge->destinationNode, edge->metric);
		}
		
		for (int i = 0; i < nodes->get(currentNode)->getSize(); i++) {
			LinkedGraphEdge* edge = nodes->get(currentNode)->get(i);
			if (edge->originNode == currentNode
					&& !nodeIncluded[edge->destinationNode]
					&& edge->metric < cheapestConnectionMetric[edge->destinationNode]) {
				cheapestConnectionMetric[edge->destinationNode] = edge->metric;
				cheapestConnectionEdge[edge->destinationNode] = edge;
			}
			else if (edge->destinationNode == currentNode
					&& !nodeIncluded[edge->originNode]
					&& edge->metric < cheapestConnectionMetric[edge->originNode]) {
				cheapestConnectionMetric[edge->originNode] = edge->metric;
				cheapestConnectionEdge[edge->originNode] = edge;
			}
		}
		
		int lowestMetric = std::numeric_limits<int>::max();
		int lowestMetricNode = -1;
		for (int i = 0; i < nodes->getSize(); i++) {
			if (!nodeIncluded[i] && cheapestConnectionMetric[i] < lowestMetric) {
				lowestMetric = cheapestConnectionMetric[i];
				lowestMetricNode = i;
			}
		}
		currentNode = lowestMetricNode;
	}
	return result;
}
