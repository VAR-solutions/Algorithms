package forwardChaining;
import java.awt.Frame;
import java.util.*;


public class ForwardChaining {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		prln("Enter Number of Horn Clauses");
		int n = sc.nextInt();
		sc.nextLine();
		for(int i=0; i < n; i++) {				// Iterate over number of Horn clause
			String s = sc.nextLine();           //Takes a Horn Clause
			
			makeInferred(s.substring(0, s.indexOf("=>")));
			GlobalVar.head.put(s.substring(0, s.indexOf("=>")), s.substring(s.indexOf("=>")+2,s.length()));
		}
		prln("Enter Number of Agenda");
		int m = sc.nextInt();
		//sc.next();
		for(int i=0 ; i<m; i++) {
			String c = sc.next();
			GlobalVar.agenda.add(c);
		}
		prln("Enter query");
		String q = sc.next();
		prln("Query is: "+q);
		
		boolean flag = false;
		while(!GlobalVar.agenda.isEmpty()) {			// Main Algorithm Starts
			String p = GlobalVar.agenda.remove();		//Pops from queue
			
			if(p.equals(q)) {
				flag = true;
				prln("\nResult: Entails\n");
				break;
			}
			//prln("Working With: "+p);
			if(GlobalVar.inferred.containsKey(p) && GlobalVar.inferred.get(p) == false) {
				
				GlobalVar.inferred.put(p, true);
				
				for(String clause:GlobalVar.head.keySet()) {		// Iterate over all Body of the Horn Clauses
					if(clause.contains(p)) {
						int temp = GlobalVar.count.get(clause);
						temp = temp -1;
						GlobalVar.count.put(clause, temp);
						
						if(GlobalVar.count.get(clause) == 0) {
							GlobalVar.agenda.add(GlobalVar.head.get(clause));
						}
					}
				}
			}
		}
		if(!flag) {
			prln("\nResult: Doesn't Entail\n");
		}
		
//		prln("Agenda Queue: "+GlobalVar.agenda);
//		prln("Inferred: "+GlobalVar.inferred);
//		prln("Count: "+GlobalVar.count);
//		prln("Head: "+GlobalVar.head);
	}
	
	static void makeInferred(String s) {		// Initializes All literals of the Body to False 
		//prln(s);
		for(int i=0; i<s.length(); i++) {
			 if(!Character.toString(s.charAt(i)).equals("^")) {
				GlobalVar.inferred.put(Character.toString(s.charAt(i)), false); 
			 }
		}
		
		int c = s.replace("^", "").length();		// Initialize Count variable 
		GlobalVar.count.put(s, c);
	}
	
	static void prln(Object ob) {
		System.out.println(ob);
	}
	
	public static class GlobalVar{
		static Map<String, String> head = new HashMap<String,String>();
		static Map<String, Boolean> inferred = new HashMap<String, Boolean>();
		static Map<String, Integer> count = new HashMap<String,Integer>();
		static Queue<String> agenda = new LinkedList<String>();
	}
}
