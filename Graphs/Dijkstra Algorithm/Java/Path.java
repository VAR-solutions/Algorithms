package util;

/**
 * Classe que representa um caminho entre dois vértices
 * @author Brendo Nascimento e Gabriel Azevedo
 *
 */
public class Path implements Comparable<Path>{
	
	private String vertex;
	private String previous;
	private Double time;
	
	/**
	 * Método construtor
	 * @param v Vértice inicial (estação de partida)
	 * @param p Vértice final (estação de chegada)
	 * @param t Tempo que leva para ir da estação de partida até a chegada
	 */
	public Path(String v, String p, double t) {
		vertex = v;
		previous = p;
		time = t;
	}
	
	//Getters e setters
	public String getVertex() {
		return vertex;
	}
	
	public void setVertex(String v) {
		vertex = v;
	}
	
	public String getPrevious() {
		return previous;
	}
	
	public void getPrevious(String p) {
		previous = p;
	}
	
	public double getTime() {
		return time;
	}
	
	public void setTime(double t) {
		time = t;
	}
	
	/**
	 * Método que compara o tempo entre caminhos
	 */
	public int compareTo(Path p) {				
		return time.compareTo(p.getTime());
	}
	
}
