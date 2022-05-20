#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct funcionario{
	char nome[10];
	float salario;
	int idade;
};
void carrega(struct funcionario vetor[20], int &tl){
	FILE *fp = fopen("empresa.txt","r");
	if (fp==NULL){
		printf("\n nao encontrou o arquivo empresas.txt");
		exit(0);
	}
	else
	{
		char nome[10];
		float salario;
		int idade;
		int tl2 =0;
		while (!feof(fp)){
			fscanf(fp,"%s %f %d\n",nome,&salario,&idade);
			strcpy(vetor[tl2].nome,nome);
			vetor[tl2].salario=salario;
			vetor[tl2].idade = idade;
			tl2++;
		}
		*tl = tl2;
		fclose(fp);
	}
}
void exibe(struct funcionario vetor[20],int tl){
	int i;
	for (i=0;i<tl;i++){
		printf("\n Nome:%s  Salario:%5.2f   Idade:%d",vetor[i].nome,
		                                              vetor[i].salario,
													  vetor[i].idade);
	}
}

void buscar(struct funcionario vetor[20], int tl, char nome[10]) {
	int i = 0;
	while ((i< tl)&&(strcmp(vetor[i].nome, nome) != 0))
		i++;
	if(i<tl){
		printf("\Encontrou o nome %s com salario=%5.2f e idade %d" , nome, vetor[i].salario, vetor[i].idade);
	} else {
		printf("\n nao encontrou o nome fornecido");
	}
}

void inclusao(struct funcionario vetor[20], int tl) {
	struct funcionario novo;
	printf("entre com o nome do novo funcionario: ");
	scanf("%s", novo.nome);
	printf("entre com o salario do novo funcionario: ");
	scanf("%s", &novo.salario);
	printf("entre com a idade do novo funcionario: ");
	scanf("%s", &novo.idade);
	tl++;
	vetor[tl] = novo;
}

void regravar() {
	
}
main(){
	struct funcionario vetor[20];
	int tl= 0;
	int opcao=0;
	while (opcao != 4){
		printf("\n1 - Leitura do arq texto e carrega o vetor funcionarios");
		printf("\n2 - exibe o vetor de funcionarios");
		printf("\n3 - busca um funcion�rio no vetor pelo nome");
		printf("\n4 - inclusao de um funcionario no vetor");
		printf("\n5 - remocao de um funcionario no vetor");
		printf("\n6 - regravar o vetor no arquivo texto apos alteracoes");
		printf("\n7 - sair");
		printf("\nopcao: ");
		scanf("\n%d",&opcao);
		switch(opcao){
			case 1: carrega(vetor,tl);
			        printf("\n fez a leitura do arq texto e armazenou no vetor\n\n");
			        break;
			case 2: exibe(vetor,tl);
			        printf("\n ja exibiu os funcionarios do vetor\n\n");
					break;
			case 3: printf("entre com o nome a ser procurado: ");
					char nome[10];
					scanf("%s", nome);
					buscar(vetor, tl, nome);
					break;
			case 4: inclusao(vetor, tl);
					break;
			case 5: //remocao
					break;
			case 6: regravar(vetor, tl);
			printf("as alteracoes foram salvas");
			break;
		}
	}
	
	
	
}
