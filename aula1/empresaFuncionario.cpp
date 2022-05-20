#include<stdio.h>
#include<string.h>
struct funcionario{
	char nome[10];
	float salario;
	int idade;
};
void carrega(struct funcionario vetor[10],int &tl){
	tl=0;
	char nome[10];
	int idade;
	float salario;
	FILE *arq = fopen("empresa.txt", "r");
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else  {
			while( !feof(arq) ){
			     fscanf(arq,"%s %f %d\n",nome,&salario,&idade);
			     strcpy(vetor[tl].nome,nome);
			     vetor[tl].salario = salario;
			     vetor[tl].idade=idade;
			     tl++;
          }
	    fclose(arq);
	}
}
void exibe(struct funcionario vetor[10], int tl){
    int i;
    printf("\nLista de Funcionarios no VETOR");
    for (i=0;i<tl;i++)
       printf("\nPosicao:%d  Nome=%s  Salario:$%5.2f  Idade:%d",i,vetor[i].nome,vetor[i].salario,vetor[i].idade);   
}
int busca(struct funcionario vetor[10],int tl,char nome[]){
	int posicao=-1;
	int i=0;
	while ((i<tl)&&(strcmp(nome, vetor[i].nome)!=0))
	        i++;
	if (i<tl)
	   posicao = i;
	   else posicao = -1;        
	return posicao;
}
void inclusao(struct funcionario vetor[10], int &tl){
	char nome[10];
	printf("\nEntre com o nome do novo funcionario:");
	scanf("%s",&nome);
	strcpy(vetor[tl].nome,nome);
	printf("\nEntre com o salario deste funcionario:");
	scanf("%f",&vetor[tl].salario);
	printf("\nEntre com a idade deste funcionario:");
	scanf("%d",&vetor[tl].idade);
	tl++;
}
void regravar(struct funcionario vetor[10], int tl){
	FILE *arq = fopen("empresa.txt","w");
	int i;
	for (i=0;i<tl;i++)
	   fprintf(arq,"%s %f %d\n",vetor[i].nome,vetor[i].salario,vetor[i].idade);
	fclose(arq); 
	printf("\n Regravado o arquivo texto EMPRESA.TXT");  
}

void remover() {
	
}

main(){
	int opcao=0;
	struct funcionario vetor[10];
	// uma unica posi��o do vetor tem nome, salario e idade
	int tl=0, posicao;
	char nome[10];
	while (opcao!=7){
		printf("\n\n1 - Leitura do arquivo texto para carregar o vetor");
		printf("\n2 - Exibe o vetor na memoria principal");
		printf("\n3 - Consulta um funcionario (busca) no vetor");
		printf("\n4 - Inclusao de um novo funcionario no vetor - memoria principal");
		printf("\n5 - Remocao de um funcionario no vetor");
		printf("\n6 - Regravar o arquivo texto- grava no HD ");
		printf("\n7 - Sair");
		printf("\n Opcao:"); scanf("%d",&opcao);
		switch (opcao) {
			case 1: carrega(vetor,tl);
			        printf("\nVetor carregado com tl=%d funcionarios", tl);
			        break;
			case 2: exibe(vetor,tl);
			        break; 
			case 3: printf("\n Entre com o nome a ser procurado: ");
			        scanf("%s",&nome);
					posicao = busca(vetor, tl, nome);
					if (posicao==-1)
					   printf("\n Nao encontrou");
					   else printf("\n Encontrou na posicao %d nome:%s  salario:$%5.2f",posicao,nome,vetor[posicao].salario);
					break;
			case 4: inclusao(vetor,tl);
			        break;
			case 5: printf("\n faca voce a remocao como exercicio");
			        break;        
			case 6: regravar(vetor,tl);
			        break;		   		       
		}
		
	}
}
