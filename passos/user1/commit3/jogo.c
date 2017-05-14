
#include "perguntas.h"
#include "jogador.h"
#include "jogo.h"

struct jogo_ criar_novo_jogo(char nome_jogador1[24], char nome_jogador2[24])
{
    struct jogo_ jogo;
    jogo.jogadores[0] = registar_novo_jogador(nome_jogador1);
    jogo.jogadores[1] = registar_novo_jogador(nome_jogador2);
    obter_perguntas_aleatorias(jogo.perguntas);
    return jogo;
}
