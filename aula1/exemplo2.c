#include <stdio.h>;
#include <stdlib.h>;

void main() { 

FILE *f = fopen("teste.txt", "r");
int i;
while(!feof(f)) {
        fscanf(f, "%d", &i);
        printf("%d\n", i);
    }
    fclose(f); 
}
