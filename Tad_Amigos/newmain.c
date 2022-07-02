
#include <stdio.h>
#include <stdlib.h>
#include "tad_amigos.h"

int main()
{
system("cls");
Aluno *lista;
int op = 0;

    criarLista(&lista);
    while (op != 9)
    {
        menu(&op);
        switch (op)
        {
        case 1:
            leAluno(&lista);
            break;
        case 2:
            alterarDados(&lista);
            break;
        case 4:
            imprimeAluno(&lista);
            break;
        case 5:
            insereAmigo(&lista);
        default:
            break;
        }
    }
    
    system("cls");
    return 0;
}

