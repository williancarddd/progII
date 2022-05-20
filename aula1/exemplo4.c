#include <stdlib.h>
#include <stdio.h>

void main() {
    char nome[20]; 
    float nota1, nota2, nota3; 
    FILE *arq = fopen("notas.txt", "r"); 
    if(arq == NULL) 
        printf("Erro, nao foi possivel abrir o arquivo\n"); 
    else { 
        while( !feof(arq) ){ 
        fscanf(arq,"%s %f %f %f\n", nome, &nota1, &nota2, &nota3); 
        float media = (nota1 + nota2 + nota3) /3; 
        printf("%s obteve media %.2f\n", nome, media); 
    } 
    fclose(arq); 
    } 
    getchar();
}