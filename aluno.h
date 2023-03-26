#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

typedef union documento Documento;

typedef struct aluno Aluno;

/* Recebe como parâmetro um número inteiro "N", retornando um vetor de "Aluno". 
"N" corresponde ao tamanho do vetor de "Aluno". */
Aluno *AlocaAlunos(int N);

// Recebe void como parâmetro, alocando uma union "Documento", não há retorno.
Documento* AlocaDocumento(void);

/* Recebe como parâmetro um número inteiro "N" e uma struct "Aluno", não há retorno. 
Ordena alfabeticamente o nome dos alunos. */
void ordenaAlunos(int N, Aluno *Vet);

/* Recebe como parâmetro um número inteiro "N" e uma struct "Aluno", não há retorno. 
Imprime os dados dos alunos no arquivo. */
void ImprimeAluno(int N, Aluno *Vet);

#endif
