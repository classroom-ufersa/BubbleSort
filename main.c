#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.c"

int main(){
    FILE *arch = fopen("ListaDeAlunos.txt", "w"); // Abre e cria um arquivo
    int n;                                          // Variavel que armazena e define a quantidade de pessoas que serão cadastradas
    int i;                                          // Variavel contadora
    printf("\nInforme a quantidade de alunos a serem cadastradas: ");
    scanf("%i", &n); // Lendo a quantidade de pessoas que serão cadastradas
    // Criação de ponteiro do tipo da struct Aluno. Chamada da função que será usada para alocar um vetor de Aluno
    // Atribuição do valor que será retornado da função que aloca um vetor para o ponteiro da struct do tipo Aluno
    Aluno *p = AlocaAlunos(n);

    ordenaAlunos(n, p);
    ImprimeAluno(n, p);
    for (i = 0; i < n; i++){
        fprintf(arch, "Nome: %s\nMatricula: %i\nDocumento: %i\n\n", p[i].nome, p[i].mat, p[i].doc);
    }
    fclose(arch);
    free(p); // Liberando espaço alocado dinamicamente
    printf("\nPrograma finalizado!\n");
    system("pause");
    printf("\n\n");
    return 0;
}
