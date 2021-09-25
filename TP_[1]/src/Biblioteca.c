/*
 * Biblioteca.c
 *
 *  Created on: 22 sept 2021
 *      Author: Cris
 */

#include "FuncionesMatematicas.h"
#include "Biblioteca.h"


//------------------------------------------------
int MostrarMenu (int flagOpcion1, int flagOpcion2, float primerOperando, float segundoOperando)
{
        int opcionIngresada;


        if (flagOpcion1 == 0 && flagOpcion2 == 0)
        {
         printf("Elija una opcion\n");
         printf("1. Ingresar 1er operando ( A = X)\n");
         printf("2. Ingresar 2do operando (B = Y)\n");
         printf("3. Calcular todas las operaciones\n");
         printf("4. Informar resultados\n");
         printf("5. Salir\n");


        }else if (flagOpcion2 == 1 && flagOpcion1 == 1)
        {
         printf("Elija una opcion\n");
         printf("1. Ingresar 1er operando ( A = %.2f)\n",primerOperando);
         printf("2. Ingresar 2do operando (B = %.2f)\n",segundoOperando);
         printf("3. Calcular todas las operaciones\n");
         printf("4. Informar resultados\n");
         printf("5. Salir\n");

        }else if (flagOpcion1 == 1 && flagOpcion2 == 0)
        {
         printf("Elija una opcion\n");
         printf("1. Ingresar 1er operando ( A = %.2f)\n",primerOperando);
         printf("2. Ingresar 2do operando (B = Y)\n");
         printf("3. Calcular todas las operaciones\n");
         printf("4. Informar resultados\n");
         printf("5. Salir\n");

        }else if (flagOpcion2 == 1 && flagOpcion1 == 0)
        {
         printf("Elija una opcion\n");
         printf("1. Ingresar 1er operando ( A = Y)\n");
         printf("2. Ingresar 2do operando (B = %.2f)\n",segundoOperando);
         printf("3. Calcular todas las operaciones\n");
         printf("4. Informar resultados\n");
         printf("5. Salir\n");
        }

        scanf("%d", &opcionIngresada);

        return opcionIngresada;
}
//------------------------------------------------
int PedirUnEntero(char mensaje[])
{
    int numeroIngresado;

    printf(mensaje);
    fflush(stdin);
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}
//--------------------------------------------------
float PedirUnFlotante(char mensaje[])
{
    float numeroIngresado;

    printf(mensaje);
    fflush(stdin);
    scanf("%f",&numeroIngresado);

    return numeroIngresado;
}
//-----------------------------------------------------
int ValidarEnteroDeUnFlotante (float primerOperando)
{
    int entero;
    int resultado;

    entero = primerOperando;

    resultado = 0;

    primerOperando = primerOperando - entero;
    if (primerOperando == 0)
    {
         resultado = 1;
    }
    return resultado;

}

