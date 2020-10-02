let v=[];
const INF=999;
d=[INF,INF,INF,INF];
let G=[
[0,5,INF,INF],
[INF, 0, 6, 3],
[INF,INF,0,INF],
[2,INF,1,0]
]

const dijkstra=()=>
{
	for(let i=0;i<G.length;i++)
		v[i]=0;
	let min=1;
	v[min]=1;
	d[min]=0;
	for(let i=0;i<G.length;i++)
	{
		for(let j=0;j<G.length;j++)
		{
			if(v[j]!=1)
				d[j]= Math.min(d[j],(d[min]+G[min][j]))
		}
		min=d.indexOf(Math.min(...d.filter((x,index)=>v[index]!=1)));
		v[min]=1;
	}
}
dijkstra();
console.log(d);