#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ficheiros.h"
#include "perguntas.h"

struct pergunta_* carregar_ficheiro_perguntas(int *t_perguntas)
{
    int contador;
    int total_perguntas;
    FILE *ptr_myfile;
    struct pergunta_ pergunta;
    struct pergunta_* perguntas;

    ptr_myfile = fopen("perguntas.bin","rb");
    if (!ptr_myfile)
    {
    	printf("Impossivel abrir o ficheiro!\n");
        *t_perguntas = 0;
    	return NULL;
    }

    fseek(ptr_myfile, 0, SEEK_END);
    total_perguntas = ftell(ptr_myfile);
    fseek(ptr_myfile, 0, SEEK_SET);
    
    perguntas = (struct pergunta_*)malloc(total_perguntas);
    total_perguntas = total_perguntas/sizeof(struct pergunta_);

    for (contador = 0; contador < total_perguntas; contador++)
    {
    	fread(&pergunta, sizeof(struct pergunta_), 1, ptr_myfile);

        strcpy(perguntas[contador].pergunta, pergunta.pergunta);
        strcpy(perguntas[contador].respostas[0], pergunta.respostas[0]);
        strcpy(perguntas[contador].respostas[1], pergunta.respostas[1]);
        strcpy(perguntas[contador].respostas[2], pergunta.respostas[2]);
        perguntas[contador].resposta_correta = pergunta.resposta_correta;
    }
    fclose(ptr_myfile);
    *t_perguntas = total_perguntas;
    return perguntas;
}

int guardar_ficheiro_perguntas(struct pergunta_ pergunta)
{
	FILE *ptr_myfile;
    int total_perguntas;

    struct pergunta_* perguntas = carregar_ficheiro_perguntas(&total_perguntas);
    if(perguntas == NULL)
    {
        ptr_myfile = fopen("perguntas.bin","wb");
    }
    else
    {
        ptr_myfile = fopen("perguntas.bin","ab");
    }

    if (!ptr_myfile)
    {
        printf("Impossivel abrir o ficheiro!");
        return 0;
    }
    fwrite(&pergunta, sizeof(struct pergunta_), 1, ptr_myfile);
    fclose(ptr_myfile);
    return 1;
}
