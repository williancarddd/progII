// quicksort sem pivo

#define TF 7
#define MAX 40

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void cria(int vetor[TF])
{
  for (int i = 0; i < TF; i++)
  {
    vetor[i] = rand() % MAX;
  }
}

void exibe(int vetor[TF])
{
  int i;
  for (i = 0; i < TF; i++)
    printf(" %3d ", vetor[i]);
  // getchar();
}

void troca(int *a, int *b) {
  // função para facilitar a troca
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int p, int r) {
  int x = array[r];
  int i = (p - 1);
  for (int j = p; j < r; j++) {
    if (array[j] <= x) {
      i++;
      troca(&array[i], &array[j]);
    }
  }
  troca(&array[i + 1], &array[r]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

main()
{
  int vetor[TF];
  srand(time(NULL));
  cria(vetor);
  exibe(vetor);
  printf("\n----------------------------------------------------\n");
  printf("\n");
  quickSort(vetor, 0, TF - 1);
  exibe(vetor);
}