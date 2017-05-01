
struct jogador_
{
    char nome[24];
    int acertou;
    int errou;
    int jogouNvezes;
};

struct jogador_ registar_novo_jogador(char nome_jogador[24]);
