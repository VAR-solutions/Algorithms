import java.util.*;
import java.io.*;

public class ConnectedG {
	
	public static TreeSet<Integer> adj[];
	public static int[] parent;
	public static int[] distance;
	public static boolean[] visited;
	
	public static void main(String[] main){
		
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the number of vertex: ");
		int ver = in.nextInt();
		System.out.println("Enter the number of edges: ");
		int edge = in.nextInt();
		
		adj = new TreeSet[ver+1];
		parent = new int[ver+1];
		distance = new int[ver+1];
		visited = new boolean[ver+1];
		
		for(int i=0;i<=ver;i++)
			adj[i] = new TreeSet<Integer>();
		System.out.println("Enter the graph: ");
		for(int i=0;i<edge;i++)
		{
			int u = in.nextInt();
			int v = in.nextInt();
			
			adj[u].add(v);
			adj[v].add(u);
		}
		BFS(1);
		if(conected())
			System.out.println("Graph is conected");
		else
			System.out.println("Graph is not conected");
		
	}
	
	public static void BFS(int s)
	{
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(s);
		parent[s]=0;
		distance[s]=0;
		visited[s]=true;
		
		while(!q.isEmpty())
		{
			int u = q.poll();
			for(int v : adj[u])
			{
				if(!visited[v])
				{
					parent[v]=u;
					distance[v]=distance[u]+1;
					visited[v]=true;
					q.add(v);
				}
			}
			
		}
	}
	public static boolean conected()
	{
		for(int i=1;i<visited.length;i++)
		{
			if(!visited[i])
				return false;
		}
		return true;
	}

}
