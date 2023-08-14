#include <stdio.h>
int main()
{
 int i,j,min,count=0,time,n;
 double avg=0,tat=0,end;
 printf("Enter the number of processes:");
 scanf("%d",&n);
 int at[1000],bt[1000],x[1000];
 printf("Enter the arrival time of the process:");
 for (i=0;i<n;i++)
 {
 scanf("%d",&at[i]);
 }
 printf("Enter the burst time of the process:");
 for(i=0;i<n;i++)
 {
scanf("%d",&bt[i]);
 }
 for(i=0;i<n;i++)
 {
x[i]=bt[i];
 }
 bt[999]=9999;
 for(time=0;count!=n;time++)
 {
 min=999;
for(i=0;i<n;i++)
 {
 if(at[i]<=time && bt[i]<bt[min] && bt[i]>0 )
 {
min=i;
}
 }
 bt[min]--;
 if(bt[min]==0)
 {
 count++;
 end=time+1;
 avg=avg+end-at[min]-x[min];
 tat= tat+end-at[min];
 }
 }
 printf("Average waiting time = %lf\n",avg/n);
 printf("Average Turnaround time = %lf\n",tat/n);
 return 0;
}
