#include "aluno.h"

int main(){
    setlocale(LC_ALL, "");
    FILE *arch = fopen("Lista de alunos.txt", "r+"); // Abre e cria um arquivo
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
        fprintf(arch, "Nome: %s\nMatricula: %i\nNota: %f\n\n", p[i].nome, p[i].mat, p[i].nota);
    }
    fclose(arch);
    free(p); // Liberando espaço alocado dinamicamente
    printf("\nPrograma finalizado!\n");
    system("pause");
    printf("\n\n");
    return 0;
}
