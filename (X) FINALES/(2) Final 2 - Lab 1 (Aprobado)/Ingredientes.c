#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ingredientes.h"


eIngrediente* Ingrediente_new()
{
    eIngrediente* newIngrediente;

    newIngrediente = (eIngrediente*)malloc(sizeof(eIngrediente));

    if(newIngrediente != NULL)
    {
        newIngrediente->id = 0;
        strcpy(newIngrediente->nombre, " ");
        newIngrediente->calorias = 0;
        newIngrediente->grasa = 0;
        newIngrediente->sodio = 0;
        newIngrediente->carbohidratos = 0;
        newIngrediente->proteinas = 0;
    }

    return newIngrediente;
}


eReceta* Receta_new()
{
    eReceta* newReceta;

    newReceta = (eReceta*)malloc(sizeof(eReceta));

    if(newReceta != NULL)
    {
        newReceta->idReceta = 0;
        strcpy(newReceta->nombreReceta, " ");
        newReceta->idIngrediente = 0;
        newReceta->cantidad = 0;
    }

    return newReceta;
}



eReceta* Receta_newParametros(char* idStr, char* nombreRecetaStr, char* idIngredienteStr , char* cantidadStr)
{
    eReceta* newReceta;
    newReceta = Receta_new();

    int auxiliarId;
    int auxiliarIDIngrediente;
    int auxiliarCantidad;

    auxiliarId= atoi(idStr);
    auxiliarIDIngrediente = atoi(idIngredienteStr);
    auxiliarCantidad = atoi(cantidadStr);

    if(newReceta != NULL && idStr != NULL && nombreRecetaStr != NULL && idIngredienteStr != NULL && cantidadStr)
    {
        Receta_setidReceta(newReceta, auxiliarId);
        Receta_setNombre(newReceta, nombreRecetaStr);
        Receta_setidIngrediente(newReceta, auxiliarIDIngrediente);
        Receta_setCantidad(newReceta, auxiliarCantidad);

    }
    return newReceta;
}



eIngrediente* Ingrediente_newParametros(char* idStr, char* nombreStr, char* caloriasStr , char* grasaStr, char* sodioStr, char* carbohidratosStr, char* proteinasStr)
{
    eIngrediente* newIngrediente;
    newIngrediente = Ingrediente_new();

    int auxiliarId;
    int auxiliarCalorias;
    int auxiliarGrasa;
    int auxiliarSodio;
    int auxiliarCarbohidratos;
    int auxiliarProteinas;

    auxiliarId= atoi(idStr);
    auxiliarCalorias = atoi(caloriasStr);
    auxiliarGrasa = atoi(grasaStr);
    auxiliarSodio = atoi(sodioStr);
    auxiliarCarbohidratos = atoi(carbohidratosStr);
    auxiliarProteinas = atoi(proteinasStr);


    if(newIngrediente != NULL && idStr != NULL && nombreStr != NULL && caloriasStr != NULL && grasaStr != NULL && sodioStr != NULL && carbohidratosStr != NULL && proteinasStr != NULL)
    {
        Ingrediente_setNombre(newIngrediente, nombreStr);
        Ingrediente_setId(newIngrediente, auxiliarId);
        Ingrediente_setCalorias(newIngrediente, auxiliarCalorias);
        Ingrediente_setGrasa(newIngrediente, auxiliarGrasa);
        Ingrediente_setSodio(newIngrediente, auxiliarSodio);
        Ingrediente_setCarbohidratos(newIngrediente, auxiliarCarbohidratos);
        Ingrediente_setProteinas(newIngrediente, auxiliarProteinas);
    }
    return newIngrediente;
}

void Ingrediente_delete(eIngrediente* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}


int Ingrediente_setId(eIngrediente* this,int id)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(id >= 0)
        {
            this->id = id;
            retorno = 0;
        }
    }
    return retorno;
}


int Ingrediente_getId(eIngrediente* this,int* id)
{
    int retorno = -1;

    if (this!=NULL && id !=NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;

}

int Ingrediente_setNombre(eIngrediente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}





int Ingrediente_getNombre(eIngrediente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}



int Ingrediente_setCalorias(eIngrediente* this,int calorias)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(calorias >= 0)
        {
            this->calorias = calorias;
            retorno = 0;
        }
    }
    return retorno;
}


int Ingrediente_getCalorias(eIngrediente* this,int* calorias)
{
    int retorno = -1;
    if(this != NULL && calorias != NULL)
    {
        *calorias = this->calorias;
        retorno = 0;
    }
    return retorno;
}


int Ingrediente_setGrasa(eIngrediente* this,int grasa)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(grasa >= 0)
        {
            this->grasa = grasa;
            retorno = 0;
        }
    }
    return retorno;
}


int Ingrediente_getGrasa(eIngrediente* this,int* grasa)
{
    int retorno = -1;
    if(this != NULL && grasa != NULL)
    {
        *grasa = this->grasa;
        retorno = 0;
    }
    return retorno;
}


int Ingrediente_setSodio(eIngrediente* this,int sodio)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(sodio >= 0)
        {
            this->sodio = sodio;
            retorno = 0;
        }
    }
    return retorno;
}


int Ingrediente_getSodio(eIngrediente* this,int* sodio)
{
    int retorno = -1;
    if(this != NULL && sodio != NULL)
    {
        *sodio = this->sodio;
        retorno = 0;
    }
    return retorno;
}

int Ingrediente_setCarbohidratos(eIngrediente* this,int carbohidratos)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(carbohidratos >= 0)
        {
            this->carbohidratos = carbohidratos;
            retorno = 0;
        }
    }
    return retorno;
}


int Ingrediente_getCarbohidratos(eIngrediente* this,int* carbohidratos)
{
    int retorno = -1;
    if(this != NULL && carbohidratos != NULL)
    {
        *carbohidratos = this->carbohidratos;
        retorno = 0;
    }
    return retorno;
}

int Ingrediente_setProteinas(eIngrediente* this,int proteinas)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(proteinas >= 0)
        {
            this->proteinas = proteinas;
            retorno = 0;
        }
    }
    return retorno;
}


int Ingrediente_getProteinas(eIngrediente* this,int* proteinas)
{
    int retorno = -1;
    if(this != NULL && proteinas != NULL)
    {
        *proteinas = this->proteinas;
        retorno = 0;
    }
    return retorno;
}



int Receta_setidReceta(eReceta* this,int idReceta)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(idReceta >= 0)
        {
            this->idReceta = idReceta;
            retorno = 0;
        }
    }
    return retorno;
}





int Receta_setNombre(eReceta* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombreReceta,nombre);
        retorno=0;
    }
    return retorno;
}


int Receta_setidIngrediente(eReceta* this,int idIngrediente)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(idIngrediente >= 0)
        {
            this->idIngrediente = idIngrediente;
            retorno = 0;
        }
    }
    return retorno;
}

int Receta_setCantidad(eReceta* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(cantidad >= 0)
        {
            this->cantidad = cantidad;
            retorno = 0;
        }
    }
    return retorno;
}








int Receta_getNombreReceta(eReceta* this,char* nombreReceta)
{
    int retorno=-1;
    if(this!=NULL && nombreReceta!=NULL)
    {
        strcpy(nombreReceta,this->nombreReceta);
        retorno=0;
    }
    return retorno;
}



int Receta_getidReceta(eReceta* this,int* idReceta)
{
    int retorno = -1;
    if(this != NULL && idReceta != NULL)
    {
        *idReceta = this->idReceta;
        retorno = 0;
    }
    return retorno;
}


int Receta_getidIngrediente(eReceta* this,int* idIngrediente)
{
    int retorno = -1;
    if(this != NULL && idIngrediente != NULL)
    {
        *idIngrediente = this->idIngrediente;
        retorno = 0;
    }
    return retorno;
}

int Receta_getCantidad(eReceta* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}







int Ingrediente_sortIngrediente(LinkedList* pArrayListIngrediente)
{
    int opcion;
    int retorno = -1;

    if(pArrayListIngrediente != NULL)
    {
                printf("\n===========================================\n");
                printf("How do you want to order? \n 1) By Name \n 2)Exit. \n");
                printf("===========================================\n\n");

                printf("\nSelect your option: ");
                scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    printf("\n*************** PLEASE - Wait a moment.\n\n");
                    printf("\n*************** \n\n");
                    printf("\n*************** \n\n");
                    printf("\n*************** DONE.\n\n");
                    ll_sort(pArrayListIngrediente, Ingrediente_ordenarPorNombre, 1);
                    break;

                default:
                    printf("\nInvalid option!");
            }

        retorno = 0;
    }

    return retorno;
}


int Ingrediente_ordenarPorNombre(void* variableA, void* variableB)
{
    char nombreA[50];
    char nombreB[50];
    int retorno = 0;

    Ingrediente_getNombre(variableA, nombreA);
    Ingrediente_getNombre(variableB, nombreB);

    if(stricmp(nombreA, nombreB) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreA, nombreB) < 0)
    {
        retorno = -1;
    }

    return retorno;
}

