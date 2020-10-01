vector<int> lista;

int kadane(){

  int max_aqui = 0;
  int max_total = 0;
  
  for(int i=0;i<lista.size();i++){
  
     max_aqui += lista[i];
     
     if(max_aqui < 0) max_aqui = 0;
     max_total = max(max_total,max_aqui);
  }
  return max_total;
}
