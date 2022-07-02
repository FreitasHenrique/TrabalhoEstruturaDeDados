typedef struct amigos{
    int id;
    struct amigos *prox;
}Amigos;

typedef struct aluno
{
    int id;
    char nome[10], curso[30];
    struct Aluno *ant, *prox;
    Amigos *listaAmigos;

}Aluno; 

void menu(int *op);

void criarLista(Aluno **a);

Aluno *leAluno(Aluno **a);

void imprimeAluno(Aluno **a);

int verificaID(int *temp);

int showOptions(int *temp);

void alteraNome(Aluno *a);

void alteraCurso(Aluno *a);

void alterarDados(Aluno **a);

void insereAmigo(Aluno **l);