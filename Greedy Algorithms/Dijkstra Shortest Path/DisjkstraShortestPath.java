package com.carfax.ucl.services.seo;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.IntStream;

public class DijkstraShortestPath {
    private int distances[];
    private Set<Integer> visited, notVisited;
    private int nodes;
    private int adjacencyMatrix[][];

    public DijkstraShortestPath(int nodes) {
        this.nodes = nodes;
        distances = new int[nodes + 1];
        visited = new HashSet<>();
        notVisited = new HashSet<>();
        adjacencyMatrix = new int[nodes + 1][nodes + 1];
    }

    public void dijkstra_algorithm(int adjacencyMatrix[][], int source) {
        for (int i = 1; i <= nodes; i++)
            for (int j = 1; j <= nodes; j++)
                this.adjacencyMatrix[i][j] = adjacencyMatrix[i][j];

        IntStream.rangeClosed(1, nodes).forEach(i -> distances[i] = Integer.MAX_VALUE);

        notVisited.add(source);
        distances[source] = 0;
        while (!notVisited.isEmpty()) {
            int evaluationNode = getNodeWithMinimumDistanceFromUnsettled();
            notVisited.remove(evaluationNode);
            visited.add(evaluationNode);
            evaluateNeighbours(evaluationNode);
        }
    }

    private int getNodeWithMinimumDistanceFromUnsettled() {
        int node = notVisited.iterator().next();
        int min = distances[node];
        for (int i = 1; i <= distances.length; i++) {
            if (notVisited.contains(i) && distances[i] <= min) {
                min = distances[i];
                node = i;
            }
        }
        return node;
    }

    private void evaluateNeighbours(int evaluationNode) {
        int edgeDistance;
        int newDistance;

        for (int destinationNode = 1; destinationNode <= nodes; destinationNode++) {
            if (!visited.contains(destinationNode) && adjacencyMatrix[evaluationNode][destinationNode] != Integer.MAX_VALUE) {
                edgeDistance = adjacencyMatrix[evaluationNode][destinationNode];
                newDistance = distances[evaluationNode] + edgeDistance;
                if (newDistance < distances[destinationNode]) {
                    distances[destinationNode] = newDistance;
                }
                notVisited.add(destinationNode);
            }
        }
    }

    public static void main(String... arg) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of vertices");
        int numberOfVertices = scanner.nextInt();
        int adjacencyMatrix[][] = new int[numberOfVertices + 1][numberOfVertices + 1];

        System.out.println("Enter the Weighted Matrix for the graph");
        for (int i = 1; i <= numberOfVertices; i++) {
            for (int j = 1; j <= numberOfVertices; j++) {
                adjacencyMatrix[i][j] = scanner.nextInt();
                if (i == j) {
                    adjacencyMatrix[i][j] = 0;
                    continue;
                }
                if (adjacencyMatrix[i][j] == 0) {
                    adjacencyMatrix[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        System.out.println("Enter the source ");
        int source = scanner.nextInt();
        scanner.close();

        DijkstraShortestPath dijkstraShortestPath = new DijkstraShortestPath(numberOfVertices);
        dijkstraShortestPath.dijkstra_algorithm(adjacencyMatrix, source);

        System.out.println("The Shorted Path to all nodes are ");
        for (int i = 1; i <= dijkstraShortestPath.distances.length - 1; i++) {
            System.out.println(source + " to " + i + " is " + dijkstraShortestPath.distances[i]);
        }
    }
}
