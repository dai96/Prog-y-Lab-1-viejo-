#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile=fopen(path,"r");

    if(pFile!=NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee);
    }

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int r;

    FILE* pFile;
    pFile=fopen(path,"rb");

    if(pFile!=NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    char horasTrabajadas[20],sueldo[20],id[20],nombre[128];
    int auxId;

    printf("\nNombre: ");
    fflush(stdin);
    scanf("%s",&nombre);

    printf("\nHoras trabajadas: ");
    fflush(stdin);
    scanf("%s",&horasTrabajadas);

    printf("\nSueldo: ");
    fflush(stdin);
    scanf("%s",&sueldo);

    auxId=ll_len(pArrayListEmployee)+1;
    itoa(auxId,id,10);

    pEmployee=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
    ll_add(pArrayListEmployee,pEmployee);
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int horasTrabajadas, sueldo;
    char nombre[128];
    int auxId;

    printf("Ingrese numero de id");
    scanf("%d",&auxId);
    auxId--;
    pEmployee=ll_get(pArrayListEmployee,auxId);

    printf("\nNombre: ");
    fflush(stdin);
    scanf("%s",&nombre);
    strcpy(pEmployee->nombre,nombre);

    printf("\nHoras trabajadas: ");
    fflush(stdin);
    scanf("%d",&horasTrabajadas);
    pEmployee->horasTrabajadas=horasTrabajadas;

    printf("\nSueldo: ");
    fflush(stdin);
    scanf("%d",&sueldo);
    pEmployee->sueldo=sueldo;

    ll_add(pArrayListEmployee,pEmployee);
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int auxId;

    printf("Ingrese numero de id");
    scanf("%d",&auxId);

    ll_remove(pArrayListEmployee,auxId);
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
        Employee* pEmployee;
        int len,i;

        len=ll_len(pArrayListEmployee);

        for (i=0;i<5;i++)
        {
            pEmployee=ll_get(pArrayListEmployee,i);
            printf("\n%d,%s,%d,%d",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
        }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

