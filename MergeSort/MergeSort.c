#include "MergeSort.h"

Vector *createVector(int tamanho)
{
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->tam = tamanho;
    v->espaco = 0;
    v->vec = (int *)malloc(sizeof(int) * tamanho);
    return v;
}

void addElement(Vector *v, int elem)
{
    if (cheio(v))
    {
        printf("Vetor cheio!\n");
        exit(1);
    }
    v->vec[v->espaco] = elem;
    v->espaco++;
}

void listarElementos(Vector *v)
{
    for (int i = 0; i < v->espaco; i++)
        printf("Elemento: %d\n", v->vec[i]);
    printf("\n");
}

int cheio(Vector *v)
{
    return (v->tam - 1) == v->espaco;
}

/*
    Basicamente vai fazer um negocio assim:
    Vetor: [[0], [2], [5], [3], [4], [1]]
    // Chamou o 1 MergeSort:           
    [[0], [2], [5]]
    [[0], [2]]      [5]
    [0]   [2]     [5]
    // Chamou o IrJuntando:
    [[0], [2]]
    [[0], [2], [5]]
    // Chamou o 2 MergeSort:
    [[3], [4], [1]]
    [[3], [4]]      [1]
    [3]   [4]     [1]
    // Chamou o IrJuntando:             <- Como ja tinha os elementos do outro IrJuntando, 
    [[0], [2], [5], [3], [4]]    [1]       ele simplesmente vai adicionando os outros do lado
    [[0], [2], [5], [1], [3], [4]]         Para, por fim, 
    [[0], [1], [2], [3], [4], [5]]         Arrumar tudo!!
*/
void MergeSort(Vector *v, int left, int right)
{
    // Toda vez que chama o MergeSort, eh para Dividir o vetor, ateh ficar com 1 casinha somente,
    // Por isso tem essa condicao, pois fica com 1 casinha, quando left == right.
    if (left < right)
    {
        int q = (left + right) / 2;
        // Vai realizar esse 1 MergeSort, terminando ele, FAZ O IrJuntando.
        MergeSort(v, left, q);
        // DEPOIS QUE FAZER esse IrJuntando, efetuado depois do 1 MergeSort, q vai chamar esse 2
        // MergeSort e Por fim, o IrJuntando.
        MergeSort(v, q + 1, right);
        IrJuntando(v, left, q, right);
    }
}

// A ideia dessa funcao vai ser chamada quando tiver somente 1 casinha de vetor em cada e ir
// juntando ateh formar o vetor inteiro.
// Vai criar 2 vetores auxiliares, que 1 vai representar do left ateh o meio.
// e o outr vai ir do meio + 1 ateh o left, depois vai comparando os 2 para ver qual eh menor
// e vai encaixando de volta no vetor passado por referencia (v).
// Caso sobre algum elemento nos vetores temporarios, eles vao passar para o vetor principal
// em qualquer ordem
void IrJuntando(Vector *v, int left, int midle, int right)
{
    // i para VetorTemp1, j para VetorTemp2, k para v;
    int i, j, k;
    int tamanhoVetorTemp1 = ((midle - left) + 1);
    int tamanhoVetorTemp2 = (right - midle);

    // VetorTemp1 = Left ateh middle - 1
    int vetorTemp1[tamanhoVetorTemp1];
    // VetorTemp2 = middle ateh right
    int vetorTemp2[tamanhoVetorTemp2];

    // Colocando os elementos do inicio ateh o meio - 1
    for (i = 0; i < tamanhoVetorTemp1; i++)
        vetorTemp1[i] = v->vec[i + left];
    for (j = 0; j < tamanhoVetorTemp2; j++)
        vetorTemp2[j] = v->vec[j + 1 + midle];

    for (k = left, i = 0, j = 0; (i < tamanhoVetorTemp1) && (j < tamanhoVetorTemp2); k++)
    {
        if (vetorTemp1[i] <= vetorTemp2[j])
        {
            v->vec[k] = vetorTemp1[i];
            i++;
        }
        else
        {
            v->vec[k] = vetorTemp2[j];
            j++;
        }
    }

    while (i < tamanhoVetorTemp1)
    {
        v->vec[k] = vetorTemp1[i];
        k++;
        i++;
    }
    while (j < tamanhoVetorTemp2)
    {
        v->vec[k] = vetorTemp2[j];
        k++;
        j++;
    }
}

void swap(Vector *v, int i, int j)
{
    int aux = v->vec[i];
    v->vec[i] = v->vec[j];
    v->vec[j] = aux;
}

// Se for verdadeiro, deu certo, se nao, deu errado
int verificarOrdenacao(Vector *v)
{
    for (int i = 0; i < v->espaco - 1; i++)
        if (v->vec[i] > v->vec[i + 1])
        {
            printf("Ordenacao Errada!!\n");
            return 0;
        }
    printf("Ordenacao Correta :D\n");
    return 1;
}

void liberarVector(Vector *v)
{
    free(v->vec);
    free(v);
}