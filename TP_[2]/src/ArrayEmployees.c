#include "ArrayEmployees.h"




//----------------------------------------------------------------------------
void PedirListaEmpleados (Employee lista[], int len, int id)
{

	char name[51];
	char lastName[51];
	float salary;
	int sector;

	PedirCadena(name,"Ingrese el nombre: ","Error Ingrese solo el nobmre");
	PedirCadena(lastName, "Ingrese el apellido: ", "Error: Ingrese solo el apellido");
	PedirNumeroFlotante(&salary, "Ingrese el salario [0-800k]: ", "Salario Incorrecto, reingrese.\n", 0, 800000.00,5);
	sector = PedirUnEnteroRango("Ingrese el sector: \n 1)Cables Alta Tension \n 2)Lineas Aereas \n 3)Gerencia Distribucion \n 4)Comercial \n 5)Gerencia de Transmision ", 1, 5);



	if(addEmployee(lista, len, id, name, lastName, salary, sector) != -1)
		{
			printf("Se cargo el empleado exitoxamente \n");
		}
	else
		{
			printf("No se puede cargar mas datos por que no hay espacio libre \n");
		}
}

//-----------------------------------------------------------------------------
void initEmployees(Employee listaEmpleados[],int len)
{
	for (int i; i < len; i++)
	{
		listaEmpleados[i].isEmpty = VACIO;
	}

}
//-----------------------------------------------------------------------------

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
	int index;
	int retorno;


	retorno = -1;

	index = FindFreeSpace(list,len);

	if (index != -1)
	{
		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName,lastName);
		list[index].salary = salary;
		list[index].sector = sector;
		list[index].isEmpty = CARGADO;
		retorno = 0;
	}

	return retorno;
}
//--------------------------------------------------------------------------------
int FindFreeSpace (Employee list[],int len)
{
	int retorno;
	int i;
	retorno = -1;

	for (i = 0; i < len; i++)
	{
		if (list[i].isEmpty == VACIO)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------
int GenerarId (int id)
{
    id++;
    return id;
}



//---------------------------------------------------------------------------------------
void showEmployee(Employee lista)
{
   printf("   %4d    %6s   %10s   %12.2f  %4d \n", lista.id, lista.name,lista.lastName,lista.salary,lista.sector);
}
//---------------------------------------------------------------------------------------
int printEmployees(Employee list[], int len)
{
	printf("\n---------------------- Lista De Empleados ---------------------- \n");
	printf("     Id        Name        LastName     Salary    Sector\n");

	for (int i = 0; i<len; i++)
	{
		if (list[i].isEmpty == CARGADO)
		{
			showEmployee(list[i]);
		}
	}
	printf("\n________________________________________________________________\n");
	return 0;
}
//---------------------------------------------------------------------------------------
int findEmployeeById(Employee list[], int len,int id)
{
	int retorno;

	retorno = -1;

	for (int i = 0; i < len; ++i)
	{
		if(list[i].id == id)
		{
			retorno = i;
		}
	}
	return retorno;
}
//--------------------------------------------------------------------------------------
void ModificarEmpleado(Employee list[],int index)
{
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int opcionIngresadaModificar;

		do{
			opcionIngresadaModificar = MostrarMenuAModificar();
			 switch (opcionIngresadaModificar) {
				case 1:

					PedirCadena(name,"Ingrese el nombre: ","Error Ingrese solo el nobmre");
					PedirCadena(lastName, "Ingrese el apellido: ", "Error: Ingrese solo el apellido");
					salary = PedirNumeroFlotante(&salary, "Ingrese el salario [0-800k]: ", "Salario Incorrecto, reingrese.\n", 0, 800000.00,5);
					sector = PedirUnEnteroRango("Ingrese el sector: \n 1)Cables Alta Tension \n 2)Lineas Aereas \n 3)Gerencia Distribucion \n 4)Comercial \n 5)Gerencia de Transmision ", 1, 5);
					strcpy(list[index].name, name);
					strcpy(list[index].lastName,lastName);
					list[index].salary = salary;
					list[index].sector = sector;
					printf("\nSe modificaron correctamente los datos del empleado \n");
					break;
				case 2:
					PedirCadena(name,"Ingrese el nombre: ","Error Ingrese solo el nobmre\n");
					PedirCadena(lastName, "Ingrese el apellido: ", "Error: Ingrese solo el apellido\n");
					strcpy(list[index].name, name);
					strcpy(list[index].lastName,lastName);
					printf("\nSe modificaron correctamente el Nombre y Apellido \n");
					break;
				case 3:
					salary = PedirNumeroFlotante(&salary, "Ingrese el salario [0-800k]: ", "Salario Incorrecto, reingrese.\n", 0, 800000.00,5);
					list[index].salary = salary;
					printf("\nSe modifico correctamente el salario. \n");
					break;
				case 4:
					sector = PedirUnEnteroRango("Ingrese el sector: \n 1)Cables Alta Tension \n 2)Lineas Aereas \n 3)Gerencia Distribucion \n 4)Comercial \n 5)Gerencia de Transmision ", 1, 5);
					list[index].sector = sector;
					printf("\nSe modifico correctamente el sector. \n");
					break;

			}
				}while(opcionIngresadaModificar != 5);



}
void HarcodearEmpleados (Employee lista[],int len)
{
Employee listaHardcodeada[] = {{100,"aaaaa","aaaaa",300.13,4,1},{101,"bbbbb","bbbbbb",250.18,6,1}, {102,"dddd","ddddd",850.48,2,1},{103,"zzzzz","zzzz",300.22,4,1}};
	for (int i = 0; i  < 4; i++)
	{
		lista[i]=listaHardcodeada[i];
	}
}
//--------------------------------------------------------------------------------------------
int MostrarMenuAModificar()
{
        int opcionIngresada;


         printf("Ingrese el dato que desea modificar \n");
         printf("1. Todos los datos \n");
         printf("2. Modificar Nombre y Apellido  \n");
         printf("3. Modificar Salario \n");
         printf("4. Modificar Sector \n");
         printf("5. Salir\n");

         opcionIngresada = PedirUnEntero("Ingrese una opcion:");

         return opcionIngresada;
}
//------------------------------------------------------------------------------------------------
int removeEmployee(Employee list[], int len, int id)
{
	int retorno;
	retorno = -1;
	int idAborrar;
	int respuesta;

	idAborrar = findEmployeeById(list, len, id);
	if (idAborrar != -1)
	{

		respuesta = PedirUnEntero("¿Esta seguro que desea borrar el empleado? 1 para confirmar \n");
		if(respuesta == 1)
		{
			list[idAborrar].isEmpty = VACIO;
			printf("Se borro el empleado correctamente \n");
			retorno = 0;
		}
		else{
			printf("No se borro el empleado \n");
		}
	}
	return retorno;
}
//-------------------------------------------------------------------------------------------------------
int sortEmployees(Employee list[], int len, int order)
{
    int retorno;
    int i;
    int j;

    retorno =-1;

    Employee auxEmployee;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
        	if (order == 1 && (strcmp(list[i].lastName, list[j].lastName) > 0 || ((strcmp(list[i].lastName, list[j].lastName)== 0)
        	                                                && (list[j].sector < list[i].sector))))

        	       {
        				 auxEmployee = list[i];
        	             list[i] = list[j];
        	             list[j] = auxEmployee;
        	             retorno = 0;
        	       }
            else if (order == 0 && (strcmp(list[i].lastName, list[j].lastName) < 0 || ((strcmp(list[i].lastName, list[j].lastName)==0)
                    && (list[j].sector < list[i].sector))))

					{
					auxEmployee = list[i];
					list[i] = list[j];
					list[j] = auxEmployee;
					retorno = 0;
					}
        }

    }

    return retorno;
}
//------------------------------------------------------------------------------------
void MostrarMenuCase4(Employee lista[],int len)
{
	int order;
	int opcionDelMenu;
	float promedio;
	int conEmpleadosMayorPromedio;

	conEmpleadosMayorPromedio = 0;

	printEmployees(lista, len);
	do {
			printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector. \n");
			printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n");
			printf("3. Salir del menu \n");
		opcionDelMenu = PedirUnEntero("Ingrese una opcion: ");

		switch (opcionDelMenu) {
			case 1:
				order = PedirUnEntero("Ingrese 0 para ordenar los apellidos de forma DESCENDENTE (Z-A) o 1 para ordenar los apellidos de forma ASCENDENTE (A-Z): \n");
				sortEmployees(lista, len, order);
				printEmployees(lista, len);
				break;
			case 2:
				CalcularPromedio(lista,len,&promedio);
				printf("El promedio de las salarios es : %.2f",promedio);
				BuscarPromedioMasAlto (lista, len, promedio, &conEmpleadosMayorPromedio);
				printf("La cantidad de empleados superan el salario promedio es :%d \n",conEmpleadosMayorPromedio);
				break;
		}

	} while (opcionDelMenu != 3);


}
//------------------------------------------------------------------------------------------
int CalcularPromedio (Employee lista[], int len, float *promedio)
{
	int retorno;
	float acumulador;
	int contador;
	float promedioLocal;

	retorno = -1;
	acumulador = 0;
	contador = 0;

	for (int i = 0;  i< len; i ++)
	{
		if (lista[i].isEmpty == CARGADO && lista[i].salary > 0)
		{
			acumulador = acumulador + lista[i].salary;
			retorno = 0;
		}
	}
	for (int i = 0;  i < len; i ++)
		{
			if (lista[i].isEmpty == CARGADO && lista[i].salary > 0)
			{
				contador++;
			}
		}
	promedioLocal = acumulador / contador;

	if (retorno != -1)
	{
		*promedio = promedioLocal;
	}


	return retorno;
}
//----------------------------------------------------------------------------------
int BuscarPromedioMasAlto (Employee lista[],int len,float promedio, int *conEmpleadosMayorPromedio)
{
	int contadorLocal;
	int retorno;

	retorno = -1;

	contadorLocal = 0;

	for (int i = 0; i < len; ++i)
	{
		if(lista[i].isEmpty == CARGADO && lista[i].salary > promedio)
		{
			contadorLocal ++;
			retorno = 0;
		}
	}
	*conEmpleadosMayorPromedio = contadorLocal;

	return retorno;
}
