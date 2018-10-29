package util;

/**
 * Class that represents the connection between two nodes
 * @author Brendo Nascimento and Gabriel Azevedo
 *
 */
public class Path implements Comparable<Path>{
	
	private String vertex;
	private String previous;
	private Double time;
	
	/**
	 * Constructor
	 * @param v Initial node ('Departure station')
	 * @param p Final node ('Arrival station')
	 * @param t Time it takes from the Departure station to Arrival station
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
	 * Time comparison Method (between two paths)
	 */
	public int compareTo(Path p) {				
		return time.compareTo(p.getTime());
	}
	
}
