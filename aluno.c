#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

union documento
{
    int CPF;
    int RG;
};

struct aluno
{
    char nome[100];
    int mat;
    Documento d;
};

void ordenaAlunos(int N, Aluno *Vet)
{
    int i, j;      // Variáveis de contagem
    int r;         // Variável utilizada para ordenar strings, quando o usuário deseja ordenar por nomes
    char temp[100]; // Variável temporária, porém, criada como variável do tipo "char"

    // Laço de repetição usado para ordenar o vetor de acordo com o campo selecionado, neste caso, os nomes dos alunos
    
    for (i = 0; i < N; i++) // n-1
    {
        for (j = i + 1; j < N; j++) // n-1
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

Aluno *AlocaAlunos(int N)
{

    int i; // Variável de contagem
    int op1, op2, op3; /* Declarações de variáveis responsáveis por delimitar as opções
    da função "Aloca Alunos". Para cada opção um dado diferente será inserido pelo usuário ou não */
    int n_qnt; // Variável usada para a realocação da struct "Aluno"

    printf("\n-Menu-\n\n");
    printf("1 - Criar nova lista de alunos\n");
    printf("2 - Cancelar\n: ");
    scanf("%i", &op1);
    if (op1 == 1)
    {
        printf("Digite a quantidade de alunos a serem cadastrados: ");
        scanf("%i", &N);
        Aluno *p = (Aluno*) malloc(N * sizeof(Aluno)); // Criação de um ponteiro "p" e alocação de um vetor de "Aluno"

        if(p==NULL)
        {
            printf("Erro!");
            exit(1);
        }

        for (i = 0; i < N; i++)
        {
            printf("Qual documento deseja registrar?\n1 - CPF\n2 - RG2\n: ");
            scanf("%i", &op2);
            switch (op2)
            {
            case 1:
                printf("\nInsira o nome, a matricula e o CPF do %i aluno: ", i + 1);
                scanf("%s %i %i", p[i].nome, &p[i].mat, &p[i].d.CPF);
                break;
            case 2:
                printf("\nInsira o nome, a matricula e o RG do %i aluno: ", i + 1);
                scanf("%s %i %i", p[i].nome, &p[i].mat, &p[i].d.RG);
            default:
               break;
            } 
        }

        printf("\nDeseja mudar a quantidade de alunos:\n1 - Sim\n0 - Nao\n: ");

        if (op3 == 1)
        {
            Aluno * p1;
            printf("\nDigite a nova quantidade: ");
            scanf("%i", &n_qnt);
            Aluno *p = (Aluno*) realloc((Aluno*)p1 ,n_qnt * sizeof(Aluno));
        }
        else
        {
            return p; // Retorna os dados inseridos pelo usuário
        }
    }
    else
    {
        return 0; 
    } 
}

Documento* AlocaDocumento(void)
{
    Documento *d = (Documento*) malloc(sizeof(Documento));   //Criação de um ponteiro "d" e alocação de um vetor de "Documento"
    if(d==NULL)
    {
        printf("Erro!");
        exit(1);
    }
    return d;
}

void ImprimeAluno(int N, Aluno *Vet){
    int i; // Variavel de contagem

    // Laço de repetição que imprime os dados dos alunos que foram cadastradas pelo usuario
    for (i = 0; i < N; i++){
        printf("\nNome: %s", Vet[i].nome);
        printf("\nMatricula: %i", Vet[i].mat);
        printf("\nDocumento: %i\n", Vet[i].d.CPF);
    }
}
