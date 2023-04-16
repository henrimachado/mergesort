#include <iostream> //biblioteca padrão do c++
#include <locale>   //biblioteca para a localização da linguagem
#include <fstream>  //biblioteca para arquivo
#include <ctime>    //biblioteca para a semente do tempo
#include <cstdlib>  //biblioteca para a função rand

using namespace std;

void merge(int array[], int start, int middle, int end, int n); // Junção dos termos após ordenados
void mergesort(int array[], int start, int end, int n);         // Função principal e recursiva
void write(int array[], int n, int type);

int main()
{

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL)); // Time seed para garantir que a cada execução do programa o array gerado seja diferente

    int n;

    // Construção do array

    cout << "\nMÉTODOS DE ORDENAÇÃO - MERGESORT\n"
         << "\n----------------------------------------------------\n\n"
         << "Quantos números você deseja ordernar? ";
    cin >> n;
    cout << "\n----------------------------------------------------\n\nSeu arquivo foi gerado e pode ser acessado no mesmo\ndiretório em que este programa se encontra.\n\nPor motivos de organização, os números escolhidos\npertencem ao intervalo [-200, 200]\n\n";

    int array[n];

    // Construção do array com valores aleatórios
    for (int p = 0; p < n; p++)
    {
        array[p] = (rand() % 401) - 201; // rand()%limite | Foram utilizados valores para controlar o intervalo, de forma que irá escolher valores entre -200 e 200.
    }

    cout << "\n\n";

    write(array, n, 1); // Escreve o array desordenado no arquivo segundo o parâmetro Type 1

    mergesort(array, 0, (n - 1), n); // Aplica o método mergesort

    write(array, n, 2); // Escreve o array ordenado no arquivo segundo o parâmetro Type = 2

    return 0;
}

void merge(int array[], int start, int middle, int end, int n)
{

    int in_left, in_right, in_aux;

    in_left = start;       // indice de posição da esquerda
    in_right = middle + 1; // indice de posição da direita
    in_aux = start;        // índice de posição do array auxiliar

    int aux[n]; // array auxiliar

    while (in_left <= middle && in_right <= end)
    {

        if (array[in_left] <= array[in_right]) // elemento da esquerda é menor que o da direita
        {
            aux[in_aux] = array[in_left];
            in_left++;
            in_aux++;
        }

        else // Elemento da direita é maior que o da esquerda
        {
            aux[in_aux] = array[in_right];
            in_right++;
            in_aux++;
        }
    }

    while (in_left <= middle) // Organiza os elementos restantes da porção à esquerda
    {
        aux[in_aux] = array[in_left];
        in_left++;
        in_aux++;
    }

    while (in_right <= end) // Organiza os elementos restantes da porção à direita
    {
        aux[in_aux] = array[in_right];
        in_right++;
        in_aux++;
    }

    for (int k = start; k <= end; k++) // Substitui o array original pelo array ordenado
    {
        array[k] = aux[k];
    }
}
void mergesort(int array[], int start, int end, int n)
{

    if (start < end)
    {
        int middle = ((start + end) / 2);
        mergesort(array, start, middle, n);
        mergesort(array, middle + 1, end, n);
        merge(array, start, middle, end, n);
    }
}
void write(int array[], int n, int type)
{

    /* Tipos:
    O parâmetro type é para distinguir se se trata da escrita do array ordenado ou desordenado.
    Type == 1 | Vetor desordenado
    Type == 2 | Vetor ordenado */

    if (type == 1)
    {
        ofstream output;
        output.open("Merge Sort.txt", ios::trunc);

        output << "MÉTODOS DE ORDENAÇÃO - MERGESORT\n--------------------------------------------\n\n";
        output << "OS NÚMEROS DESORDENADOS SÃO: \n[";

        for (int i = 0; i < n; i++)
        {
            if (i == (n - 1))
            {
                output << array[i];
            }
            else
            {
                output << array[i] << ", ";
            }
        }
        output << "]\n\n-------------------------------------------\n\n";
        output.close();
    }

    else
    {
        ofstream output;
        output.open("Merge Sort.txt", ios::app);

        output << "\n";
        output << "OS NÚMEROS ORDENADOS SÃO: \n[";

        for (int j = 0; j < n; j++)
        {
            if (j == (n - 1))
            {
                output << array[j];
            }
            else
            {
                output << array[j] << ", ";
            }
        }

        output << "]\n\n-------------------------------------------\n\n";
        output.close();
    }
}