#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee* e1;
    Employee* e2;
    int retorno;

    e1=(Employee*)pEmployeeA;
    e2=(Employee*)pEmployeeB;

    retorno= strcmp(e1->name,e2->name);

    return retorno;

}

void employee_print(Employee* this)
{
    printf("\n-----------\nID: %d\nNombre: %s\nApellido: %s",this->id,this->name,this->lastName);
}


int employee_new(Employee* lista)
{
    int i;
    Employee* aux;
    ArrayList* lista;
    lista =al_newArrayList();//hace un malloc.
    Employee* e1;
    e1=(Employee*)malloc(sizeof(Employee));
    if (e1!=NULL)
    {
        e1


        e1->id=4;
        strcpy(e1->name,"Dai");
        strcpy(e1->lastName,"Minarro");
        al_add(lista,e1);

    }




    return 0 ;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{
    int retorno=-1;
    if(this!=NULL&&id>0)
    {
        retorno=1;
      this->id=id;
    }
    return retorno;


}

int employee_getId(Employee* this)
{

    int retorno=-1;
    if(this!=NULL)
    {
       retorno=this->id;
    }
    return retorno;

}


