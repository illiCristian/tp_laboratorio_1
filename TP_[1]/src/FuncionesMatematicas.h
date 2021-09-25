/*
 * FuncionesMatematicas.h
 *
 *  Created on: 22 sept 2021
 *      Author: Cris
 */
#include <stdio.h>


#ifndef FUNCIONESMATEMATICAS_H_
#define FUNCIONESMATEMATICAS_H_
/// @fn float CalcularSuma(float, float)
/// @brief Esta funcion calcula una suma entre 2 parametros
/// @param a Es el primer parametro
/// @param b Es el segundo parametro
/// @return	Retorna el resultado de la suma
float CalcularSuma (float a, float b);
/// @fn float CalcularResta(float, float)
/// @brief Calcula una resta entre 2 parametros
/// @param a Es el primer parametro
/// @param b Es el segundo parametro
/// @return Retorna el resultado de la resta
float CalcularResta (float a, float b);
/// @fn float CalcularDivision(float, float)
/// @brief Esta funcion calcula una division entre 2 parametros
/// @param a Es el primer parametro
/// @param b Es el segundo parametro
/// @return Retorna el resultado de la division
float CalcularDivision (float a, float b);
/// @fn float CalcularMultiplicacion(float, float)
/// @brief Esta funcion calcula una multiplicacion entre 2 parametros
/// @param a  Es el primer parametro
/// @param b Es el segundo parametro
/// @return Retorna el resultado de la multiplicacion
float CalcularMultiplicacion (float a, float b);
/// @fn int CalcularFactorial(int)
/// @brief Esta funcion calcula el factorial de un numero
/// @param a Es el parametro para calcular el factorial
/// @return Retornal el resulado del factoreo del numero ingresado
int CalcularFactorial(int a);

#endif /* FUNCIONESMATEMATICAS_H_ */
