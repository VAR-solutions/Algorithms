

import java.util.Arrays;
import java.util.Comparator;

import GreedyHuMai.ActivitySelection.activity;
import GreedyHuMai.JobSequencing.job;

public class JobSequencing {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [] dead = {2,1,2,1,3};
		int [] profit = {100,19,27,25,15};
		int n = dead.length;
		
		job[] j = new job[n];
		
		for(int i=0 ; i<n ; i++) {
			j[i] = new job((char)('a'+i),dead[i],profit[i]);
		}
		
		Arrays.sort(j, new jobcomparator());
		
		for(int i=0 ; i<n ; i++) {
			System.out.println(j[i].profit);
		}
		
		job(j,n);
		
		
	}
	
	private static void job(job[] j, int n) {
		
		boolean[] b = new boolean[n];
		for(int i=0 ; i<n ; i++) {
			b[i]=false;
		}
		int [] result = new int[n];
		
		for(int i=0 ; i <n; i ++) {
			for(int k=Math.min(n, j[i].dead)-1  ; k>=0 ; k--) {
				if(b[k]==false) {
					result[k] = i;
					b[k]=true;
					break;
				}
			}
		}
		
		for(int i =0 ;i < n ; i ++) {
			if(b[i]) {
			System.out.print(j[result[i]].id);
		}}
		
	}

	public static class job {
		public job(char a,int i, int j) {
			this.id = a;
			this.dead = i;
			this.profit =j;
		}
		char id ;
		int dead ;
		int profit;
	}
	
	public static class jobcomparator implements Comparator {

		@Override
		public int compare(Object o1, Object o2) {
			job a1 = (job) o1;
			job a2 = (job) o2;

			return (a1.profit >= a2.profit) ? -1: 1;
		}

	}
	
	
	

}
