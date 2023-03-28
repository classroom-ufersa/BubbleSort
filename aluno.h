typedef struct documento Documento;
typedef struct aluno Aluno;

/* Recebe como parametro um número inteiro "n", retornado um vetor de "Aluno". 
"n" corresponde ao tamanho do vetor de "Aluno". */
Aluno *AlocaAlunos(int n);

/* Recebe como parâmetro um número inteiro "n" e uma struct "Aluno", não há retorno. 
Ordena alfabeticamente o nome dos alunos. */
void OrdenaAlunos(int n, Aluno *Vet);

/* Recebe como parâmetro um número inteiro "n", uma struct "Aluno" e um arquivo "FILE", não há retorno. 
Imprime os dados dos alunos no terminal e no arquivo. */
void ImprimeAluno(int n, Aluno *Vet, FILE *arch);