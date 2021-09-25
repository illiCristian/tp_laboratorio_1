/*
 * Biblioteca.h
 *
 *  Created on: 22 sept 2021
 *      Author: Cris
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
/// @fn int PedirUnEntero(char[])
/// @brief Esta funcion pide un numero entero
/// @param mensaje Es el mensaje que se le pasa a la funcion por parametro
/// @return Retorna un numero entero
int PedirUnEntero(char mensaje[]);
/// @fn int ValidarEnteroDeUnFlotante(float)
/// @brief Esta funcion se encarga de establecer si el primer operando ingresado es entero o no
/// @param primerOperando El parametro a determinar
/// @return El valor de verdad
int ValidarEnteroDeUnFlotante (float primerOperando);
/// @fn float PedirUnFlotante(char[])
/// @brief Esta funcion se encarga de pedir un numero flotante
/// @param mensaje Es el mensaje que se le pasa a la funcion por parametro
/// @return Retorna un numero flotante
float PedirUnFlotante(char mensaje[]);
/// @fn int MostrarMenu(int, int, float, float)
/// @brief Esta funcion muestra un menu con opciones para que el usuario pueda elegir
/// @param flagOpcion1 Es la opcion para saber si se ingreso el primer operando y mostrarlo
/// @param flagOpcion2 Es la opcion para saber si se ingreso el segundo operando y mostrarlo
/// @param primerOperando El primer operando para mostrarlo en el menu
/// @param segundoOperando El segundo operando para mostrarlo en el menu
/// @return Retorna la opcion ingresada en el menu
int MostrarMenu (int flagOpcion1, int flagOpcion2, float primerOperando, float segundoOperando);

#endif /* BIBLIOTECA_H_ */
