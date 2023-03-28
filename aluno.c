#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

struct documento{
    int CPF;
    int RG;
};

struct aluno{
    char nome[100];
    int mat;
    Documento d;
};

void OrdenaAlunos(int n, Aluno *Vet)
{
    int i, j, r; // Variáveis de contagem "i" e "j". Variável utilizada para ordenar strings, quando o usuário deseja ordenar por nomes "r"
    char temp[100]; // Variável usada para guardar temporarialente o nome dos alunos no Bubble Sort

    // Laço de repetição usado para ordenar o vetor de acordo com o campo selecionado, neste caso, os nomes dos alunos
    for (i = 0; i < n; i++) // n-1
    { 
        for (j = i + 1; j < n; j++) // n-1
        { 
            /* Atribuindo o valor da função strcmp à variável que auxilia na troca das strings.
            A função strcmp retorna 3 valores, 1, 0 e -1, mas neste caso, não estamos comparando
            se as strings sao maiores em questão de quantidade de caracteres, mas sim, em relação ao código ascii */
            r = strcmp(Vet[i].nome, Vet[j].nome); // c1

            /* Estrutura de decisão "if" que realiza a ordenação caso a comparação feita anteriormente retorne valores maiores que 0,
            sinalizando que a primeira string é menor que a segunda em relação aos valores dos caracteres na tabela ascii */
            if (r > 0) // c2
            { 
                strcpy(temp, Vet[i].nome); // c3
                strcpy(Vet[i].nome, Vet[j].nome); // c4
                strcpy(Vet[j].nome, temp); // c5
            }
        }
    }
}

/*

Complexidade da função "OrdenaAlunos" - Bubble Sort

T(O) = n-1 + n-1 + c1 + c2 + c3+ c4 + c5
T(O) = n² + 2n + C
T(O) = n² 

*/

Aluno *AlocaAlunos(int n)
{
    int i, op; // Variável de contagem e outra que guarda a opção escolhida pelo usuário
    
    Aluno *p = (Aluno*)malloc(n * sizeof(Aluno));
    if(p==NULL)
    {
        printf("Erro!");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        printf("\nDigite o nome do aluno: ");
        scanf("%s", p[i].nome);
        printf("\nDigite a matricula: ");
        scanf("%i", &p[i].mat);
        printf("\nDeseja registrar o (1)CPF ou o (2)RG: ");
        scanf("%i", &op);
        if (op == 1)
        {
            printf("\nDigite o CPF: ");
            scanf("%d", &p[i].d.CPF);  
        }
        else if (op == 2)
        {
            printf("\nDigite O RG: ");
            scanf("%d", &p[i].d.RG); 
        }  
    }
    return p; // Retorna os dados inseridos pelo usuário
}

void ImprimeAluno(int n, Aluno *Vet, FILE *arch)
{
    int i; // Variavel de contagem

    // Laço de repetição que imprime os dados dos alunos que foram cadastradas pelo usuario
    for (i = 0; i < n; i++)
    {
        printf("\nNome: %s", Vet[i].nome);
        printf("\nMatricula: %d", Vet[i].mat);
        printf("\nCPF: %d\n", Vet[i].d.CPF);
        printf("\nRG: %d\n", Vet[i].d.RG);
    }

    for (i = 0; i < n; i++) // Imprime dados dos alunos no arquivo
    {
        fprintf(arch, "Nome: %s\nMatricula: %i\nCPF: %d\nRG: %d\n\n", Vet[i].nome, Vet[i].mat, Vet[i].d.CPF, Vet[i].d.RG);   
    }
}