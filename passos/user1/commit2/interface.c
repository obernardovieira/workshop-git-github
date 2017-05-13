#include <stdio.h>
#include <stdlib.h>

#include "perguntas.h"
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

    while(pergunta < 7)
    {
        printf("%s\n", jogo.perguntas[pergunta].pergunta);
        printf("1 - %s\n", jogo.perguntas[pergunta].respostas[0]);
        printf("2 - %s\n", jogo.perguntas[pergunta].respostas[1]);
        printf("3 - %s\n", jogo.perguntas[pergunta].respostas[2]);
        scanf("%d", &resposta_jogador);

        if(resposta_jogador == jogo.perguntas[pergunta].resposta_correta)
        {
            printf("Parabens! Acertou!");
            jogo.jogadores[a_jogar].acertou ++;
        }
        else
        {
            printf("Resposta errada!");
            jogo.jogadores[a_jogar].errou ++;
        }

        a_jogar ^= a_jogar;
        printf("É a vez de %s\n", jogo.jogadores[a_jogar].nome);

        pergunta ++;
    }

    printf("** FIM DO JOGO **\n");
    if(jogo.jogadores[0].acertou > jogo.jogadores[1].acertou)
    {
        printf("O jogador %s ganhou!\n", jogo.jogadores[0].nome);
    }
    else
    {
        printf("O jogador %s ganhou!\n", jogo.jogadores[1].nome);
    }
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
