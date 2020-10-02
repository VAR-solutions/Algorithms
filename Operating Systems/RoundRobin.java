import java.util.*;
public class RoundRobin {
	int name;
	int bt;
	int at;
	int ct;
	int tat;
	int wt;
	int flag;
	
	public static void main(String[] args) {
		int n;
		System.out.println("Enter number of processes");
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		RoundRobin[] r = new RoundRobin[n];
		for(int i=0;i<n;i++){
			System.out.println("enter burst time of process "+i);
			r[i]= new RoundRobin();
			r[i].name = i;
			r[i].bt = in.nextInt();
			System.out.println("enter arrival time of process "+i);
			r[i].at = in.nextInt();
		}
		System.out.println("Enter time slice");
		int timeslice = in.nextInt();
		RoundRobin t = new RoundRobin();
		for(int i=1;i<n;i++){
			for(int j=0;j<n-i;j++){
				if(r[j].at > r[j+1].at){
					t = r[j];
					r[j] = r[j+1];
					r[j+1] = t;
				}
			}
		}
		for(int i=0;i<n;i++){
			System.out.println(r[i].name +"  "+r[i].bt);
		}
		/*RoundRobin[] temp = new RoundRobin[n];
		for(int i=0;i<n;i++){
			temp[i] = r[i];
		}*/
		int[] bt = new int[n];
		for(int i=0;i<n;i++){
			bt[i]=r[i].bt;
		}
		int k=0;
		int tcurr=0;
		int pflag=0;
		int sumw=0;
		for(k=0;;k++){
			if(k>n-1){
				k=0;
			}
			if(r[k].bt>0){
				System.out.print(" "+tcurr+" "+r[k].name+" ");
			}
			int ti=0;
			while(ti<timeslice && r[k].bt >0){
				ti++;
				tcurr++;
				r[k].bt--;
			}
			if(r[k].bt<=0 && r[k].flag !=1){
				r[k].tat = tcurr - r[k].at;
				r[k].wt = tcurr - bt[k] - r[k].at;
				pflag++;
				r[k].flag = 1;
				sumw +=r[k].wt;
				
			}
			if(pflag == n){
				break;
			}
			
		}
		System.out.println(" "+tcurr);
		double avgw;
		avgw = sumw/n;
		for(int i=0;i<n;i++){
			System.out.println(r[i].name+ "  "+bt[i]+" "+r[i].wt);
		}
		System.out.println("average waiting time is: "+avgw);

	}


}
