#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void printando_vetor(vector<int> vetor);
void mergeSort(vector<int> &vetor, int inicio, int final);
void merge(vector<int> &vetor, int inicio, int meio, int final);

// Waliff Cordeiro Bandeira - 17/0115810

int main() {
    vector<int> vetor_ordenar;
    string linha_entrada;
    
    // Pegando a linha (vetor de entrada)
    getline(cin, linha_entrada);
    
    // Cast para fazer o vetor de inteiros
    istringstream linha_inteiros(linha_entrada);
    
    int elemento;
    while(linha_inteiros >> elemento)
        // Pegando cada elemento e inserindo no vetor de ordenação
        vetor_ordenar.push_back(elemento);
    
    // Ordenando e printando
    mergeSort(vetor_ordenar, 0, static_cast<int>(vetor_ordenar.size() - 1));
    printando_vetor(vetor_ordenar);

    return 0;
}

void mergeSort(vector<int> &vetor, int inicio, int fim) {
    if (inicio < fim) {
        // Pegando a posição central
        int meio = (inicio + fim) / 2;
        
        // Chamando a função de forma recursiva
        mergeSort(vetor, inicio, meio); // Primeira parte do vetor
        mergeSort(vetor, meio + 1, fim);  // Segunda parte do vetor

        // Unindo as duas partes
        merge(vetor, inicio, meio, fim);
    }
}

// Unindo os dois subarrays (subvetores)
void merge(vector<int> &vetor, int inicio, int meio, int final) {

    std::vector<int> vetorEsquerda(meio - inicio + 1);
    std::vector<int> vetorDireita(final - meio);

    // Preenchendo o vetor da esquerda
    for (int i = 0; i < vetorEsquerda.size(); ++i)
        vetorEsquerda[i] = vetor[inicio + i];

    // Preenchendo o vetor da direita
    for (int i = 0; i < vetorDireita.size(); ++i)
        vetorDireita[i] = vetor[meio + 1 + i];

    /* Unindo os vetores temporários */

    // index inicial dos subvetores
    int indexEsquerda = 0, indexDireita = 0;

    // index para adicionar os subvetores no vetor principal
    int indexAtual = inicio;

    // Comparando os índices dos vetores e adicionando o menor valor ao index atual
    while (indexEsquerda < vetorEsquerda.size() && indexDireita < vetorDireita.size()) {
        if (vetorEsquerda[indexEsquerda] <= vetorDireita[indexDireita]) {
            vetor[indexAtual] = vetorEsquerda[indexEsquerda];
            indexEsquerda++;
        } else {
            vetor[indexAtual] = vetorDireita[indexDireita];
            indexDireita++;
        }
        indexAtual++;
    }

    // Copia os vetores remanescentes da esquerda (se houver)
    while (indexEsquerda < vetorEsquerda.size()) vetor[indexAtual++] = vetorEsquerda[indexEsquerda++];

    // Copia os vetores remanescentes da direita (se houver)
    while (indexDireita < vetorDireita.size()) vetor[indexAtual++] = vetorDireita[indexDireita++];
}

void printando_vetor(vector<int> vetor) {
    int i;
    for(i = 0; i < vetor.size()- 1 ; i++) {
        // Pegando o size-1 para printar o último elemento sem espaço após o for
        cout<<vetor[i]<<' '; 
    }
    cout<<vetor[i];
}