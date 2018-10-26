 program bogosort (input, output);
 const max=10;   {*Tamanho do vetor *}
 type vetor=array[1..max] of integer;
 var lista, lista1: vetor;
     i: integer;
     j: boolean;
     pos: integer;
 
 	 function teste(var proto: vetor): boolean;     {*Verifica se o vetor NÃO está ordenado.*}
 	 var i: integer;
 	 begin
 		 teste:=true;
 		 for i:=2 to max do
 			 if (proto[i]<proto[i-1]) then
 				 break;
 		 if (i=max) and (proto[max]>=proto[max-1]) then
 			 teste:=false;
 	 end;
 
 begin
 	 randomize;    {*Inicializa o gerador de numeros aleatórios *}
 	 writeln('Escreva abaixo os ', max,' elementos do vetor:');
 	 for i:=1 to max do
 	 begin
 		 read(lista[i]);  
 		 lista1[i]:=lista[i];
 	 end;
 	 for i:=1 to max do           {*Escreve o vetor recebido *}
 		 write(lista1[i],' ');
 	 writeln;
 	 while teste(lista1) do    {*Enquanto o vetor nao esta ordenado...*}
 	 begin
 		 j:=true;
 		 for i:=1 to max do     {*Inicializa o vetor auxiliar *}
 			 lista1[i]:=0;
 		 for i:=1 to max do   {* Este loop preenche aleatoriamente o vetor auxiliar *}
 		 begin
 			 j:=true;
 			 while j do {* Este while garante que nenhum dado será sobrescrito *}
 			 begin
 				 pos:= random(max)+1;    {* Gera posição aleatória *}
 				 if lista1[pos]=0 then     {*Garante que a posição não está ocupada *}
 				 begin
 	 				 lista1[pos]:=lista[i];
 					 j:=false;
 				 end;
 			 end;
 		 end;
 		 for i:=1 to max do	{* Imprime na tela a tentativa *}	
 			 write(lista1[i],' ');
 		 writeln;		
 	 end;
 	 write('A LISTA FOI ORDENADA!');
 end.