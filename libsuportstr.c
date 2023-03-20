/*
 * libsuportstr.c
 *
 *  Created on: Mar 18, 2023
 *      Author: lume
 */


#include "primeira_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
 * OBJETIVOS DO PROGRAMA
 * 		Criar uma lib que consiga Calcular alguns tipos de equacoes
 *
 * IDENTIFICACAO DE ENTRADA
 * 		MUDANCA DE VIRGULA PARA PONTO - O
 * 		IDENTIFICAO DE NIVEIS DE RESOLUCAO
 * 		RASTREADOR DE INCONSISTENCIAS
 * 		CONVERSOES DE TIPO
 * */


int
meu_strstr_strchr(char *expressao, char *elemento_de_paridade,int *posicao, int len_elemento_de_paridade)
{
	int cont = 0;

	if (len_elemento_de_paridade == 1)
	{
		char caracter = '';
		int i = 0;

		for (i = 0; (caracter = *(expressao+i)); i++)
		{
			if (caracter == *(elemento_de_paridade))
			{
				posicao[cont] = i;
				cont++;
			}
		}
	}else
	{
		char caracter = '';
		int i = 0, j = 0;

		for (i = 0; (caracter = *(expressao+i)); i++)
		{
			int static correcao_de_i = len_elemento_de_paridade - 1;

			if (*(expressao+i) == *(elemento_de_paridade) && strncmp(expressao + i, elemento_de_paridade, len_elemento_de_paridade) == 0)
			{
				posicao[cont] = i;
				cont++;

				i += correcao_de_i;
			}
		}
	}

	switch (cont)
	{
		case 1:
			return FLAG_POSITIVO;

		default:
			return FLAG_NEGATIVA;
	}
}


void
altera_char(char *entrada_txt, char char_substituto, int *posicoes, int ocorrencias)
{
	int i = 0;

	for (i = 0; i < ocorrencias; i++)
		*(entrada_txt+*(posicoes+i)) = char_substituto;

}


void
altera_str(char *entrada_txt, char *conjunto_de_str_substituta, int *posicoes, int len_str_atual, int ocorrencias)
{
	int i = 0;

	for (i = 0; i < ocorrencias; i++)
		memcpy(entrada_txt + *(posicoes+i), conjunto_de_str_substituta, len_str_atual);

}

//testar alocacao
int
muda_uma_str_por_outra(char *entrada_txt, char *conjunto_de_str_atual, char *conjunto_de_str_substituta, int ocorrencias)
{
	int i = 0, *posicoes;
	long unsigned len_str_atual = strlen(conjunto_de_str_atual), len_str_substituta = strlen(conjunto_de_str_substituta);

	if (len_str_atual < len_str_substituta)
	{
		return ERROR;

	}else if (len_str_atual == 1)
	{
		*posicoes = (int *) malloc(sizeof(int) * len_str_atual);

		if (meu_strstr_strchr(&entrada_txt, &conjunto_de_str_atual, &posicoes, len_str_atual))
		{
			altera_char (&entrada_txt, conjunto_de_str_substituta, &posicoes, ocorrencias);

		}else
		{
			free(posicoes);

			return ERROR;

		}

	}else
	{
		*posicoes = (int *) malloc(sizeof(int) * len_str_atual);

		if (meu_strstr_strchr(&entrada_txt, &conjunto_de_str_atual, &posicoes, len_str_atual))
		{
			altera_str (&entrada_txt, &conjunto_de_str_substituta, &posicoes, len_str_atual, ocorrencias);

		}

		else
			free(posicoes);

			return ERROR;

	}

	free(posicoes);

	return PASSED;
}
