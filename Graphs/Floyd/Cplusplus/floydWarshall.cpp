#include <stdio.h>
#include <limits.h>
using namespace std;
#define dir true
#define n_dir false
class grafo{
    private:
        struct head_graph{
            int **matriz_ad;
            int numvert;
            int numares;
            bool direct;
        };
        bool criado = false;
        head_graph g;
    public:
        void create_graph(int tmax, bool tipo){
            g.matriz_ad = new int*[tmax];
            for(int i = 0; i < tmax; i++){
                g.matriz_ad[i] = new int[tmax];
            }
            g.numares = 0;
            g.numvert = tmax;
            g.direct = tipo;
            criado = true;
            for(int i = 0; i <tmax; i++){
                for(int j = 0; j<tmax; j++){
                    if(i != j){
                        g.matriz_ad[i][j] = INT_MAX;
                    }
                    else{
                        g.matriz_ad[i][j] = 0;
                    }
                }
            }
        }

        void floyd_warshall(){
            for(int k = 0; k < g.numvert; k++){
                for(int i = 0; i < g.numvert; i++){
                    for(int j = 0; j <g.numvert; j++){
                        if((g.matriz_ad[i][k]!= INT_MAX)
                                &&(g.matriz_ad[k][j] != INT_MAX)
                                    &&(g.matriz_ad[i][j] > g.matriz_ad[i][k] +g.matriz_ad[k][j])){
                            g.matriz_ad[i][j] = g.matriz_ad[i][k] +g.matriz_ad[k][j];
                        }
                    }
                }
            }
        }

        void add_edge(int u, int v, int peso){
            if(criado){
                g.numares++;
                g.matriz_ad[u][v] = peso;
                if(!g.direct){
                    g.matriz_ad[v][u] = peso;
                }
            }
        }

        void matriz_ad(){
            for(int i = 0; i < g.numvert; i++){
                for(int j = 0; j< g.numvert; j++){
                    if(g.matriz_ad[i][j] == INT_MAX){
                        printf("I ");
                    }else{
                        printf("%d ", g.matriz_ad[i][j]);
                    }
                }
                printf("\n");
            }
        }
};
int main(){
    grafo g;
    g.create_graph(4,dir);
    g.add_edge(1,0,2);
    g.add_edge(0,2,3);
    g.add_edge(2,3,1);
    g.add_edge(3,0,6);
    g.add_edge(2,1,7);
    printf("initial matriz of adjacency(I is infinity)\n");
    g.matriz_ad();
    g.floyd_warshall();
    printf("end matriz  of adjacency\n");
    g.matriz_ad();
    return 0;
}
