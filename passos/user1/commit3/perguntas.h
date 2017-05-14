
struct pergunta_
{
    char pergunta[64];
    int resposta_correta;
    char respostas[3][64];
};

void obter_perguntas_aleatorias(struct pergunta_ perguntas[7]);
