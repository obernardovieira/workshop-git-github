#include <stdio.h>
#include <stdlib.h>

void novo_jogo()
{

}

void adicionar_pergunta()
{

}

void administrador()
{
    int opcao;

    while(1)
    {
        printf("Escolha uma opção:\n");
        printf("1 - Adicionar nova pergunta\n");
        printf("2 - Sair\n");

        scanf("%d", &opcao);
        if(opcao == 2)
        {
            break;
        }

        switch (opcao) {
            case 1:
                adicionar_pergunta();
                break;
        }

    }
}

int main()
{
    int opcao;
    printf("Bem vindo ao QUIZ!\n");

    while (1)
    {
        printf("Escolha uma opção:\n");
        printf("1 - Novo jogo\n");
        printf("2 - Administrador\n");
        printf("3 - Sair\n");

        scanf("%d", &opcao);
        if(opcao == 3)
        {
            break;
        }

        switch (opcao) {
            case 1:
                novo_jogo();
                break;
            case 2:
                administrador();
                break;
        }
    }
}
