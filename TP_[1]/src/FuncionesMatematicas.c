/*
 * FuncionesMatematicas.c
 *
 *  Created on: 22 sept 2021
 *      Author: Cris
 */
#include "FuncionesMatematicas.h"
#include "Biblioteca.h"

float CalcularSuma (float a, float b)
{
    float resultado;

    resultado = a + b;

    return resultado;
}

//-----------------------------------------------------------------

float CalcularResta (float a, float b)
{
    float resultado;

    resultado = a - b;

    return resultado;
}

//--------------------------------------------------------------------

float CalcularDivision (float a, float b)
{
     float resultadoDivision;

    if(a !=0 && b !=0)
    {
        resultadoDivision = a / b;
    }
    else
    {
        resultadoDivision=0;
    }

    return resultadoDivision;
}


//--------------------------------------------------------------------

float CalcularMultiplicacion(float a, float b)
{
    float resultado;

    resultado = a * b;

    return resultado;
}

//---------------------------------------------------------------------

int CalcularFactorial(int a)
{
    int i;
    int resultado;
    int aux;

    resultado = 1;

    aux = ValidarEnteroDeUnFlotante(a);

    if (aux == 1 && a >= 0)
    {
        for (i = 1; i <= a; i++)
        {
            resultado *= i;
        }
    }else
    {
        resultado = 0;
    }

    return resultado;

}
