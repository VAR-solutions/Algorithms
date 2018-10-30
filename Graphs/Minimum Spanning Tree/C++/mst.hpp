#ifndef MST_HPP_
#define MST_HPP_

#include "data-structures/LinkedGraph.hpp"

#define MAX_RANDOM_METRIC 1<<10

void promptGraphGenerationParams(LinkedGraph& graph);
void generateRandomGraph(LinkedGraph& graph, int nodeCount, int densityPercentage);
void printGraph(LinkedGraph& graph);
void runPrim(LinkedGraph& graph);
void runKruskal(LinkedGraph& graph);

#endif //MST_HPP_
