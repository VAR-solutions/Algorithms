package Dynamic Programming.floyd-warshall;

import java.util.*; 
import java.lang.*; 
import java.io.*; 

public class FloydWarshall {
    //initialising infinity and V as the vertices
    final static int INF = 99999, V = 4; 
  
    void floydWarshall(int graph[][]) 
    { 
        int dist[][] = new int[V][V]; 
        int i, j, k; 
        
        //the distances graph is also initialised equal to the input graph 
        for (i = 0; i < V; i++) 
            for (j = 0; j < V; j++) 
                dist[i][j] = graph[i][j]; 
  
        for (k = 0; k < V; k++) 
        { 
            for (i = 0; i < V; i++) 
            { 
                for (j = 0; j < V; j++) 
                { 
                    if (dist[i][k] + dist[k][j] < dist[i][j]) 
                        dist[i][j] = dist[i][k] + dist[k][j]; 
                } 
            } 
        } 
        printSolution(dist); 
    } 
  
    void printSolution(int dist[][]) 
    { 
        System.out.println("The following matrix shows the shortest "+ 
                         "distances between every pair of vertices"); 
        for (int i=0; i<V; ++i) 
        { 
            for (int j=0; j<V; ++j) 
            { 
                if (dist[i][j]==INF) 
                    System.out.print("INF "); 
                else
                    System.out.print(dist[i][j]+"   "); 
            } 
            System.out.println(); 
        } 
    } 
  

    public static void main (String[] args) 
    { 

        int graph[][] = { {0,   8,  INF, 12}, 
                          {INF, 0,   1, INF}, 
                          {INF, INF, 0,   8}, 
                          {INF, INF, INF, 0} 
                        }; 
        FloydWarshall f = new FloydWarshall(); 

        f.floydWarshall(graph); 
    } 
}
