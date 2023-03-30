#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.c"
#include <time.h>

int main()
{
    clock_t inicio = 0, fim; // Variáveis para a contagem do tempo do algoritmo
    double tempo_execucao; // Variável para guardar o tempo de execução do algoritmo
    int numero_alunos; // Variável para armazenagem da quantidade de alunos cadastradas
    
    FILE *arquivo = fopen("ListaDeAlunos.txt", "w"); // Abre e cria um arquivo no modo "write" (escrita)

    // Analisa se o arquivo foi  criado ou não
    if(arquivo != NULL){ 
        printf("\nArquivo criado!\n");
    }
    else if(arquivo == NULL){
        printf("\nProblema ao criar o arquivo!\n");
    }

    printf("\nInforme a quantidade de alunos a serem cadastradas: ");
    scanf("%d", &numero_alunos); // Lendo a quantidade de pessoas que serão cadastradas
    
    // Criação de um ponteiro "p" e alocação de um vetor struct "Aluno" por meio da função "AlocaAluno"
    Aluno* vetor_alunos = AlocaAlunos(numero_alunos);

    OrdenaAlunos(numero_alunos, vetor_alunos); // Implementação do Bubble Sort
    ImprimeAluno(numero_alunos, vetor_alunos, arquivo); // Imprime dados dos alunos no terminal e no arquivo criado

    fclose(arquivo); // Fecha o arquivo criado
    free(vetor_alunos); // Liberando espaço alocado dinamicamente da struct "Aluno" e consequentemente de "Documentos"

    fim = clock(); // "fim" recebe o tempo de execução
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC; // "tempo_execucao" recebe o resultado da divisão entre tempo "inicio" e tempo "fim"
    printf("\nTempo de execucao: %f segundos\n\n", tempo_execucao); // Amostragem do tempo de execução
        
    return 0;
}