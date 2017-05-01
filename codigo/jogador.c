
#include <string.h>

#include "perguntas.h"
#include "jogador.h"
#include "jogo.h"

struct jogador_ registar_novo_jogador(char nome_jogador[24])
{
    struct jogador_ jogador;
    strcpy(jogador.nome, nome_jogador);
    jogador.acertou = 0;
    jogador.errou = 0;
    jogador.jogouNvezes = 0;
    return jogador;
}
