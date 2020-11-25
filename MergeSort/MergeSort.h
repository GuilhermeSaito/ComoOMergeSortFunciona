#ifndef MERGE_SORT
#define MERGE_SORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 6

typedef struct Vetor
{
    int tam;
    int espaco;
    int *vec;
} Vector;

Vector *createVector(int tamanho);
void addElement(Vector *v, int elem);
void listarElementos(Vector *v);
int cheio(Vector *v);
void MergeSort(Vector *v, int left, int right);
void IrJuntando(Vector *v, int left, int midle, int right);
void swap(Vector *v, int i, int j);
int verificarOrdenacao(Vector *v);
void liberarVector(Vector *v);

#endif