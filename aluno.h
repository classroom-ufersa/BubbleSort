#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

typedef struct aluno Aluno;

void ordenaAlunos(int N, Aluno *Vet);

Aluno *AlocaAlunos(int N);

void ImprimeAluno(int N, Aluno *Vet);

#endif