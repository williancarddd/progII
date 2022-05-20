#include <stdio.h>;
#include <stdlib.h>;

void main() {
    FILE *fp;
    fp = fopen("listatelefone.txt", "r");
    if(!fp) {
        printf("erro na abertura do arquivo de texto.");
        exit(0);
    } else {
        char  fone[10];
        while(!feof(fp)) {
    
            fscanf(fp, "%s", fone);
            printf("%s\n", fone);
        }
        fclose(fp);
    };
};