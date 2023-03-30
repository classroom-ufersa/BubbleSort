#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

typedef union documento{
    int CPF;
    int RG;
} Documento;

typedef struct aluno{
    char nome[100];
    int mat;
    Documento d;
} Aluno;

void OrdenaAlunos(int n, Aluno *vetor)
{
    int i, j, recebe_comparacao; // Variáveis de contagem "i" e "j". Variável utilizada para ordenar strings, quando o usuário deseja ordenar por nomes "rebebe_comparacao"
    char guarda_string[100]; // Variável usada para guardar temporarialente o nome dos alunos no Bubble Sort

    // Laço de repetição usado para ordenar o vetor de acordo com o campo selecionado, neste caso, os nomes dos alunos
    for (i = 0; i < n; i++) // acessa o primeira posição do vetor aluno // n
    { 
        for (j = i + 1; j < n; j++) // acessa uma posição adiante do vetor // n - 1
        { 
            /* Atribuindo o valor da função strcmp à variável que auxilia na troca das strings.
            A função strcmp retorna 3 valores, 1, 0 e -1, mas neste caso, não estamos comparando
            se as strings sao maiores em questão de quantidade de caracteres, mas sim, em relação ao código ascii */
            recebe_comparacao = strcmp(vetor[i].nome, vetor[j].nome); // compara se "vetor[i].nome" e maior que "vetor[j].nome" // "c1
            
            /* A função strcmp devolve um valor inteiro que indica o relacionamento entre vetor[i].nome e vetor[j].nome:
            Um valor menor que zero significa que vetor[i].nome é menor que vetor[j].nome. Um valor zero significa que ambas as 
            strings são iguais. Um valor maior que zero significa que vetor[i].nome é maior que vetor[j].nome. */

            /* Estrutura de decisão "if" que realiza a ordenação caso a comparação feita anteriormente retorne valores maiores que 0,
            sinalizando que a primeira string é menor que a segunda em relação aos valores dos caracteres na tabela ascii */
            if (recebe_coomparacao > 0) // c2
            { 
                strcpy(guarda_string, vetor[i].nome); // copia a string de vetor[i].nome para a variável guarda_string // c3
                strcpy(vetor[i].nome, Vet[j].nome); // copia de vetor[j].nome pra o vetor[i].nome // c4
                strcpy(vetor[j].nome, guarda_string); // copia de guarda_string pra o vetor[j].nome // c5
            }
        }
    }
}

/*

Complexidade da função "OrdenaAlunos" - Bubble Sort

Pior caso:

T(O) = n * n-1 + c1 + c2 + c3+ c4 + c5
T(O) = n * (n-1) + C
T(O) = n² 

O(n²)

Caso médio:

T(O) = n * n-1 + c1 + c2 + c3+ c4 + c5
T(O) = n * (n-1) + C
T(O) = n² 

O(n²)

Melhor caso:

T(O) = n + n-1 + c1 + c2 + c3+ c4 + c5
T(O) = n + n-1 + C
T(O) = n

O(n)

*/

Aluno *AlocaAlunos(int numero_alunos)
{
    int i, op; // Variável de contagem e outra que guarda a opção escolhida pelo usuário
    
    Aluno *vetor = (Aluno*)malloc(numero_alunos * sizeof(Aluno));
    if(p==NULL)
    {
        printf("Erro!");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        printf("\nDigite o nome do aluno %i: ", i+1);
        scanf("%s", vetor[i].nome);
        printf("\nDigite a matricula: ");
        scanf("%i", &vetor[i].mat);
        printf("\nDeseja registrar o (1)CPF ou o (2)RG: ");
        scanf("%i", &op);
        if (op == 1)
        {
            printf("\nDigite o CPF: ");
            scanf("%d", &vetor[i].d.CPF);  
        }
        else if (op == 2)
        {
            printf("\nDigite O RG: ");
            scanf("%d", &vetor[i].d.RG); 
        }  
    }
    return p; // Retorna os dados inseridos pelo usuário
}

void ImprimeAluno(int n, Aluno *vetor, FILE *arch)
{
    int i; // Variavel de contagem

    // Laço de repetição que imprime os dados dos alunos que foram cadastradas pelo usuario no terminal
    for (i = 0; i < n; i++){
        printf("\nNome: %s", vetor[i].nome);
        printf("\nMatricula: %d", vetor[i].mat);
        printf("\nDocumento(s): CPF - %d RG - %d\n", vetor[i].d.CPF, vetor[i].d.RG);
    }
    
    // Laço de repetição que imprime os dados dos alunos que foram cadastradas pelo usuario no arquivo
    for (i = 0; i < n; i++) 
    {
        fprintf(arch, "Nome: %s\nMatricula: %i\nDocumento(s): CPF - %d RG - %d\n\n", vetor[i].nome, vetor[i].mat, vetor[i].d.CPF, vetor[i].d.RG);   
    }
}
