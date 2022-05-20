#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct contato
{
  char nome[10];
  char telefone[10];
};


void carrega(struct contato vetor[10],int &tl){
	tl=0;
	char nome[10];
	char telefone[10];
	FILE *arq = fopen("agenda.txt", "r");
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else  {
			while( !feof(arq) ){
			     fscanf(arq,"%s %s\n",nome , telefone);
			     strcpy(vetor[tl].nome,nome);
			     strcpy(vetor[tl].telefone,telefone);
			     tl++;
          }
	    fclose(arq);
	}
}
void inclusao(struct contato vetor[10], int &tl){
  char nome[10];
  char telefone[10];
  printf("\nEntre com o nome do novo contato:");
  scanf("%s",&nome);
  strcpy(vetor[tl].nome,nome);
  printf("\nEntre com o telefone deste contato:");
  scanf("%s",&telefone);
  strcpy(vetor[tl].telefone,telefone);
  tl++;
  printf("\n O %s foi incluido na agenda", nome);

}
int busca(struct contato vetor[10],int tl,char nome[]){
	int posicao=-1;
	int i=0;
	while ((i<tl)&&(strcmp(nome, vetor[i].nome)!=0))
	        i++;
	if (i<tl)
	   posicao = i;
	   else posicao = -1;        
	return posicao;
}

void remocao(struct contato vetor[10], int posicao, int &tl){
  int i;
  for (i=posicao;i<tl-1;i++)
    vetor[i]=vetor[i+1];
  tl--;
}
void exibe(struct contato vetor[10], int tl){
    int i;
    printf("\nLista de Funcionarios no VETOR");
    for (i=0;i<tl;i++)
       printf("\n Posicao Lista:%d  Nome=%s Telefone=%s ",i,vetor[i].nome,vetor[i].telefone);   
}

void regravar(struct contato vetor[10], int tl){
	FILE *arq = fopen("agenda.txt","w");
	int i;
	for (i=0;i<tl;i++)
	   fprintf(arq,"%s %s\n",vetor[i].nome,vetor[i].telefone);
	fclose(arq); 
	printf("\n Regravado o arquivo texto AGENDA.TXT");  
}
int main() {
  struct contato vetor[10];
  int tl, opcao, posicao;
  //carrega o vetor de contatos
  carrega(vetor,tl);
  while (opcao!=7){
    printf("\n1 - Inclusao ");
    printf("\n2 - Remocao ");
		printf("\n3 - Buscar");
		printf("\n4 - Exibe o vetor na memoria principal");
		printf("\n5 - Sair");
		printf("\n Opcao:"); scanf("%d",&opcao);
		switch (opcao) {
			case 1:
      printf("\n Inclusao de um novo contato.");
        inclusao(vetor,tl);
      printf("\n agora ha %d contatos.",tl);
			        break;
			case 2: 
              printf("\n Remocao de um contato.");
              printf("\n Entre com o nome do contato a ser removido:");
              char nome[10];
              scanf("%s",&nome);
              posicao = busca(vetor, tl, nome);
              if (posicao!=-1){
                remocao(vetor, posicao, tl);
                printf("\n agora ha %d contatos.",tl);
              }
              else printf("\n Contato nao encontrado.");
			        break; 
			case 3:
          printf("\n Busca de um contato.");
          printf("\n Entre com o nome do contato a ser buscado:");
          char nome2[10];
          scanf("%s",&nome2);
          posicao = busca(vetor, tl, nome2);
          if (posicao!=-1){
            printf("\n Contato encontrado na posicao  %d.", tl);
            printf("\n Nome: %s",vetor[posicao].nome);
            printf("\n Telefone: %s",vetor[posicao].telefone);
          }
          else printf("\n Contato nao encontrado.");

					break;
			case 4:
              exibe(vetor, tl);
			        break;
			case 5: 
              printf("\n contatos gravados.");
              printf("\n Saindo...");
              regravar(vetor, tl);
              exit(0);
			        break;        		   		       
		}
		
	}
  return 0;
}