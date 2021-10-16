/*
 * ArrayEmployees.h
 *
 *  Created on: 29 sept 2021
 *      Author: Cris
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "Input.h"
#define CARGADO 1
#define VACIO 0

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/// @fn void PedirListaEmpleados(Employee[], int, int)
/// @brief Pide al usuario los datos "lista" de empleados
/// @param lista El Array employee
/// @param len Tamaño del array
/// @param id del main autoincrementable
void PedirListaEmpleados (Employee lista[], int len,int id);
/// @fn int initEmployees(Employee[], int)
/// @brief Inicializa una estructura para que todas las posiciones isEmpty sean iguales a VACIO
/// @param listaEmpleados
/// @param len Tamaño de la listade empleados
void initEmployees(Employee listaEmpleados[],int len);
/// @fn int addEmployee(Employee[], int, int, char[], char[], float, int)
/// @brief  Agrega un empleado que recibe por parametros a una posicion del array Employee
/// @param list array Employee
/// @param len Tamaño de la listade empleados
/// @param id De los empleados
/// @param name  Nombre
/// @param lastName Apellido
/// @param salary Salario
/// @param sector sector
/// @return Un valor de verdad
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
/// @fn int FindFreeSpace(Employee[], int)
/// @brief Verifica si hay lugar disponible y retorna una posicion del array
/// @param list lista empleados
/// @param len tamaño de la lista
/// @return retorna la posicion que encontro libre
int FindFreeSpace (Employee list[],int len);
/// @fn int printEmployees(Employee[], int)
/// @brief Imprime una lista
/// @param list
/// @param length tamaño de la lista
/// @return Un valor de verdad
int printEmployees(Employee list[], int length);
/// @fn void showEmployee(Employee)
/// @brief Muestra un solo empleado de la lista
/// @param lista de empleados
void showEmployee(Employee lista);
/// @fn int GenerarId(int)
/// @brief Incrementa un valor numerico para ser utilizado como id
/// @param id
/// @return el id Incrementado
int GenerarId (int id);
/// @fn int findEmployeeById(Employee[], int, int)
/// @brief Busca un empleado por id
/// @param list
/// @param len
/// @param id
/// @return Un valor de verdad
int findEmployeeById(Employee list[], int len,int id);
/// @fn void HarcodearEmpleados(Employee[], int)
/// @brief Carga una lista de empleados para realizar pruebas
/// @param lista
/// @param len
///
void HarcodearEmpleados (Employee lista[],int len);
/// @fn void ModificarEmpleado(Employee[], int)
/// @brief
/// @param list
/// @param index es la posicion a modificar en la lista
///
void ModificarEmpleado(Employee list[],int index);
/// @fn int MostrarMenuAModificar()
/// @brief Muestra un menu
/// @return la opcion ingresada
int MostrarMenuAModificar();
/// @fn int removeEmployee(Employee[], int, int)
/// @brief Borra un empleado
/// @param lista
/// @param tamaño de la lista
/// @param id del empleado a borrar
/// @return valor de verdad

int removeEmployee(Employee list[], int len, int id);

/// @fn int sortEmployees(Employee[], int, int)
/// @brief Ordena una lista
/// @param list
/// @param len
/// @param order
/// @return valor de verdad
///
int sortEmployees(Employee list[], int len, int order);
/// @fn void MostrarMenuCase4(Employee[], int)
/// @brief
/// @param lista
/// @param len
void MostrarMenuCase4(Employee lista[],int len);

/// @fn int CalcularPromedio(Employee[], int, float*)
/// @brief  Calcula promedio de sueldos
/// @param lista
/// @param len
/// @param promedio
/// @return un valor de verdad
int CalcularPromedio (Employee lista[], int len, float *promedio);

/// @fn int BuscarPromedioMasAlto(Employee[], int, float, int*)
/// @brief Busca un promedio mas alto
/// @param lista
/// @param len
/// @param promedio para comparar
/// @param conEmpleadosMayorPromedio
/// @return un valor de verdad
int BuscarPromedioMasAlto (Employee lista[],int len,float promedio, int *conEmpleadosMayorPromedio);

#endif /* ARRAYEMPLOYEES_H_ */
