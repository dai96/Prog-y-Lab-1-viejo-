#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/
//primera parte del arcial, segunda par

int main()
{
    int i;
    int tamaniopunteo;
    Employee* aux;
    ArrayList* lista;
    lista =al_newArrayList();//hace un malloc.
    Employee* e1;
    e1=(Employee*)malloc(sizeof(Employee));
    if (e1!=NULL)
    {
        e1->id=4;
        strcpy(e1->name,"Dai");
        strcpy(e1->lastName,"Minarro");
        al_add(lista,e1);
        tamaniopunteo=al_len(lista);
        //printf("%d",tamaniopunteo);-->en los dos casos me da 1?
    }

    Employee* e2;
    e2=(Employee*)malloc(sizeof(Employee));
    if (e2!=NULL)
    {
        e2->id=2;
        strcpy(e2->name,"Pueds");
        strcpy(e2->lastName,"Flo");
        al_add(lista,e2);
        //printf("\n%d",tamaniopunteo);En los dos casos me da 1?
    }

    for (i=0;i<2;i++)
    {
    aux=(Employee*)al_get(lista,i);
    employee_print(aux);
    }

   al_sort(lista, employee_compare,0);


   for (i=0;i<2;i++)
    {
    aux=(Employee*)al_get(lista,i);
    employee_print(aux);
    }

    /*
    //aux=al_get(lista,0); lo de abajo es mejor
    aux=(Employee*)al_get(lista,0);
    printf("\niD: %d",aux->id);
    printf("\nNombre: %s",aux->name);
    printf("\nApellido: %s",aux->lastName);
    aux=(Employee*)al_get(lista,1);
    printf("\niD: %d",aux->id);
    printf("\nNombre: %s",aux->name);
    printf("\nApellido: %s",aux->lastName);
    */


}

