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


    return 0 ;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


