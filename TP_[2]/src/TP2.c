#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Input.h"

#define TAM_Employees 1000

#define CARGADO 1
#define VACIO 0

int main(void)
{
	setbuf(stdout,NULL);


	Employee listaEmpleados[TAM_Employees];

	int id;
	int idABuscar;
	int idABorrar;
	int flag;
	int opcionIngresada;
	int indexAModificar;

	initEmployees(listaEmpleados, TAM_Employees);

	HarcodearEmpleados (listaEmpleados,TAM_Employees);

	flag = 0;
	id= 1;

	do
	{
		printf("\n-------------------------------------------- \n");
		printf("\n Bienvenido al TP2 Creado por Cristian Illi \n");
		printf("\n-------------------------------------------- \n");
		opcionIngresada = MostrarMenu("Ingrese una opcion \n");
		switch (opcionIngresada)
	{
	case 1:

		if(FindFreeSpace(listaEmpleados, TAM_Employees) != -1)
		{
			id = GenerarId(id);
			PedirListaEmpleados(listaEmpleados,TAM_Employees,id);
			flag =1;
		}else{
			printf("No hay lugar disponible para cargar Empleados \n");
		}

		break;
	case 2:
		if(flag !=0)
		{
			printEmployees(listaEmpleados, TAM_Employees);
			idABuscar = PedirUnEntero("Ingrese el id a buscar: ");
			indexAModificar = findEmployeeById(listaEmpleados, TAM_Employees, idABuscar);

			if (indexAModificar != -1)
			{
				printf("Se encontro el id ingresado en la lista \n");

				ModificarEmpleado(listaEmpleados, indexAModificar);
			}
			else {
				printf("No se encontro el id ingresado en la lista \n");
			}
		}else
		{
			printf("Primero tiene que cargar un empleado para despues poder modificarlo \n");
		}

		break;
	case 3:
		if(flag !=0)
		{

			printEmployees(listaEmpleados, TAM_Employees);
			idABorrar = PedirUnEntero("Ingrese la id del empleado que desea borrar: \n");
			removeEmployee(listaEmpleados,TAM_Employees,idABorrar);
		}else{
			printf("Primero tiene que cargar un empleado para poder borrar uno \n");
		}
		break;
	case 4:
		if(flag !=0)
		{
			MostrarMenuCase4(listaEmpleados,TAM_Employees);
		}else
		{
			printf("Primero tiene que cargar un empleado para poder ver la lista \n");
		}

		break;
	}

	} while (opcionIngresada !=5);



	return EXIT_SUCCESS;
}

