#include <iostream>
#include <random>
#include <chrono>
#include "data-structures/LinkedGraph.hpp"
#include "prim.hpp"
#include "kruskal.hpp"
#include "nanoseconds.hpp"
#include "mst.hpp"

int main(int argc, char** argv) {
	LinkedGraph graph = LinkedGraph();
	promptGraphGenerationParams(graph);
	std::cout << "\n";
	std::cout << "Generated graph:\n";
	printGraph(graph);
	std::cout << "Minimum spanning tree, DJP algorithm:\n";
	runPrim(graph);
	std::cout << "Minimum spanning tree, Kruskal's algorithm:\n";
	runKruskal(graph);
	return 0;
}

void promptGraphGenerationParams(LinkedGraph& graph) {
	std::cout << "Enter number of nodes: ";
	int nodeCount = 0;
	std::scanf("%d", &nodeCount);
	
	if (nodeCount <= 0) {
		std::cout << "Size of 0 chosen, structure unaltered.\n";
		return;
	}
	
	std::cout << "Enter density [%]: ";
	int densityPercentage = 0;
	std::scanf("%d", &densityPercentage);
	
	if (densityPercentage < 0 || densityPercentage > 100) {
		std::cerr << "Invalid percentage\n";
		return;
	}
	
	generateRandomGraph(graph, nodeCount, densityPercentage);
}

void generateRandomGraph(LinkedGraph& graph, int nodeCount, int densityPercentage) {
	if (nodeCount > 0 && densityPercentage >= 0 && densityPercentage <= 100) {
		graph.clear();
		graph.addNodes(nodeCount);
		
		std::random_device randomDevice;
		std::mt19937 mt = std::mt19937(randomDevice());
		std::uniform_int_distribution<int> nodeDist = std::uniform_int_distribution<int>(0, nodeCount - 1);
		std::bernoulli_distribution directionDist = std::bernoulli_distribution();
		std::uniform_int_distribution<int> metricDist = std::uniform_int_distribution<int>(1, MAX_RANDOM_METRIC);
		/*
		 * This part guarantees that we generate a connected graph
		 */
		bool nodeIncluded[nodeCount] = {}; // { false, ... }
		nodeIncluded[nodeDist(mt)] = true;
		
		for (int i = 1; i < nodeCount; i++) {
			int node = nodeDist(mt);
			while (nodeIncluded[node]) {
				node = nodeDist(mt);
			}
			int connectionNode = nodeDist(mt);
			while (!nodeIncluded[connectionNode]) {
				connectionNode = nodeDist(mt);
			}
			nodeIncluded[node] = true;
			if (directionDist(mt)) {
				std::swap(node, connectionNode);
			}
			int metric = metricDist(mt);
			graph.addEdge(node, connectionNode, metric);
		}
		/***/
		
		double initialDensity = ((double)nodeCount - 1.0) / (((double)nodeCount - 1.0) * (double)nodeCount);
		double probability = (((double) densityPercentage / 100.0) - initialDensity) / (1.0 - initialDensity);
		if (densityPercentage > 0) {
			std::bernoulli_distribution boolDist = std::bernoulli_distribution(probability);
			
			for (int i = 0; i < nodeCount; i++) {
				for (int k = 0; k < nodeCount; k++) {
					if (k != i
							&& !graph.containsEdge(i, k)
							&& boolDist(mt)) {
						int metric = metricDist(mt);
						graph.addEdge(i, k, metric);
					}
				}
			}
		}
	}
}

void printGraph(LinkedGraph& graph) {
	std::cout << graph.toString() << "\n";
}

void runPrim(LinkedGraph& graph) {
	std::chrono::time_point<std::chrono::high_resolution_clock> timeBefore;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeAfter;
	
	timeBefore = std::chrono::high_resolution_clock::now();
	
	LinkedGraph* mst = findMstPrim(graph);
	
	timeAfter = std::chrono::high_resolution_clock::now();
	
	std::cout << mst->toString();
	std::cout << "Total edge metric: " << mst->totalEdgeMetric() << "\n";
	delete mst;
	
	std::cout << "Computation took " << nanoseconds(timeBefore, timeAfter) << " ns\n\n";
}

void runKruskal(LinkedGraph& graph) {
	std::chrono::time_point<std::chrono::high_resolution_clock> timeBefore;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeAfter;
	
	timeBefore = std::chrono::high_resolution_clock::now();
	
	LinkedGraph* mst = findMstKruskal(graph);
	
	timeAfter = std::chrono::high_resolution_clock::now();
	
	std::cout << mst->toString();
	std::cout << "Total edge metric: " << mst->totalEdgeMetric() << "\n";
	delete mst;
	
	std::cout << "Computation took " << nanoseconds(timeBefore, timeAfter) << " ns\n\n";
}
