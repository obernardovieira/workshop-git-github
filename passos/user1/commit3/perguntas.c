
#include "perguntas.h"

void obter_perguntas_aleatorias(struct pergunta_ perguntas[7])
{
    int total_perguntas;
    struct pergunta_* fperguntas = carregar_ficheiro_perguntas(&total_perguntas);
    int pergunta = 0;
    int sou_tao_random;

    srand(time(NULL));
}
