#include <stdio.h>
#include <stdlib.h>

typedef struct amigos{
    int info;
    struct amigos *prox;
}Amigos;

typedef struct aluno
{
    int id;
    char nome[10], curso[30];
    struct Aluno *ant, *prox;
    Amigos *listaAmigos;

}Aluno; 

void menu(int *op){
    // system("cls");
    printf("----- Menu -----\n\n");
    printf("[1] - Inserir um novo aluno.\n");
    printf("[2] - Alterar os dados de um alunos.\n");
    printf("[3] - Remover um aluno\n");
    printf("[4] - Imprimir a lista de alunos.\n");
    printf("[5] - Inserir relacao de amizade\n");
    printf("[6] - Remover relacao de amizade\n");
    printf("[7] - Imprimir amigos de um aluno\n");
    printf("[8] - Imprimir a lista de alunos por curso\n");
    printf("[9] - Sair.\n");
        scanf("%d",op);
}

void criarLista(Aluno **a){
    *a = NULL;
}

Aluno *leAluno(Aluno **a){
    system("cls");
    Aluno *n = malloc(sizeof(Aluno));
    if(n != NULL){
        n->id = 0;
        printf("Informe o nome do novo aluno: ");
            scanf("%s",n->nome);
        printf("Informe o curso do novo aluno: ");
            scanf("%s",n->curso);
        n->prox = *a;
        *a = n;
        return *a;
    }
    else
        printf("Falha ao alocar memoria, volte duas casas!\n\n");
}

void imprimeAluno(Aluno **a){
    system("cls");
    int cont = 0;
    Aluno *p;
        for(p = *a; p != NULL; p = p->prox){
            printf("----- Aluno %d -----\n\n", cont);
            printf("Id: %d\n",p->id);
            printf("Nome: %s\n",p->nome);
            printf("Curso: %s\n\n",p->curso);
            cont++;
        }
    system("pause");
}

int verificaID(int *temp){
    printf("Informe o ID do aluno:");
        scanf("%d",&temp);
    return temp;
}

int showOptions(int *temp){
    printf("O que deseja alterar deste aluno? \n\n");
    printf("[1] - Nome.\n");
    printf("[2] - Curso.\n");
        scanf("%d",&temp);
    return temp;
}

void alteraNome(Aluno *a){
    printf("Informe o novo nome do aluno:");
        scanf("%s",a->nome);
}

void alteraCurso(Aluno *a){
    printf("Informe o novo curso do aluno:");
        scanf("%s",a->curso);
}

void alterarDados(Aluno **a){
system("cls");   
    int temp = verificaID(&temp);
	Aluno *p;
    for (p = *a; p != NULL; p = p->prox ){
        if (p->id == temp){
            int op = showOptions(&op);
            op == 1? alteraNome(*a) : alteraCurso(*a);
        }else
            printf("ID nao encontrado.\n");
    }
}


void insereAmigo(Aluno **l){
    int temp = verificaID(&temp);
    Aluno *p = *l;
    while(p != NULL){
        if(temp == p->id){ 
            int boolean = 0;
            
            
            printf("Informe o ID do amigo:");
            scanf("%d",&temp);
            
            Aluno *n;
            n->listaAmigos = (*l)->listaAmigos;
            while(n != NULL){
                if(temp == n->listaAmigos->info){
                    boolean++;
                }
                n->listaAmigos = n->listaAmigos->prox;    
            }
        if(boolean > 0 ){
            printf("Já são amigos. \n");
        }else{
            n =(Aluno*) malloc(sizeof(Aluno));
            if(n != NULL){
                n->listaAmigos->info = temp;
                n->listaAmigos = (*l)->listaAmigos->prox;
                (*l)->listaAmigos = n->listaAmigos;
            }else{
                printf("Não foi possível alocar espaço. ");
            }
        }
            
        }else{
            printf("ID nao encontrado.\n");
        }    
    }    
}