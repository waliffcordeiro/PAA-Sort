#include <iostream>

// Waliff Cordeiro Bandeira - 17/0115810

using namespace std;

int insertionSort(int vetor[], int n);

int main() {
	int qtd_vetores, qtd_elementos;
	int numero_alteracao[5]; // Definindo vetor com quantidade máxima de resultados
	int vetor[100000]; // Definindo vetor com tamanho máximo

	scanf("%d",&qtd_vetores);

	while(qtd_vetores--) { // Quantidade de iterações de acordo com o primeiro input
		scanf("%d",&qtd_elementos);
		
        for(int j=0 ; j<qtd_elementos; j++) { // Quantidade de elementos de cada vetor
			scanf("%d", &vetor[j]); // Input de cada lista	
		}
		cout << insertionSort(vetor, qtd_elementos) << "\n";
	}
}

// Pega cada elemento e já coloca na ordem correta
int insertionSort(int vetor[], int n)
{
   int aux, pos, cont=0;
   for (int i = 1; i < n; i++) {
       aux = vetor[i];

       // Pega a posição e compara todo mundo
       for (pos = i-1; pos >= 0 && (vetor[pos] > aux); pos-- ) {
           // Move o elemento menor uma casa para frente
           // Abrindo espaço para inserir o elemento avaliado
           vetor[pos+1] = vetor[pos];
           cont++; // Quantidade de trocas(swaps) realizadas
       }
       // Quando o valor analisado for menor que o salvo na auxiliar
       // Iremos atribuir, pois é a posição correta
       vetor[pos+1] = aux; 
   }
   return cont;
}