#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.c"
#include <time.h>

int main()
{
    clock_t inicio = 0, fim; // Variáveis para a contagem do tempo do algoritmo
    double tempo_execucao; // Variável para guardar o tempo de execução do algoritmo
    int n; // Variável para armazenagem da quantidade de alunos cadastradas
    
    FILE *arch = fopen("ListaDeAlunos.txt", "w"); // Abre e cria um arquivo no modo "write" (escrita)

    // Análize se o arquivo foi  criado ou não
    if(arch != NULL){ 
        printf("\nArquivo criado!\n");
    }
    else if(arch == NULL){
        printf("\nProblema ao criar o arquivo!\n");
    }

    printf("\nInforme a quantidade de alunos a serem cadastradas: ");
    scanf("%i", &n); // Lendo a quantidade de pessoas que serão cadastradas
    
    // Criação de um ponteiro "p" e alocação de um vetor struct "Aluno" por meio da função "AlocaAluno"
    Aluno* p= AlocaAlunos(n);

    OrdenaAlunos(n, p); // Iplementação do Bubble Sort
    ImprimeAluno(n, p, arch); // Imprime dados dos alunos no terminal e no arquivo criado

    fclose(arch); // Fecha o arquivo criado
    free(p); // Liberando espaço alocado dinamicamente da struct "Aluno" e consequentemente de "Documentos"

    fim = clock(); // "fim" recebe o tempo de execução
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC; // "tempo_execucao" recebe o resultado da divisão entre tempo "inicio" e tempo "fim"
    printf("\nTempo de execucao: %f segundos\n\n", tempo_execucao); // Amostragem do tempo de execução
        
    return 0;
}