#include "MergeSort.h"

/*
    Complexidade do Deck Sort:
        Como 2 fors, um dentro do outro, resulta em um O(n) * O(n) = O(n^2)

    Do Deck Sort, ele sempre verifica um n - 1, portanto eh:
        O(n) * O(n - 1) = O(n^2 - n)            <---- O que eh O(n^2).
*/

int main()
{
    srand(time(NULL));
    clock_t start, end;

    Vector *v = createVector(TAM + 1);

    for (int i = 0; i < TAM; i++)
        addElement(v, rand() % 8);

    listarElementos(v);

    start = clock();
    MergeSort(v, 0, v->espaco - 1);
    end = clock();

    printf("\n\n");
    listarElementos(v);
    if (verificarOrdenacao(v))
        printf("Tempo de Execucao do Deck Sort: %lf\n", (end - start) / (double)CLOCKS_PER_SEC);

    liberarVector(v);

    return 0;
}