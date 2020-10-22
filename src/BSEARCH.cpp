#include <bits/stdc++.h> 

using namespace std; 

// Waliff Cordeiro Bandeira - 17/0115810

int pesquisaBinaria(long long int vetor[],long long int query, int tamanho);

int main()
{
    /* ---------- Dados de entrada ---------- */
    int qtd_elementos, qtd_queries;
    scanf("%d%d", &qtd_elementos, &qtd_queries);
    long long int indices[qtd_elementos];
    for(int i=0; i < qtd_elementos; i++)
    {
        scanf("%lld",&indices[i]);
    }
    /* --------------------------------------- */

    while(qtd_queries--)
    {
        long long int query;
        scanf("%lld",&query);
        int resposta = pesquisaBinaria(indices, query, qtd_elementos);
        
        // Caso de erro
        if(resposta == -1) {
            printf("-1\n");
        }
        // Caso de sucesso
        else {
            printf("%d\n", resposta);
        }
    }
    return 0;
}  

int pesquisaBinaria(long long int vetor[],long long int query, int tamanho)
{
    int inicio = 0; // Primeira posição do vetor de índices
    tamanho = tamanho-1; // Última posição do vetor de índices
    int resposta = -1;

    while(inicio <= tamanho) {
        int meio = (inicio + tamanho)/2;

        if(vetor[meio] == query) {
            // Encontrou a resposta e atualizou a nova parte 'tamanho' do vetor
            resposta = meio;
            tamanho = meio - 1; // Uma posição antes do elemento encontrado
        }

        // Diminuindo os intervalos de busca

        else if(vetor[meio] > query) {
            // O valor procurado está na esquerda do vetor[meio]
            // Portanto o valor procurado estará em meio-1 ou posições anteriores
            tamanho = meio - 1; 
        }
        else {
            // O valor procurado está na direita do vetor[meio]
            // Portanto o início do vetor pode ignorar as posições anteriores a meio + 1
            inicio = meio + 1;
        }
    }
    return resposta;
}