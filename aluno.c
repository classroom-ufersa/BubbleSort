#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct aluno
{
    char nome[100];
    int mat;
    int doc;
} Aluno;

void ordenaAlunos(int N, Aluno *Vet)
{

    int i, j;      // Variaveis contadoras
    int r;         // Variavel utilizada para ordenar strings, quando o usuario deseja ordenar por nomes
    char temp[60]; // Variavel temporaria, porém, criada como variavel do tipo CHAR
    // Laço de repetição usado para ordenar o vetor de acordo com o campo selecionado, neste caso, NOMES
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            r = strcmp(Vet[i].nome, Vet[j].nome); // Atribuindo o valor da função strcmp a variavel que auxilia na troca das strings
            // a função strcmp retorna 3 valores, 1, 0 e -1, mas neste caso não estamos comparando se as strings são maiores em questão
            // de quantidade de caracteres, mas sim, em relação ao codigo ascii
            if (r > 0) // Estrutura de decisão que realiza a ordenação caso a comparação feita anteriormente retorne valores maiores que 0,
            // sinalizando que a primeira string é menor que a segunda em relação aos valores dos caracteres na tabela ascii
            {
                strcpy(temp, Vet[i].nome);
                strcpy(Vet[i].nome, Vet[j].nome);
                strcpy(Vet[j].nome, temp);
            }
        }
    }
}

// Função que aloca um vetor de alunos que retorna um vetor de alunos e recebe a quantidade N de alunos como parâmetro
Aluno *AlocaAlunos(int N)
{
    int i;                                         // Variavel contadora
    Aluno *p = (Aluno *)malloc(N * sizeof(Aluno)); // Criação de um ponteiro p e alocação de um vetor de alunos
    // Laço de repetição que pede ao usuario os dados de cada aluno para realizar o cadastro
    for (i = 0; i < N; i++)
    {
        printf("\nInsira o nome, a matricula e a nota da %i pessoa: ", i + 1);
        scanf("%s %i %i", p[i].nome, &p[i].mat, &p[i].doc);
    }

    return p; // Retorna os dados inseridos pelo usuario
}

// Função que não retorna nada e recebe como parâmetro uma quantidade N de alunos a serem cadastradas e um vetor de alunos como parâmetro
void ImprimeAluno(int N, Aluno *Vet)
{

    int i; // Variavel contadora

    // Laço de repetição que imprime os dados dos alunos que foram cadastradas pelo usuario
    for (i = 0; i < N; i++)
    {
        printf("\nNome: %s", Vet[i].nome);
        printf("\nMatricula: %i", Vet[i].mat);
        printf("\nDocumento: %i\n", Vet[i].doc);
    }
}
