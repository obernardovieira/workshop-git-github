
struct jogo_
{
    struct jogador_ jogadores[2];
    struct pergunta_ perguntas[7];
};

struct jogo_ criar_novo_jogo(char nome_jogador1[24], char nome_jogador2[24]);
