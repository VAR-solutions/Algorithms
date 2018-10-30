
//package himsri;

/**
 *
 * @author Himanshu
 */
import javax.swing.JOptionPane;
//import java.util.Scanner;
class process{
    public String name;
	public int bt;
	public int at;
	public int prt;
	public int wt,ta;
	public int flag;
        
        public void processdata(String k,int b,int a,int p){
            this.name=k;
            this.bt=b;
             this.at=a;
             this.prt=p;
        }

}
public class Himsri {

    public static void main(String[] args) {
        
    int n;
 process[] p = new process[20];
 

   n=Integer.parseInt(JOptionPane.showInputDialog("Enter Number of Processes:"));

for(int i=0;i<n;i++){
  
    String k = JOptionPane.showInputDialog( "Enter the process name?");
    int l= Integer.parseInt(JOptionPane.showInputDialog("Enter The BurstTime for Process "+k+" "));
    int z=Integer.parseInt(JOptionPane.showInputDialog("Enter The ArrivalTime for Process "+k+" "));
    int y=Integer.parseInt(JOptionPane.showInputDialog("Enter The Priority for Process "+k+" "));
      p[i]=new process();
    p[i].processdata(k,l,z,y);
}
    
 int select;
 do
 {
 select=Integer.parseInt(JOptionPane.showInputDialog("Select An Option: \n1.SJF NonPreemptive\n2.Round Robin\n3.SJF Preemptive\n4.FCFS\n5.Priority Preemptive\n6.Priority Non-Preemptive\n7.Exit"));

switch(select)
 {
 case 1:
//System.out.println("SJF NonPreemptive");
 //System.out.println ("-------------------");
 SjfNp(p,n);//106
 break;
case 2:
 //System.out.println("Round Robin");
 //System.out.println ("-------------------");
 RoundRobin(p,n);//184
 break;
 case 3:
  //  System.out.println("SJF Preemptive");
 //System.out.println ("-------------------");
 SjfP(p,n); //322
 break;
 
 case 4:
    //System.out.println("FCFS");
 //System.out.println ("-------------------");
 Fcfs(p,n); //261
 break;
 
 case 5:
    //System.out.println("Priority Preemptive");
 //System.out.println ("-------------------");
 Prioritypremptive(p,n); //408
 
 break;
 
 case 6:
    //System.out.println("Priority Non-Preemptive");
 //System.out.println ("-------------------");
 PriorityNonpremptive(p,n); //489
 break;
case 7:
 break;
 }
 }
 while(select!=7);
  }
     static void b_sort(process temp7[],int n)
{
process t;
int i,j;
for(i=1;i<n;i++)
for(j=0;j<n-i;j++){
if(temp7[j].at > temp7[j+1].at){
t = temp7[j];
temp7[j] = temp7[j+1];
temp7[j+1] = t;
}
}
}  
    @SuppressWarnings("empty-statement")
    static void SjfNp(process k[],int n)
 {
     System.out.print("\n-------------------------------------------------------------------------------------\n");
    System.out.print("SJF Non Pre-emptive");
     System.out.print("\n-------------------------------------------------------------------------------------\n");
     process []temp=new process[10];
     process t;
     int sumw=0;
     int sumt=0;
     int x=0;
     float avgwt=0;
     float avgta=0;
     int i,j;
     
     for( i=0;i<n;i++){
         temp[i]=k[i];
     }
     b_sort(temp,n);
     
     for(i=2;i<n;i++){
         for(j=1;j<n-i+1;j++){
             if(temp[j].bt>temp[j+1].bt){
                 t = temp[j];
                    temp[j] = temp[j+1];
	temp[j+1] = t;
             }
         }
     }
     
     System.out.println("PROC.\tB.T.\tA.T.");
for(i=0;i<n;i++){
 System.out.println("  "+temp[i].name+"       "+temp[i].bt+"       "+temp[i].at);
}
     
     
     sumw = temp[0].wt = 0;
sumt = temp[0].ta = temp[0].bt - temp[0].at;

for(i=1;i<n;i++){
     temp[i].wt = (temp[i-1].bt + temp[i-1].at + temp[i-1].wt) - temp[i].at;
     temp[i].ta = (temp[i].wt + temp[i].bt);
     sumw+=temp[i].wt;
         sumt+=temp[i].ta;
}
       avgwt = (float)sumw/n;
      avgta = (float)sumt/n;
      System.out.println("\nPROC.\tB.T.\tA.T.\tW.T\tT.A.T");
     for(i=0;i<n;i++)
	 System.out.println("" +temp[i].name+"     "+temp[i].bt+"       "+temp[i].at+"      "+temp[i].wt+"          "+temp[i].ta);

	    System.out.println("\n GANTT CHART\n ");
		/*for(i=0;i<n;i++)
	 System.out.print("      "+temp[i].name+"");
		 System.out.print("\n ");
                 System.out.print(" ");
     	 System.out.print("0\t");
		for(i=1;i<=n;i++){
			x+=temp[i-1].bt;
			 System.out.print(x+"\t");
		}*/
                System.out.print("0");
                                         for(i=1;i<=n;i++){
                                             System.out.print(" "+temp[i-1].name+" ");
			x+=temp[i-1].bt;
			 System.out.print(x);
		                      }
                
                
	 System.out.println("\n"+" Average waiting time = "+avgwt);
         System.out.println("\n"+" Average turn-around = "+avgta);
	 System.out.println("\n----------------------------------------------------------------------------------\n");
}
 
 static void RoundRobin(process m[],int n)
 {
     int []b=new int[20];
 System.out.print("\n--------------------------------------------------------------\n");
 System.out.print("Round Robin Scheduling");
 System.out.print("\n--------------------------------------------------------------\n");
 for( int f=0;f<n;f++){
            m[f].flag=0;
        }
 for(int i=0;i<n;i++){
     b[i]=m[i].bt;
   }
	int pflag=0,t,tcurr=0,k,i,Q=0;
	int sumw=0,sumt=0;
	float avgwt=0;
        float avgta=0;
	process []temp1=new process[n];
        process []temp2=new process[n];


	for(i=0;i<n;i++)
		temp1[i]=m[i];
    
	b_sort(temp1,n);
      /*********/  
        System.out.println("PROC.\tB.T.\tA.T.");
for(i=0;i<n;i++){
 System.out.println("  "+temp1[i].name+"       "+temp1[i].bt+"       "+temp1[i].at);
}
/**********/
	for(i=0;i<n;i++)
		temp2[i]=temp1[i];
	Q=Integer.parseInt(JOptionPane.showInputDialog("Enter The Time Quantum:"));
	System.out.println("\n TimeQuantum:"+Q);
    System.out.println("\n GANTT CHART\n ");
	for(k=0;;k++){
		if(k>n-1)
			k=0;
		if(temp1[k].bt>0)
		 System.out.print(" "+tcurr+" "+temp1[k].name);
		t=0;
		while(t<Q && temp1[k].bt > 0){
			t++;
			tcurr++;
			temp1[k].bt--;
		}          
		 if(temp1[k].bt <= 0 && temp1[k].flag != 1){
			temp1[k].wt = tcurr - b[k]- temp1[k].at;
			temp1[k].ta = tcurr - temp1[k].at;
			pflag++;
			temp1[k].flag = 1;
			sumw+=temp1[k].wt;
                        
                                                     
			sumt+=temp1[k].ta;
		}
		
                                                      if(pflag==n) {
                                                          break;
                                                      } else {
                                                      }
	}
	 System.out.print(" "+tcurr);
         for( i=0;i<n;i++){
             m[i].bt=b[i];
         }
  /*************/
          System.out.println("\nPROC.\tB.T.\tA.T.\tW.T\tT.A.T");
     for(i=0;i<n;i++)
	 System.out.println("" +temp1[i].name+"     "+temp1[i].bt+"       "+temp1[i].at+"      "+temp1[i].wt+"          "+temp1[i].ta);
	/************/
     avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	System.out.println("\n"+" Average waiting time = "+avgwt);
         System.out.println("\n"+" Average turn-around = "+avgta);
	 System.out.println("\n--------------------------------------------------------------------------\n"); 
         for( i=0;i<n;i++){
             m[i].bt=b[i];
         }
}
 
  static void Fcfs(process r[],int n){
     
     System.out.print("\n------------------------------------------------------------------------------------------\n");
    System.out.print("FCFS Algorithm");
     System.out.println("\n------------------------------------------------------------------------------------------\n");
	process []temp3=new process[20];
	int sumw=0,sumt=0;
	int x = 0;
	float avgwt=0;
        float avgta=0;
	int i,j;
	for(i=0;i<n;i++)
		temp3[i]=r[i];

	b_sort(temp3,n);

	System.out.println("\n PROC.\tB.T.\tA.T.");
		for(i=0;i<n;i++)
		System.out.println("   "+temp3[i].name+"   "+temp3[i].bt+"     "+temp3[i].at);

		 sumw = temp3[0].wt = 0;
		sumt = temp3[0].ta = temp3[0].bt - temp3[0].at;

		for(i=1;i<n;i++){
			temp3[i].wt = (temp3[i-1].bt + temp3[i-1].at + temp3[i-1].wt) - temp3[i].at;
			temp3[i].ta = (temp3[i].wt + temp3[i].bt);
			sumw+=temp3[i].wt;
			sumt+=temp3[i].ta;
		}
		avgwt = (float)sumw/n;
		avgta = (float)sumt/n;
		System.out.println("\nPROC.\tB.T.\tA.T.\tW.T\tT.A.T");
		for(i=0;i<n;i++)
		System.out.println(""+temp3[i].name+"       "+temp3[i].bt+"       "+temp3[i].at+"       "+temp3[i].wt+"       "+temp3[i].ta);

	System.out.println("\nGANTT CHART\n ");
		
                System.out.print("0");
                      for(i=1;i<=n;i++){
                                                         System.out.print(" "+temp3[i-1].name+" ");
			x+=temp3[i-1].bt;
			System.out.print(x);
		     }
                
                
                
		System.out.println("\n"+" Average waiting time = "+avgwt);
         System.out.println("\n"+" Average turn-around = "+avgta);
		System.out.println("\n--------------------------------------------------------------\n");
     
     
 }
 
static  void SjfP(process o[],int n){
    
    System.out.print("\n-------------------------------------------------------------------------------------\n");
    System.out.print("Shortest Job First - Pre-emptive");
    System.out.print("\n-------------------------------------------------------------------------------------\n");
	int l,t_total=0,m,i;
        for( int f=0;f<n;f++){
            o[f].flag=0;
        }
        int tcurr;
        int b[];    //declaring array
b = new int[20];
        int min_at,j,x,min_bt;
	int sumw=0,sumt=0;
	float avgwt=0,avgta=0;
	
process []temp4=new process[10];
     process t;
	for(i=0;i<n;i++){
		temp4[i]=o[i];
		t_total+=o[i].bt;
	}
	b_sort(temp4,n);
    /******/
        System.out.println("\n PROC.\tB.T.\tA.T.");
		for(i=0;i<n;i++)
			System.out.println("   "+temp4[i].name+"   "+temp4[i].bt+"           "+temp4[i].at);
           
	/******/
        for(i=0;i<n;i++)
		b[i] = temp4[i].bt;
        

	l=0;
        m=0;
System.out.println("\n GANTT CHART\n");
	System.out.print(l+" "+temp4[l].name+" ");
	for(tcurr=0;tcurr<t_total;tcurr++){
                               
		if(b[l] > 0 && temp4[l].at <= tcurr){
                   // System.out.print("c1");
			b[l]--;}

		if(l!=m){
			System.out.print(tcurr+" "+temp4[l].name+" ");
                                                              //     System.out.print("c2");
                                                               }

		if(b[l]<=0 && temp4[l].flag != 1){

			temp4[l].flag = 1;
			temp4[l].wt = (tcurr+1) - temp4[l].bt - temp4[l].at;
			temp4[l].ta = (tcurr+1) - temp4[l].at;
			sumw+=temp4[l].wt;
			sumt+=temp4[l].ta;
                          //   System.out.print("sumw="+sumw+" sumt"+sumt+"\n");
		}
		m=l;	
                                       min_bt = 999;
		for(x=0;x<n;x++){

			if(temp4[x].at <= (tcurr+1) && temp4[x].flag != 1){

				if(min_bt != b[x] && min_bt > b[x]){
					min_bt = b[x];
					l=x;
				}
			}
		}

	}//for
	System.out.println(" "+tcurr);
        /************/
                       System.out.println("\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
		for(i=0;i<n;i++)
		System.out.println("\n"+"   "+temp4[i].name+"    "+temp4[i].bt+"      "+temp4[i].at+"        "+temp4[i].wt+"        "+temp4[i].ta);
/************/	
                              avgwt = (float)sumw/n;	avgta = (float)sumt/n;
	System.out.println("\n"+" Average waiting time = "+avgwt);
         System.out.println("\n"+" Average turn-around = "+avgta);
	System.out.println("\n--------------------------------------------------------------\n");
        
    
    
}

static void  Prioritypremptive(process e[],int n){
   System.out.print("\n--------------------------------------------------------------\n");
    System.out.print("Priority Pre-emptive");
    System.out.print("\n--------------------------------------------------------------\n");
    for( int f=0;f<n;f++){
            e[f].flag=0;
        }
	int i,t_total=0,tcurr,j,x,min_pr;
        int []c;
    c = new int[20];
	int sumw=0,sumt=0;
	float avgwt=0,avgta=0;
	process []temp5=new process[20];
     process t1;

	for(i=0;i<n;i++){
		temp5[i]=e[i];
		t_total+=e[i].bt;
	}
             
	b_sort(temp5,n);

         /******/
        System.out.println("\n PROC.\tB.T.\tA.T.\tPRT");
		for(i=0;i<n;i++)
			System.out.println("   "+temp5[i].name+"   "+temp5[i].bt+"           "+temp5[i].at+"     "+temp5[i].prt);
           
	/******/
       
	for(i=0;i<n;i++)
		c[i] = temp5[i].bt;

	i=j=0;
     
System.out.println("\n GANTT CHART\n");
	System.out.print(i+" "+temp5[i].name+" ");
	for(tcurr=0;tcurr<t_total;tcurr++)
	{

		if(c[i] > 0 && temp5[i].at <= tcurr)
			c[i]--;

		if(i!=j)
			System.out.print(tcurr+" "+temp5[i].name+" ");

                                      
                  //System.out.print("temp5 set.flag"+temp5[i].flag +"\n");
		if(c[i]<=0 && temp5[i].flag != 1)
		{
			temp5[i].flag = 1;
			temp5[i].wt = (tcurr+1) - temp5[i].bt - temp5[i].at;
			temp5[i].ta = (tcurr+1) - temp5[i].at;
			sumw+=temp5[i].wt;
			sumt+=temp5[i].ta;
		}
		j=i;
		min_pr = 999;
		for(x=0;x<n;x++){
                                                              
			if(temp5[x].at <= (tcurr+1) && temp5[x].flag != 1){
                                                                                       
				if(min_pr != temp5[x].prt && min_pr > temp5[x].prt){
                                                                                                
					min_pr = temp5[x].prt;
					i=x;
				}
			}
		}

	}//for

	System.out.print(" "+tcurr);
        
         /************/
                       System.out.println("\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
		for(i=0;i<n;i++)
		System.out.println("\n"+"   "+temp5[i].name+"    "+temp5[i].bt+"      "+temp5[i].at+"        "+temp5[i].wt+"        "+temp5[i].ta);
/************/
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	System.out.println("\n"+" Average waiting time = "+avgwt);
         System.out.println("\n"+" Average turn-around = "+avgta);
	System.out.println("\n--------------------------------------------------------------\n"); 
     
     
 }
    @SuppressWarnings("empty-statement")
 static void PriorityNonpremptive(process g[],int n){
     
     System.out.print("\n--------------------------------------------------------------\n");
     System.out.print("Priority Non Pre-emptive");
      System.out.print("\n--------------------------------------------------------------\n");
	process []temp6=new process[10];
                   process t;
	int sumw=0,sumt=0;
	float avgwt=0,avgta=0;
	int i,j;
	int x = 0;

	for(i=0;i<n;i++)
		temp6[i]=g[i];

	b_sort(temp6,n);

        
	for(i=2;i<n;i++)
		for(j=1;j<n-i+1;j++){
			if(temp6[j].prt > temp6[j+1].prt){
				t = temp6[j];
				temp6[j] = temp6[j+1];
				temp6[j+1] = t;
			}
		}

	System.out.println("\n PROC.\tB.T.\tA.T.\tPRT.");
		for(i=0;i<n;i++)
			System.out.println("   "+temp6[i].name+"   "+temp6[i].bt+"      "+temp6[i].at+"    "+temp6[i].prt);

		sumw = temp6[0].wt = 0;
		sumt = temp6[0].ta = temp6[0].bt - temp6[0].at;

		for(i=1;i<n;i++){
			temp6[i].wt = (temp6[i-1].bt + temp6[i-1].at + temp6[i-1].wt) - temp6[i].at;;
			temp6[i].ta = (temp6[i].wt + temp6[i].bt);
			sumw+=temp6[i].wt;
			sumt+=temp6[i].ta;
		}
		avgwt = (float)sumw/n;
		avgta = (float)sumt/n;
		System.out.println("\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
		for(i=0;i<n;i++)
		System.out.println("\n"+"   "+temp6[i].name+"    "+temp6[i].bt+"      "+temp6[i].at+"        "+temp6[i].wt+"        "+temp6[i].ta);

		  System.out.println("\n GANTT CHART\n ");
	
                
                System.out.print("0");
                for(i=1;i<=n;i++){                       
                                                             System.out.print(" "+temp6[i-1].name+" ");
			x+=temp6[i-1].bt;
			System.out.print(x);
		}
                
	System.out.println("\n"+" Average waiting time = "+avgwt);
         System.out.println("\n"+" Average turn-around = "+avgta);
		System.out.println("\n--------------------------------------------------------------\n");
                
          }
     }
    
