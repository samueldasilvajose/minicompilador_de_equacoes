/*
 * primeira_lib.h
 *
 *  Created on: Mar 18, 2023
 *      Author: lume
 */

#ifndef PRIMEIRA_LIB_H_
#define PRIMEIRA_LIB_H_
/*
 * Essa biblioteca esta sendo desenvolvida para pretar suporte a um codigo que resolve varias sentencas matematicas
 * complexas, como se fosse um com pilador. Tal lib vai possuir suporte para solucoes basicas de matematica e fisica, como:
 * inverssoes de matrizes, mmc, questoes de geometria plana, etc.
 * */

#define QUANTIDADE_ELE_RT 4
#define FLAG_POSITIVO 1
#define FLAG_NEGATIVA 0
#define ERROR 1
#define PASSED 0

typedef struct
{
	int a = 0;
	int b = 0;
	int c = 0;

} elementos_da_equacao_sg;

typedef struct
{
	double x1 = 0.0;
	double x2 = 0.0;

}resposta_da_equacao_sg;

#endif /* PRIMEIRA_LIB_H_ */
