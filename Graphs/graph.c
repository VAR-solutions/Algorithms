#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int **matrix;
  int numEdge;
  int *Mark;
}G;
G create_graph(int n) {
  G grafoAux;
  grafoAux.Mark = (int*) malloc(n*sizeof(int));
  grafoAux.matrix = (int**) malloc(n*sizeof(int*));
  for(int i=0; i<n; i++){
    grafoAux.matrix[i] = (int*) malloc(n*sizeof(int));
  }
  grafoAux.numEdge = 0;
  return grafoAux;
}
int e(G grafo){
  return grafo.numEdge;
}
int first(G grafo, int v, int n){
  for(int i=0; i<n; i++){
    if(grafo.matrix[v][i]!=0) return i;
  }
  return n;
}
int next(G grafo, int v, int w, int n){
  for(int i=w+1; i<n; i++){
    if(grafo.matrix[v][i]!=0) return i;
  }
  return n;
}
void setEdge(G grafo, int i, int j, int wt){
  if (wt==0) printf("ERROR\n");
  if(grafo.matrix[i][j]==0) grafo.numEdge++;
  grafo.matrix[i][j] = wt;
}
void delEdge(G grafo, int i, int j){
  if(grafo.matrix[i][j]!=0) grafo.numEdge--;
  grafo.matrix[i][j] = 0;
}
int isEdge(G grafo, int i, int j){
  return (grafo.matrix[i][j]!=0);
}
int weight(G grafo, int i, int j){
  return (grafo.matrix[i][j]);
}
void setMark(G grafo, int v, int val){
  grafo.Mark[v] = val;
}
int getMark(G grafo, int v){
  return grafo.Mark[v];
}
void print_matrix(G grafo, int n){
  printf("  ");
  for(int i=0; i<n; i++){
    printf("%d ", i);
  }
  printf("\n");
  for(int i=0; i<n; i++){
    printf("%d ", i);
    for(int j=0; j<n; j++){
      printf("%d ", grafo.matrix[i][j]);
    }
    printf("\n");
  }
}
int main(void) {
  G grafinho;
  int n;
  printf("insira o numero de vertices:\n");
  scanf("%d", &n);
  grafinho = create_graph(n);
  printf("insira o numero de arestas:\n");
  int e; 
  scanf("%d", &e);
  while(e--){
    printf("aresta e peso:\n");
    int a, b, p;
    scanf("%d %d %d", &a, &b, &p);
    setEdge(grafinho,a, b, p);
  }
  //print_matrix(grafinho, n);

  return 0;
}
