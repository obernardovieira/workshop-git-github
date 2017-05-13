#include <stdio.h>
#include <stdlib.h>

#include "ficheiros.h"
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

}

void adicionar_pergunta()
{
    int resposta = 0;
    int guardado;
    struct pergunta_ npergunta;

    printf("Introduza a pergunta:");
    scanf("\n%[^\n]", npergunta.pergunta);
    do
    {
        printf("Introduza a resposta #%d:", resposta + 1);
        scanf("\n%[^\n]", npergunta.respostas[resposta]);

    } while(++ resposta < 3);
    printf("Introduza o numero da resposta correta:");
    scanf("%d", &npergunta.resposta_correta);

    guardado = guardar_ficheiro_perguntas(npergunta);
    if(guardado)
    {
        printf("Guardado com sucesso!\n");
    }
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
