/*
 * primeira_lib.c
 *
 *  Created on: Mar 18, 2023
 *      Author: lume
 */


#include "primeira_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * OBJETIVOS DO PROGRAMA
 * 		Criar uma lib que consiga Calcular alguns tipos de equacoes
 *
 * PRIMEIROS PASSOS
 * 		MMC - V
 * 		EQUACAO DO SEGUNDO GRAU - v
 * 		REGRA DE TRES - V
 * 		EXPONECIACAO - V
 * */

int
cont_elementos_de_entrada_double(double *elementos_do_vet)
{
	int cont = 0;

	for (cont = 0; *(elementos_do_vet+cont); cont++){}

	return cont++;
}


double
soma_valores(double *numeros_a_serem_somados)
{
	int i = 0;
	double solucao = 0.0;

	for (i = 0; (solucao += *(numeros_a_serem_somados+i)); i++){}

	return solucao;
}


double
subtrai_valores(double *numeros_a_serem_subtaidos)
{
	int i = 0;
	double solucao = *(numeros_a_serem_subtaidos);

	for (i = 1; (solucao -= *(numeros_a_serem_subtaidos+i)); i++){}

	return solucao;
}


double
divide_valores(double *numeros_a_serem_divididos)
{
	int i = 0;
	double solucao = *(numeros_a_serem_divididos);

	for (i = 1; (solucao /= *(numeros_a_serem_divididos+i)); i++){}

	return solucao;
}


double
multiplica_valores(double *numeros_a_serem_multiplicados)
{
	int i = 0;
	double solucao = 1.0;

	for (i = 0; (solucao *= *(numeros_a_serem_multiplicados+i)); i++){}

	return solucao;
}


double
exponeciaco_de_valores(double *numeros_a_ser_exp)
{
	int i = 0, len_numeros_elevados = cont_elementos_de_entrada(&numeros_a_ser_exp);
	double solucao = 1.0;

	for (i = len_numeros_elevados; i >= 0; i--)
		solucao = pow(*(numeros_a_ser_exp+i), solucao);

	return solucao;
}


int
confere_se_eh_tudo_um(int *lista_elementos)
{
	int flag_resultado = 0, i = 0;

	for (i = 0; *(lista_elementos+i); i++)
	{
		if (*(lista_elementos+i) != 1)
		{
			flag_resultado = 1;

			break;
		}

	}

	return flag_resultado;
}


int
eh_primo(int primo)
{
	if (primo == 3)
	    return FLAG_POSITIVO;


	  if (primo % 2 == 0 || primo % 3 == 0)
	    return FLAG_NEGATIVA;


	  for (int i = 5; i * i <= primo; i += 6)
	  {
	    if (primo % i == 0 || primo % (i + 2) == 0)
	      return FLAG_NEGATIVA;

	  }

	return FLAG_POSITIVO;
}


int
proximo_primo(int primo)
{
	for (primo += 1; eh_primo(primo); primo++) {}

	return primo;
}


int
mmc_de_n_numeros(int *lista_elementos)
{
	int resultado_mmc = 1, primo = 2;

	while (confere_se_eh_tudo_um(&lista_elementos))
	{
		int i = 0;

		for (i = 0; *(lista_elementos+i); i++)
		{
			int aux = *(lista_elementos+i), flag_ouve_divisao = 1;

			if (!(aux % primo))
			{
				*(lista_elementos+i) = aux / primo;
				flag_ouve_divisao = 0;

			}

			if (flag_ouve_divisao)
				primo = proximo_primo(primo);

			else
				resultado_mmc *= primo;

		}
	}

	return resultado_mmc;
}

//aprender a lidar com numeros complexos, complex.h
int
equacao_segundo_grau(elementos_da_equacao_sg *elementos_atuais, resposta_da_equacao_sg solucao)
{
	int delta;

	delta = (elementos_atuais->b * elementos_atuais->b) - (4.0 * elementos_atuais->a * elementos_atuais->c);

	if (delta >= 0)
	{
		solucao->x1 = ((-1 * elementos_atuais->b) + sqrt(delta)) / (elementos_atuais->a * 2);
		solucao->x2 = ((-1 * elementos_atuais->b) - sqrt(delta)) / (elementos_atuais->a * 2);

		return PASSED;

	}

	return ERROR;
}


double
regra_de_tres(double *elementos_da_rt)
{
	int i = 0;
	double *solucao;

	for (i = 0; i < QUANTIDADE_ELE_RT; i++)
	{
		if (!(*(elementos_da_rt+i)))
		{
			solucao = elementos_da_rt + 1;

			break;

		}
	}

	if (i == 0 || i == 3)
		*solucao = (*(elementos_da_rt+1) * *(elementos_da_rt+2)) / (i == 0 ? *(elementos_da_rt+3):*(elementos_da_rt+0));

	else
		*solucao = (*(elementos_da_rt+0) * *(elementos_da_rt+3)) / (i == 1 ? *(elementos_da_rt+2):*(elementos_da_rt+1));

	return *solucao;
}
