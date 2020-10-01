/******************************************************
    Criador: Jose Carlos da Silva Cruz
    codeforces: kinhosz
    e-mail: jcsc@cin.ufpe.br
	Convex hull trick: (para casco inferior)
		- deque
		- struct line
******************************************************/
#include <bits/stdc++.h>
using namespace std;

typedef struct{

	int m; // inclinacao
	int c; // constante da funcao

}line;

deque<line> dq; // deque para adicionar linhas

// recebe duas linhas e calcula seu ponto de interseccao no eixo x. NAo podem ter inclinacoes iguais
double inter(line t1,line t2){

	double ret;

	ret = (double) (t2.c - t1.c)/(t1.m - t2.m);

	return ret;
}

// funcao para adicionar uma nova linha

void add(line novo){

	// criando o convex hull (para cascos inferiores)
	bool ok = true;
	line temp,temp2;
	double point,point2;

	while(dq.size() > 1 && ok){
		temp = dq.back();
		dq.pop_back();  // remove temporariamente a ultima linha
		temp2 = dq.back();
		point = inter(temp,temp2); // calcula a interseccao das retas e devolve a coordenada x
		point2 = inter(temp,novo); // ponto de interseccao da ultima reta e da reta que desejo adicionar

		// caso point < point2, entao a reta removida nao pode ser removida. Logo, readicionamos a reta
		if(point < point2){
			dq.push_back(temp); // devolvendo a reta removida
			ok = false; // condicao para parar o loop
		}
	}
	// apos sair do while, adicionamos nossa nova reta no seu devido lugar
	dq.push_back(novo);
}

// funcao para consultar
int query(int find){

	int s,e,p;
	double point;
	int ret;
	s = 0;
	e = dq.size() - 1;
	p = (s+e)/2;

	while(s < e){

		point = inter(dq[p],dq[p+1]);
		if(point < find){
			s = p+1;
			p = (s+e)/2;
		}
		else{
			e = p;
			p = (s+e)/2;
		}
	}
	ret = (dq[p].m * find) + dq[p].c;

	return ret;

}

int main(){


	int p,c;
	line aux;

	for(int i=0;i<4;i++){
		scanf("%d %d",&p,&c);
		aux.m = p;
		aux.c = c;
		add(aux);
		printf("Minha deque contem:\n");
		for(int j=0;j<dq.size();j++){
			printf("linha %d: [%d %d]\n",j,dq[j].m,dq[j].c);
		}
	}
	printf("maior valor = %d\n",query(0));

}
