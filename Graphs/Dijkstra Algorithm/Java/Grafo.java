package util;

import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Stack;

/**
 * Classe que representa o grafo
 * @author Brendo Nascimento e Gabriel Azevedo
 *
 */
public class Grafo {
	
	private HashMap<String, HashMap<String, Double>> graph;
	
	/**
	 * Construtor
	 */
	public Grafo(){
		graph = new HashMap<>();
	}
	
	
	/**
	 * Método que verifica se é um vertice
	 * @param v Nome do vértice
	 * @return Uma resposta true caso o nome seja de um vértice, e false caso não
	 */
	public boolean isVertex(String v) {
		return graph.containsKey(v);
	}	
		
	/**
	 * Método que adiciona um vertice se ele nao existir
	 * @param v Nome do vértice
	 * @return O nome do vértice
	 */
	public String addVertex(String v) {
		if(!isVertex(v)){
			graph.put(v, new HashMap<String, Double>());
		    return v;
		}
		return null;
	}	
			
	/**
	 * Método que emove um vertice e suas arestas se ele existir
	 * @param v Nome do vétice
	 */
	public void removeVertex(String v) {
		if(isVertex(v)) {
			for(String a : graph.get(v).keySet())
			graph.get(a).remove(v);	
			graph.remove(v);
		}
	}
		
	/**
	 * Método que retorna o numero de vertices
	 * @return O tamanho do grafo (número de vértices)
	 */
	public int numVertex() {
		return graph.size();
	}
		
	/**
	 * Método que retorna o iterator dos vertices
	 * @return O itertador com todos os nomes das estações (vétices) do grafo
	 */
	public Iterable<String> getVertex() {
			return graph.keySet();
	}
		
	/**
	 * Método que verifica se é uma aresta
	 * @param v Nome do vértice de início (estação de partida)
	 * @param u Nome do vértice final (estação de destino)
	 * @return Uma resposta true casoseja uma aresta, e false, caso não
	 */
	public boolean isEdge(String v, String u) {
		return graph.containsKey(v) && graph.get(v).containsKey(u);
	}
		
	/**
	 * Método que adiciona uma aresta se ela nao existir
	 * @param v Nome do vértice de início (estação de partida)
	 * @param u Nome do vértice final (estação de destino)
	 * @param t Tempo que leva de uma estação até outra
	 */
	public void addEdge(String v, String u, Double t) {
		if(!isEdge(v, u) && t > 0) {			
			graph.get(v).put(u, t);
			graph.get(u).put(v, t);
		}
	}	
			
	/**
	 * Método que retorna uma aresta se ela existir
	 * @param v Nome do vértice de início (estação de partida)
	 * @param u Nome do vértice final (estação de destino)
	 * @return 
	 */
	public double getEdge(String v, String u) {
		return isEdge(v, u) ? graph.get(u).get(v) : -1;
	}
		
	/**
	 * Método que remove uma aresta se ela existir
	 * @param u Nome do vértice de início (estação de partida)
	 * @param v Nome do vértice final (estação de destino)
	 */
	public void removeEdge(String u, String v) {
		if(isEdge(v, u)) {
			graph.get(v).remove(u);
			graph.get(u).remove(v);
		}
	}
		
	/**
	 * Método que retorna o numero de arestas ajacentes do vertice, ou -1 se nao existir
	 * @param v Nome da estação (vértice)
	 * @return O número de arestas que estão ligadas ao vétices, ou -1 caso não tenha
	 */
	public int numEdge(String v) {
		return isVertex(v) ? graph.get(v).size() : -1;
	}
		
	/**
	 * Método que retorna o iterator dos vertices adjacentes, ou null se sao exitir
	 * @param v Nome do vétice
	 * @return O iterador com todos os vétices adjacentes do vértice atual
	 */
	public Iterable<String> getAdjacent(String v) {
		return isVertex(v) ? graph.get(v).keySet() : null;
	}
		
	/**
	 * Algoritmo de Dijikstra: Define os caminhos de um vértice até o outro, inclusive o mínimo
	 * @param v Nome do vértice de início (estação de partida)
	 * @param u Nome do vértice final (estação de destino)
	 * @return Uma HashMap com os caminho mínimo
	 */
	public Stack<Path> dijkstra(String v, String u) {
			//Verifica se os vertice existem
			if(isVertex(v) && isVertex(u)) {
				//Armazena os visitados e suas informacoes
				HashMap<String, Path> visited = new HashMap<>();
				
				//Armazena os que faltam visitar
				PriorityQueue<Path> next = new PriorityQueue<>();
				next.add(new Path(v, null, 0));
				
				//Verificar se tem proximo e se o destino nao foi atingido
				while(!next.isEmpty() && !visited.containsKey(u)) {
					//Pega as informacoes e o nome do proximo
					Path info = next.remove();
					String rem = info.getVertex();
					
					//Verifica se ele nao foi visitado
					if(!visited.containsKey(rem)) {
						visited.put(rem, info);
						
						//Verifica os adjacentes a ele					
						for(String cur : getAdjacent(rem)) {												
							//Atualiza a distancia dos adjacentes nao visitados
							if(!visited.containsKey(cur)) {
								double time = getEdge(rem, cur);
								time += info.getTime();
								next.add(new Path(cur, rem, time));
							}
						}
					}
				}
							
				//Se o destino foi atingido retorna a pila de path, se nao null
				return visited.containsKey(u) ? getPath(visited, v, u) : null;
			}			
			
			return null;
	}
		
	/**
	 * Método que converte os vétices visitados em uma pilha de paths (caminhos)
	 * @param visited HashMap com os vétices visitados no algoritmo de caminho mínimo
	 * @param v Nome do vértice de início (estação de partida)
	 * @param u Nome do vértice final (estação de destino)
	 * @return Uma estrutura de pilha com os vétices visitados
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
