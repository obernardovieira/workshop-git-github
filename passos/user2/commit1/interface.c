#include <stdio.h>
#include <stdlib.h>

#include "jogador.h"
#include "jogo.h"

void novo_jogo()
{
    char jogador1[24];
    char jogador2[24];
    int resposta_jogador;
    struct jogo_ jogo;
    int pergunta = 0;
    int a_jogar = 0;

    printf("Introduza o nome do jogador 1:");
    scanf("\n%[^\n]", jogador1);
    printf("Introduza o nome do jogador 2:");
    scanf("\n%[^\n]", jogador2);

    jogo = criar_novo_jogo(jogador1, jogador2);

    printf("Em primeiro lugar joga %s e depois %s! Boa sorte.\n",
        jogo.jogadores[0].nome, jogo.jogadores[1].nome);

}

void administrador()
{

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
