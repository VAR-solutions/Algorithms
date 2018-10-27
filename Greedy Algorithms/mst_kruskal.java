import java.util.*;
import java.text.*;
import java.io.*;
import java.math.*;
import java.util.regex.*;

public class Solution 
{
    class Edge implements Comparable<Edge>
    {
        int sr;
        int des;
        int weigh;
        
        public int compareTo(Edge compareEdge)
        {
            return this.weigh-compareEdge.weigh;
        }
    }
    class Subset
    {
        int parent;
        int rank;
    }
    
    int V;
    int E;
    Edge edge[];
    
    Solution(int v, int e)
    {
        V=v;
        E=e;
        edge = new Edge[e];
        for(int i=0;i<e;i++)
        {
            edge[i] = new Edge();
        }
    }
    
    int find(Subset subsets[], int i)
    {
        if(subsets[i].parent != i)
        {
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }
    
    void union(Subset subsets[], int x,  int y)
    {
        int xroot = find(subsets,x);
        int yroot = find(subsets,y);
        
        if(subsets[xroot].rank < subsets[yroot].rank){
            subsets[xroot].parent = yroot;
        }else if(subsets[xroot].rank > subsets[yroot].rank){
            subsets[yroot].parent = xroot;
        }else{
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }    
            
    }
   
    void printSol(Edge result[])
    {
        int total =0;
        for(Edge a : result){
            total += a.weigh;
        }
        System.out.print(total);
    }
    
    void kruskal()
    {
        Edge result[] = new Edge[V];
        int e=0;
        int i=0;
        for(i=0;i<V;i++)
        {
            result[i] = new Edge();
        }
        Arrays.sort(edge);
        
        Subset subsets[] = new Subset[V];
        for(i=0;i<V;i++)
        {
            subsets[i] = new Subset();
            subsets[i].parent = i;
            subsets[i].rank = -1;
        }
        i=0;
        while(e<V-1)
        {
            Edge next = new Edge();
            next = edge[i++];
            
            int x = find(subsets,next.sr);
            int y = find(subsets, next.des);
            
            if(x!=y){
                result[e++] = next;
                union(subsets,x,y);
            }
        }
        printSol(result);
    }
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        int nodes_num = in.nextInt();
        int edges_num = in.nextInt();
        Solution graph = new Solution(nodes_num, edges_num);
        for(int i=0;i<edges_num;i++){
            graph.edge[i].sr = in.nextInt()-1;
            graph.edge[i].des = in.nextInt()-1;
            graph.edge[i].weigh = in.nextInt();
        }
        graph.kruskal();
    }
}
