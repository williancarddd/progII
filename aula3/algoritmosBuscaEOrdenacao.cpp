#define TF 500000 // tamanho do vetor
#define MAX 9999 // maximo elemento gerado randomicamente dentro do vetor

#include <stdbool.h> // para usar variaveis booleanas
#include <time.h>  // calcular a diferença do tempo inicial e final
#include <stdlib.h> // pra usar a funcao RAND()
#include <stdio.h>

void cria(int vetor[TF]){
	for (int i=0;i<TF;i++){
		vetor[i]= rand() % MAX;
	}
}

void exibe(int vetor[TF]){
		int i;
	for (i=0;i<TF;i++)
	   printf("\n vetor[%2d]=%3d",i,vetor[i]);
	getchar();
}

void Bolha(int vetor[TF]){
	int i = 0, j;
	while(i < TF) {
		for(j = 0; j < TF ; j++) {
			if(vetor[j] >  vetor[j + 1]){
				int aux =  vetor[j + 1];
				vetor[j + 1] = vetor[j];
				vetor[j] = aux;
			}
		}
		i++;
	}
}
void selecao(int vetor[],int tl) 
{ 
	int i, j, seta, seta_pos;
	for( i = 0; i < TF; i++) {
		seta = vetor[i];
		seta_pos = i;
		for(j = i+1; j < TF; j++) {
			if(vetor[j]<seta) 
			{ 
				seta=vetor[j]; 
				seta_pos=j; 
			} 
		}
		vetor[seta_pos]=vetor[i]; 
 		vetor[i]=seta; 
	}
}


int  buscaExaustiva (int vetor[TF], int elem)   { // vetor DESORdenado
      int i=0;
      while ((vetor[i] != elem)&&(i<TF))
         i=i+1;
      if ((i < TF) && (vetor[i] == elem)) 
                return i;           // achou na posição i 
                else return  -1; // não achou
}

int buscaSequencial(int vetor[TF], int tl, int elem)   { // obrigatorio o vetor estar ORDENADO
      int i=0;
      while ((elem > vetor[i])&&(i<tl))
              i=i+1;
      
      return i; // achou na posição i OU encontrou a posicao ideal para inserir
}

int buscaBinaria(int vetor[TF],int tl, int elem)    { // obrigatorio o vetor estar ORDENADO
      int inicio, meio, fim;
      inicio=0;
      fim=tl-1;
      meio=(inicio+fim)/2;
      while((elem!=vetor[meio])&&(inicio<fim))       {
         if(elem>vetor[meio])
            inicio=meio+1;
            else
            fim=meio;
         meio=(inicio+fim)/2;
      }
      if (elem>vetor[meio])
         return(meio+1);
         else
         return(meio);
}
int binariaRecursiva(int vetor[], int elem, int inicio, int fim) {
int meio;
    if (inicio > fim)
                return -1; //nao achou
        else {
                meio = (inicio+fim) / 2;
                if (elem == vetor[meio])
                             return meio;
                     else if (elem < vetor[meio])
					           binariaRecursiva(vetor,elem,inicio ,meio-1);
							   else binariaRecursiva (vetor,elem,meio+1,fim);
             }
}

void insercaoDireta(int vetor[TF]){
int aux, i, j, n, posi;
      if (vetor[0]>vetor[1])  {
         aux=vetor[0];
         vetor[0]=vetor[1];
         vetor[1]=aux;
      }
      for (n=2;n<TF;n++)  {
         aux=vetor[n];
        //aux é o elemento a ser reinserido de forma ordenada
        // n-1 é o tamanho do vetor que já está ordenado
         posi=buscaSequencial(vetor,n,aux);
         for(j=n ;j>posi ;j--)
                 vetor[j]=vetor[j-1];
         vetor[posi]=aux;
      }  
}
void insercaoBinaria(int vetor[TF]){
int aux, i, j, n, posi;
      if (vetor[0]>vetor[1])  {
         aux=vetor[0];
         vetor[0]=vetor[1];
         vetor[1]=aux;
      }
      for (n=2;n<TF;n++)  {
         aux=vetor[n];
        //aux é o elemento a ser reinserido de forma ordenada
        // n-1 é o tamanho do vetor que já está ordenado
         posi=buscaBinaria(vetor,n,aux);
         for(j=n ;j>posi ;j--)
                 vetor[j]=vetor[j-1];
         vetor[posi]=aux;
      }  	
}
//quicksort
void quicksort(int vetor[], int inicio, int fim) {
int i, j, pivo, aux;
		i = inicio;
		j = fim;
		pivo = vetor[(inicio + fim) / 2];
		while (i <= j) {
				while (vetor[i] < pivo)
						i++;
				while (vetor[j] > pivo)
						j--;
				if (i <= j) {
						aux = vetor[i];
						vetor[i] = vetor[j];
						vetor[j] = aux;
						i++;
						j--;
				}
		}
		if (inicio < j)
				quicksort(vetor, inicio, j);
		if (i < fim)
				quicksort(vetor, i, fim);
}

//heapSort
void heapsort(int a[], int n) { 
	int i = n / 2, pai, filho, t; 
	while(true) { 
		if (i > 0) { 
			i--; 
			t = a[i]; 
		} else { 
			n--; 
			if (n <= 0) return; 
			t = a[n]; 
			a[n] = a[0]; 
		} 
		pai = i; 
		filho = i * 2 + 1; 
		while (filho < n) { 
			if ((filho + 1 < n) && (a[filho + 1] > a[filho])) 
				filho++; 
			if (a[filho] > t) { 
				a[pai] = a[filho]; 
				pai = filho; 
				filho = pai * 2 + 1; 
			} else { 
				break; 
			} 
		}
		a[pai] = t; 
	} 
}

//mergeSort
void merge(int a[], int l, int m, int r) { 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 =  r - m; 
	int L[n1], R[n2]; 
	for (i = 0; i < n1; i++) 
		L[i] = a[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = a[m + 1+ j]; 
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			a[k] = L[i]; 
			i++; 
		} else { 
			a[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1) { 
		a[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2) { 
		a[k] = R[j]; 
		j++; 
		k++; 
	} 
}
void mergeSort(int a[], int l, int r) { 
	if (l < r) { 
		int m = l+(r-l)/2; 
		mergeSort(a, l, m); 
		mergeSort(a, m+1, r); 
		merge(a, l, m, r); 
	} 
}
main(){
	int tl=0;
	int vetor[TF];
	bool ordenado=false;
	int opcao=0,posicao=-1,elem;
	time_t tempoi, tempof;
	float diferenca;

	while (opcao != -1){
		printf("\n1 - Cria o vetor de %d elementos",TF);
		printf("\n2 - Exibe o vetor gerado");
		printf("\n3 - BOLHA - Ordena o vetor");
		printf("\n4 - Selecao - Ordena o vetor");
		printf("\n5 - Insercao direta que usa a busca sequencial");
		printf("\n6 - insercao binaria que usa a busca binaria");
		printf("\n7 - Quick Sort");
		printf("\n8 - Heap Sort");
		printf("\n9 - Merge Sort");
		printf("\n10 - Busca Exaustiva de um elemento no vetor desordenado");
		printf("\n11 - Busca Sequencial num vetor Ordenado");
		printf("\n12 - Busca Binaria num vetor Ordenado");
		printf("\n13 - Busca Binaria Recursiva num vetor Ordenado");
		printf("\n-1 - Sair");
		printf("\nEntre com a opcao: ");
		scanf("%d",&opcao);
		switch(opcao){
			case 1: srand(time(NULL));  
			        cria(vetor);
			        ordenado=false;
			        printf("\n vetor gerado com %d elementos \n\n",TF);
			        break;
			case 2: exibe(vetor);
			        break;
			case 3: tempoi = time(NULL); // obtem o tempo inicial para cronometrar
			         Bolha(vetor);
			        tempof = time(NULL);
			        diferenca = difftime(tempof, tempoi);
			        printf("\n ordenou vetor e demorou %f num vetor de %d elementos",diferenca, TF);
			        ordenado=true;
					break;
			case 4: tempoi = time(NULL); // obtem o tempo inicial para cronometrar
			         selecao(vetor, TF);
			        tempof = time(NULL);
			        diferenca = difftime(tempof, tempoi);
			        printf("\n ordenou vetor e demorou %f num vetor de %d elementos",diferenca, TF);
			        ordenado=true;
					break;
			case 5:tempoi = time(NULL); // obtem o tempo inicial para cronometrar
			         insercaoDireta(vetor);
			        tempof = time(NULL);
			        diferenca = difftime(tempof, tempoi);
			        printf("\n ordenou vetor e demorou %f num vetor de %d elementos",diferenca, TF);
			        ordenado=true;
						break;

			case 6:tempoi = time(NULL); // obtem o tempo inicial para cronometrar
			        insercaoBinaria(vetor);
			        tempof = time(NULL);
			        diferenca = difftime(tempof, tempoi);
			        printf("\n ordenou vetor e demorou %f num vetor de %d elementos",diferenca, TF);
			        ordenado=true;
						break;
			case 7:tempoi = time(NULL); // obtem o tempo inicial para cronometrar
			        quicksort(vetor, 0, TF-1);
			        tempof = time(NULL);
			        diferenca = difftime(tempof, tempoi);
			        printf("\n ordenou vetor e demorou %f num vetor de %d elementos",diferenca, TF);
			        ordenado=true;
						break;
			case 8:tempoi = time(NULL); // obtem o tempo inicial para cronometrar
						heapsort(vetor, TF-1);
						tempof = time(NULL);
						diferenca = difftime(tempof, tempoi);
						printf("\n ordenou vetor e demorou %f num vetor de %d elementos",diferenca, TF);
						ordenado=true;
					break;
			case 9:tempoi = time(NULL); // obtem o tempo inicial para cronometrar
						mergeSort(vetor, 0, TF-1);
						tempof = time(NULL);
						diferenca = difftime(tempof, tempoi);
						printf("\n ordenou vetor e demorou %f num vetor de %d elementos",diferenca, TF);
						ordenado=true;
					break;
			case 10: printf("\n Exaustiva. Entre com o valor a ser procurado: ");
			        scanf("%d",&elem);
			        // tempoi
					posicao = buscaExaustiva(vetor,elem);
					// tempof
					// calcular a diferenca
					if (posicao==-1)
					   printf("\n NAO encontrou e demorou %f num vetor de %d elementos", diferenca, TF);
					   else printf("\n Demorou %f no vetor de %d elementos e encontrou na posicao vetor[%d]=%d",diferenca,TF, posicao,vetor[posicao]);
					break;
			case 11: printf("\n SEQUENCIAL exige vetor ORDENADO!!! \n Entre com o valor a ser procurado: ");
			        scanf("%d",&elem);
			        if (ordenado){
			        tempoi = time(NULL);	
					  posicao = buscaSequencial(vetor,TF, elem);
					  tempof = time(NULL);
			        diferenca = difftime(tempof, tempoi);
					  if (posicao != -1)
					     printf("\n Encontrou no vetor na posicao vetor[%d]=%d",posicao,vetor[posicao]);
					     else printf("\n NAO encontrou e demorou %f num vetor de %d elementos", diferenca, TF);
				    } 
					else printf("Vetor NAO esta ordenado \n\n");
					break;
			case 12: printf("\n BINARIA exige vetor ORDENADO!!! \n Entre com o valor a sere procurado: ");
			        scanf("%d",&elem);
			        if (ordenado){
                      // obter o tempo inicial
					  posicao = buscaBinaria(vetor,TF, elem);
					  // obter o tempo final
					  // calcular a diferenca
					  if (vetor[posicao]!=elem)
					     printf("\n NAO encontrou - posicao ideal para inserir %d ",posicao);
					     else printf("\n Encontrou no vetor na posicao vetor[%d]=%d",posicao,vetor[posicao]);
				    } else 
					    printf("Vetor NAO esta ordenado \n\n");
					break;	
			case 13: printf("\n BINARIA RECURSIVA exige vetor ORDENADO");
			  		scanf("%d",&elem);
			        if (ordenado){
			        	// tempo inicial
					  //posicao = binariaRecursiva(vetor,elem,0,TF-1);
					  // tempo final
					  // calcular a diferenca do tempo gasto
					  if (vetor[posicao]!=elem)
					     printf("\n NAO encontrou - posicao ideal para inserir %d ",posicao);
					     else printf("\n Encontrou no vetor na posicao vetor[%d]=%d",posicao,vetor[posicao]);
				    } else 
					    printf("Vetor NAO esta ordenado \n\n");
					break;				   	        		       
		}//switch
	}//while
}//main