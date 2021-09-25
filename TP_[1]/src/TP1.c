/*Illi Cristian
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
*/

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesMatematicas.h"
#include "Biblioteca.h"


int main (void)
{
	setbuf(stdout,NULL);
    int opcionIngresada;
    float primerOperando;
    float segundoOperando;
    float mostrarSuma;
    float mostrarResta;
    float mostrarDivision;
    float mostrarMultiplicacion;
    int mostrarFactorialA;
    int mostrarFactorialB;
    int flagOpcion1;
    int flagOpcion2;
    int flagOpcion3;

    flagOpcion3 = 0;
    flagOpcion2 = 0;
    flagOpcion1 = 0;


    do
    {

    	opcionIngresada = MostrarMenu(flagOpcion1,flagOpcion2,primerOperando,segundoOperando);



    	switch (opcionIngresada)
    {
    case 1:
        primerOperando = PedirUnFlotante("Ingrese el primer Operando: ");
        flagOpcion1 =1;
        break;
    case 2:
        segundoOperando = PedirUnFlotante("Ingrese el segundo operando: ");
        flagOpcion2 = 1;
    break;


    case 3:
    if(flagOpcion1 == 1 && flagOpcion2 == 1)
    {
      mostrarSuma = CalcularSuma(primerOperando,segundoOperando);
      mostrarResta = CalcularResta(primerOperando,segundoOperando);
      mostrarDivision = CalcularDivision(primerOperando,segundoOperando);
      mostrarMultiplicacion = CalcularMultiplicacion(primerOperando,segundoOperando);
      mostrarFactorialA = CalcularFactorial (primerOperando);
      mostrarFactorialB = CalcularFactorial (segundoOperando);
      flagOpcion3 = 1;
    }


    else{
        printf("Debe ingresar los 2 operandos para poder realizar los calculos\n");
    }
      break;
      case 4:

    if(flagOpcion3 != 0)
    {
    	printf("El resultado de A+B es:%.2f\n", mostrarSuma);
    	printf("El resultado de A-B es:%.2f\n", mostrarResta);
    if (segundoOperando != 0)
    {
    	printf("El resultado de A/B es:%.2f\n", mostrarDivision);
    }else{
        printf("No se puede dividir por cero\n");
    }
    	printf("El resultado de A*B es:%.2f\n", mostrarMultiplicacion);
    if (mostrarFactorialA == 0)
    {
    	printf("No se puede calular factorial de un numero negativo o que tenga decimales \n");
    }else
    {
        printf("EL resultado del factorial A es:%d \n",mostrarFactorialA);
    }
    if (mostrarFactorialB == 0)
    {
        printf("No se puede calcular factorial de un numero negativo o que tenga decimales \n");
    }else
    {
    	printf("EL resultado del factorial B es:%d \n",mostrarFactorialB);
    }


    break;
    }else
    {
    	printf("Debe realizar los calculos para mostrar los resultados\n");// ME LO METO EN EL ORTO
    }

    }
    } while (opcionIngresada != 5);

    return 0;
}
//-------------------------------------------------------------
