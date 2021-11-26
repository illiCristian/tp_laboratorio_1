#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

	setbuf(stdout,NULL);

    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    int flagCarga;

    flagCarga = 0;




    printf("%d",option);
    do{
    	option = MostrarMenu();

        switch(option)
        {
            case 1:
                if(flagCarga== 0)
                {
                	controller_loadFromText("data.csv",listaEmpleados);
                	printf("Carga Completada \n");
                	flagCarga =1;
                }
                else
                {
                	 printf("Ya cargo un archivo previamente!!.\n");
                }
                break;
            case 2:
            	if(flagCarga == 0 && controller_loadFromBinary("data.bin",listaEmpleados)!=-1)
            	{
            		printf("Carga Completada \n");
            		flagCarga =1;
            	}
            	else
            	{
            		 printf("Ya cargo un archivo previamente!! \n");
            	}
            	break;
            case 3:
            	if(flagCarga == 1 && controller_addEmployee(listaEmpleados)!= -1)
            	{
            		printf("Empleado cargado correctamente \n");
            	}else
            	{
            		printf("Cargue su lista de empleados primero para realizar esta acción.\n");
            	}
            	break;
            case 4:
            	if (flagCarga == 1)
            	{
            	if(controller_editEmployee(listaEmpleados)!=-1)
            		{
            		printf("Empleado Editado Correctamente");
            		}
            	}else
            		{
            		printf("Cargue su lista de empleados primero para realizar esta acción.\n");
            	}
            	break;
            case 5:
            	if (flagCarga == 1)
            	{
            		if(controller_removeEmployee(listaEmpleados)!=-1)
						{
							printf("Empleado borrado correctamente");
						}
            	}
            	else
            	{
            		printf("Por favor cargue su lista de empleados primero para realizar esta acción.\n");
            	}
            	break;
            case 6:
            	if(controller_ListEmployee(listaEmpleados)!=-1 && flagCarga == 1)
            	{
            		printf("Se muestra la lista ordenada \n");
            	}else
            	{
            		printf("Error al mostrar la lista, pruebe cargando el archivo \n");
            	}
            	break;

            case 7:
            	if(flagCarga == 1)
            	{
					controller_sortEmployee(listaEmpleados);
            	}else
            	{
            		printf("Cargue su lista de empleados primero para realizar esta acción.\n");
            	}

            	break;
            case 8:
            	if(flagCarga == 1)
            	{
            		if(controller_saveAsText("data.csv", listaEmpleados)!=-1 &&
            		   controller_saveAsBinary("data.bin", listaEmpleados)!=-1)
            		{
            		printf("Guardado Correctamente .\n");

            		}
            	}
            	else

            	{
            		printf("No se puede guardar si no se cargó el archivo primero!\n");
            	}

                break;
            case 9:
            	if(flagCarga == 1)
            	{
            		if(controller_saveAsText("data2.csv", listaEmpleados)!=-1 &&
            		   controller_saveAsBinary("data2.bin", listaEmpleados)!=-1)
            		{
            		printf("Guardado Exitoso \n");

            		}
            	}else

            	{
            		printf("No se puede guardar si no se cargó el archivo primero!\n");
            	}
            	break;
            case 10:
    			if(ll_deleteLinkedList(listaEmpleados)!=-1)
    			{
    				printf("Cerrado exitoso \n");
    			}
    			break;
        }

    }while(option != 10);
    return 0;
}



