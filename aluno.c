#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

union documento{
    int CPF;
    int RG;
};

struct aluno{
    char nome[100];
    int mat;
    Documento d;
};

void ordenaAlunos(int N, Aluno *Vet){
    int i, j;      // Variáveis de contagem
    int r;         // Variável utilizada para ordenar strings, quando o usuário deseja ordenar por nomes
    char temp[100]; // Variável temporária, porém, criada como variável do tipo "char"

    // Laço de repetição usado para ordenar o vetor de acordo com o campo selecionado, neste caso, os nomes dos alunos
    for (i = 0; i < N; i++){
        for (j = i + 1; j < N; j++){
            /* Atribuindo o valor da função strcmp à variável que auxilia na troca das strings.
            A função strcmp retorna 3 valores, 1, 0 e -1, mas neste caso, não estamos comparando
            se as strings são maiores em questão de quantidade de caracteres, mas sim, em relação ao código ascii */
            r = strcmp(Vet[i].nome, Vet[j].nome); 

            /* Estrutura de decisão "if" que realiza a ordenação caso a comparação feita anteriormente retorne valores maiores que 0,
            sinalizando que a primeira string é menor que a segunda em relação aos valores dos caracteres na tabela ascii */
            if (r > 0){
                strcpy(temp, Vet[i].nome);
                strcpy(Vet[i].nome, Vet[j].nome);
                strcpy(Vet[j].nome, temp);
            }
        }
    }
}

// Função que aloca um vetor de alunos que retorna um vetor de alunos e recebe a quantidade N de alunos como parâmetro
Aluno *AlocaAlunos(int N){
    int i; // Variável de contagem
    int op;

    Aluno *p = (Aluno*)malloc(N * sizeof(Aluno)); // Criação de um ponteiro "p" e alocação de um vetor de "Aluno"
    if(p==NULL){
        printf("Erro!");
        exit(1);
    }

    

    for (i = 0; i < N; i++){
        printf("Qual documento deseja registrar? |CPF[1]|RG[2]| ");
        scanf("%i", &op);
        if(op==1){
            printf("\nInsira o nome, a matricula e o CPF do %i aluno: ", i + 1);
            scanf("%s %i %i", p[i].nome, &p[i].mat, &p[i].d.CPF);
        }
        else if(op==2){
            printf("\nInsira o nome, a matricula e o RG do %i aluno: ", i + 1);
            scanf("%s %i %i", p[i].nome, &p[i].mat, &p[i].d.RG);
        }
        else{
            printf("opcao invalida!");
            exit(1);
        }
    }  
    
    return p; // Retorna os dados inseridos pelo usuário
}

Documento* AlocaDocumento(void){
    Documento *d = (Documento*)malloc(sizeof(Documento));   //Criação de um ponteiro "d" e alocação de um vetor de "Documento"
    if(d==NULL){
        printf("Erro!");
        exit(1);
    }
    return d;
}

// Função que não retorna nada e recebe como parâmetro uma quantidade N de alunos a serem cadastradas e um vetor de alunos como parâmetro
void ImprimeAluno(int N, Aluno *Vet){
    int i; // Variavel de contagem

    // Laço de repetição que imprime os dados dos alunos que foram cadastradas pelo usuario
    for (i = 0; i < N; i++){
        printf("\nNome: %s", Vet[i].nome);
        printf("\nMatricula: %i", Vet[i].mat);
        printf("\nDocumento: %i\n", Vet[i].d.CPF);
    }
}
