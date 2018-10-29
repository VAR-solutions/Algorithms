package util;

import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Stack;

/**
 * Class that represents the graph
 * @author Brendo Nascimento and Gabriel Azevedo
 *
 */
public class Grafo {
	
	private HashMap<String, HashMap<String, Double>> graph;
	
	/**
	 * Constructor
	 */
	public Grafo(){
		graph = new HashMap<>();
	}
	
	
	/**
	 * Method that check if it is a node
	 * @param v Name of the node
	 * @return Returns true if it is a node, otherwise returns false
	 */
	public boolean isVertex(String v) {
		return graph.containsKey(v);
	}	
		
	/**
	 * Method that adds a node if it doesn't already exists
	 * @param v Name of the node
	 * @return Returns the name of the node
	 */
	public String addVertex(String v) {
		if(!isVertex(v)){
			graph.put(v, new HashMap<String, Double>());
		    return v;
		}
		return null;
	}	
			
	/**
	 * Method that removes a node and its connections if it exists
	 * @param v Name of the node
	 */
	public void removeVertex(String v) {
		if(isVertex(v)) {
			for(String a : graph.get(v).keySet())
			graph.get(a).remove(v);	
			graph.remove(v);
		}
	}
		
	/**
	 * Method that returns how many nodes are in the graph
	 * @return The size of the graph (number of nodes)
	 */
	public int numVertex() {
		return graph.size();
	}
		
	/**
	 * Method that returns the Node iterator
	 * @return The iterator with the name of every station (node) in the graph
	 */
	public Iterable<String> getVertex() {
			return graph.keySet();
	}
		
	/**
	 * Method that verifies if there is a path between nodes
	 * @param v Name of the initial node (Departure station)
	 * @param u Name of the final node (Arrival station)
	 * @return True if there is a path, false if not
	 */
	public boolean isEdge(String v, String u) {
		return graph.containsKey(v) && graph.get(v).containsKey(u);
	}
		
	/**
	 * Method that creates a path if it doesn't already exists
	 * @param v Name of the initial node (Departure station)
	 * @param u Name of the final node (Arrival station)
	 * @param t Time between stations (Path value)
	 */
	public void addEdge(String v, String u, Double t) {
		if(!isEdge(v, u) && t > 0) {			
			graph.get(v).put(u, t);
			graph.get(u).put(v, t);
		}
	}	
			
	/**
	 * Method that returns a path if it exists
	 * @param v Name of the initial node (Departure station)
	 * @param u Name of the final node (Arrival station)
	 * @return The path value if it exists, otherwise, it will return -1
	 */
	public double getEdge(String v, String u) {
		return isEdge(v, u) ? graph.get(u).get(v) : -1;
	}
		
	/**
	 * Method that removes a path if it exists
	 * @param u Name of the initial node (Departure station)
	 * @param v Name of the final node (Arrival station)
	 */
	public void removeEdge(String u, String v) {
		if(isEdge(v, u)) {
			graph.get(v).remove(u);
			graph.get(u).remove(v);
		}
	}
		
	/**
	 * Method that return the number of paths adjacent to the node
	 * @param v Name of the node
	 * @return The number of paths connected to the node, or -1 if there is none
	 */
	public int numEdge(String v) {
		return isVertex(v) ? graph.get(v).size() : -1;
	}
		
	/**
	 * Method that returns the iterator of adjacent nodes, or null if there is none
	 * @param v Name of the node
	 * @return An iterator with all nodes connected to the current node
	 */
	public Iterable<String> getAdjacent(String v) {
		return isVertex(v) ? graph.get(v).keySet() : null;
	}
		
	/**
	 * Dijikstra Algorithm: Define paths from one node to the other, including the minimum
	 * @param v Name of the initial node (Departure station)
	 * @param u Name of the final node (Arrival station)
	 * @return A HashMap with minimum paths
	 */
	public Stack<Path> dijkstra(String v, String u) {
			//Verify if nodes exists
			if(isVertex(v) && isVertex(u)) {
				//Stores the visited nodes and its informations
				HashMap<String, Path> visited = new HashMap<>();
				
				//Store the unvisited nodes
				PriorityQueue<Path> next = new PriorityQueue<>();
				next.add(new Path(v, null, 0));
				
				//Verify if there are next nodes and if the destiny hasn't been reached
				while(!next.isEmpty() && !visited.containsKey(u)) {
					//Get infos and the next node name
					Path info = next.remove();
					String rem = info.getVertex();
					
					//Verify if the next node hasn't been visited
					if(!visited.containsKey(rem)) {
						visited.put(rem, info);
						
						//Verify its adjacent nodes					
						for(String cur : getAdjacent(rem)) {												
							//Update the distance of adjacent unvisited nodes
							if(!visited.containsKey(cur)) {
								double time = getEdge(rem, cur);
								time += info.getTime();
								next.add(new Path(cur, rem, time));
							}
						}
					}
				}
							
				//If the destiny has been reached it returns the path, otherwise returns null
				return visited.containsKey(u) ? getPath(visited, v, u) : null;
			}			
			
			return null;
	}
		
	/**
	 * Method that converts visited nodes into a path stack
	 * @param visited HashMap with visited nodes in the minimum path algorithm
	 * @param v Name of the initial node (Departure station)
	 * @param u Name of the final node (Arrival station)
	 * @return A stack with visited nodes
	 */
	private Stack<Path> getPath(HashMap<String, Path> visited, String v, String u) {
			Stack<Path> path = new Stack<>();
					
			while(v != u) {		
				path.push(visited.get(u));
				u = visited.get(u).getPrevious();			
			}
			
			path.push(visited.get(v));				
			return path;
	}	
	
}
