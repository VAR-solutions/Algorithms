  include<stdio.h>
//EXTRACT MIN
int extractMin(int d[10],int n,int Flag[10])
{

 int i=0,j,min=999;
 
 
  for(i=0;i<n;i++)
  {
        
 	if(d[i]<min && Flag[i]==0)
 	{
 	min=d[i];
 	j=i;
 	}
  }
  Flag[j]=1;
 
  return j;
 
}


//Dijkstra Function
void dijkstra(int G[10][10],int n,int s)
{
     int d[n],i,j,k,Q[n];
     int pi[n],Flag[n];
     
     //INITIALIZE
     for(i=0;i<n;i++)
     {
          d[i]=99;
          pi[i]=0;
     }
     d[s]=0;
     
     //ALGO****************START***********
     
     //FLAG CREATION
     for(i=0;i<n;i++)
     {
     Flag[i]=0;
     }
     
     //
     for(i=0;i<n;i++)
     {
     Q[i]=i+1;
     }
     
     for(k=0;k<n;k++)
     {
		 i=extractMin(d,n,Flag);
		
		      for(j=0;j<n;j++)
		       {
		           if( G[i][j]!=0 && G[i][j]!=99 && d[j]>(d[i]+G[i][j]))
		           {
		                d[j]=d[i]+G[i][j];
		                pi[j]=i;
		           }
		       }
		       
		  
      }
      
    

 	//PRINT WEIGHT & PI
 	for(i=0;i<n;i++)
	{
	  	printf("\nd[%d] :%d\tpi[%d] : %d",i,d[i],i,pi[i]);
	}
	printf("\n");
  	return ;
}

int main()
{
	
	int n,i,j,s,G[10][10];;
	printf("Enter the number of vertex :");
	scanf("%d",&n);
	
	printf("Enter source node :");
	scanf("%d",&s);

	printf("Enter weight if edge Exist \n \t0 if same vertex\n \t99 if edge don't exist");
	 	 
	//ENTERING WEIGHT
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\nEnter G[%d][%d] :",(i+1),(j+1));
		   	scanf("%d",&G[i][j]);
		}
	}
	 	 
	for(i=0;i<n;i++)
	{
		  for(j=0;j<n;j++)
		  {
		  	printf("%d ",G[i][j]);
		  }
		  printf("\n");
	}
	 
	dijkstra(G,n,s);

	return 0;
}
