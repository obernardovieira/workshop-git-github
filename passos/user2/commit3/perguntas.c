
#include "perguntas.h"

void obter_perguntas_aleatorias(struct pergunta_ perguntas[7])
{
    int total_perguntas;
    struct pergunta_* fperguntas = carregar_ficheiro_perguntas(&total_perguntas);
    int pergunta = 0;
    int sou_tao_random;

    srand(time(NULL));

    do
    {
        sou_tao_random = (int)(rand() % total_perguntas);

        strcpy(perguntas[pergunta].pergunta, fperguntas[sou_tao_random].pergunta);
        strcpy(perguntas[pergunta].respostas[0], fperguntas[sou_tao_random].respostas[0]);
        strcpy(perguntas[pergunta].respostas[1], fperguntas[sou_tao_random].respostas[1]);
        strcpy(perguntas[pergunta].respostas[2], fperguntas[sou_tao_random].respostas[2]);
        perguntas[pergunta].resposta_correta = fperguntas[sou_tao_random].resposta_correta;

    } while(pergunta ++ < 6);
}
