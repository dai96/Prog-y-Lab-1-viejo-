#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Ingredientes.h"
#include "Controller.h"
#include "GetOnly.h"


int controller_loadFromText(char* path, LinkedList* pArrayListPartner)
{
    int retorno = -1;
    FILE* pArchivo;

    if (pArchivo!=NULL)
    {
        pArchivo=fopen(path, "r");
        parser_IngredienteFromText(pArchivo,pArrayListPartner);
        retorno = 1;
    }

    fclose(pArchivo);

    return retorno;
}

/**
int controller_loadFromTextFichaje(char* path, LinkedList* pArrayListFichaje)
{
    int retorno = -1;
    FILE* pArchivo;

    if (pArchivo!=NULL)
    {
        pArchivo=fopen(path, "r");
        parser_FichajeFromText(pArchivo,pArrayListFichaje);
        retorno = 1;
    }

    fclose(pArchivo);

    return retorno;
}
*/



int controller_nextID(LinkedList* pArrayListPartner)
{
    int id = 0;
    int idAnterior;
    int intAuxiliar;
    eIngrediente* pIngrediente;
    int listLen;
    int i;

    if(pArrayListPartner != NULL)
    {
        listLen = ll_len(pArrayListPartner);
        if(listLen > 0)
        {
            for(i = 0; i<listLen; i++)
            {
                pIngrediente = (eIngrediente*)ll_get(pArrayListPartner,i);
                Ingrediente_getId(pIngrediente,&intAuxiliar);
                if(intAuxiliar > id)
                {
                    idAnterior = id;
                    id = intAuxiliar;
                    if(idAnterior + 1 != id)
                    {
                        id = idAnterior;
                        break;
                    }
                }
            }
            id++;

        }
        else
        {
            id = 1;
        }
    }
    return id;
}




int controller_addIngrediente(LinkedList* pArrayListPartner)
{
    eIngrediente* pIngrediente;
    int retorno = -1;

    int idAuxiliar;

    char nombreChar[50];

    char caloriasChar[50];
    int caloriasCharAuxiliar;

    char grasaChar[50];
    int grasaCharAuxiliar;

    char sodioChar[50];
    int sodioCharAuxiliar;

    char carbohidratosChar[50];
    int carbohidratosCharAuxiliar;

    char proteinasChar[50];
    int proteinasCharAuxiliar;


    pIngrediente = Ingrediente_new();

    if(pArrayListPartner != NULL)
    {

        idAuxiliar = controller_nextID(pArrayListPartner);

        printf("Nombre: ");
        fflush(stdin);
        gets(nombreChar);

        while(isOnlyLetters(nombreChar)==0)
        {
            printf("You've put a wrong name. Please, try again: ");
            fflush(stdin);
            gets(nombreChar);
        }
        stringToUpper(nombreChar);

        printf("Inserte calorias: ");
        fflush(stdin);
        gets(caloriasChar);

        while(isNumeric(caloriasChar)==0)
        {
            printf("You've put wrong. Please, try again: ");
            fflush(stdin);
            gets(caloriasChar);
        }
        caloriasCharAuxiliar= atoi(caloriasChar);


        printf("Inserte grasa: ");
        fflush(stdin);
        gets(grasaChar);

        while(isNumeric(grasaChar)==0)
        {
            printf("You've put wrong. Please, try again: ");
            fflush(stdin);
            gets(grasaChar);
        }
        grasaCharAuxiliar= atoi(grasaChar);


        printf("Inserte sodio: ");
        fflush(stdin);
        gets(sodioChar);

        while(isNumeric(sodioChar)==0)
        {
            printf("You've put wrong. Please, try again: ");
            fflush(stdin);
            gets(sodioChar);
        }
        sodioCharAuxiliar= atoi(sodioChar);

        printf("Inserte carbohidratos: ");
        fflush(stdin);
        gets(carbohidratosChar);

        while(isNumeric(carbohidratosChar)==0)
        {
            printf("You've put wrong. Please, try again: ");
            fflush(stdin);
            gets(carbohidratosChar);
        }
        carbohidratosCharAuxiliar= atoi(carbohidratosChar);

        printf("Inserte proteinas: ");
        fflush(stdin);
        gets(proteinasChar);

        while(isNumeric(proteinasChar)==0)
        {
            printf("You've put wrong. Please, try again: ");
            fflush(stdin);
            gets(proteinasChar);
        }
        proteinasCharAuxiliar= atoi(proteinasChar);


        if(pIngrediente != NULL)
        {
            Ingrediente_setId(pIngrediente, idAuxiliar);
            Ingrediente_setNombre(pIngrediente, nombreChar);
            Ingrediente_setCalorias(pIngrediente, caloriasCharAuxiliar);
            Ingrediente_setGrasa(pIngrediente, grasaCharAuxiliar);
            Ingrediente_setSodio(pIngrediente, sodioCharAuxiliar);
            Ingrediente_setCarbohidratos(pIngrediente, carbohidratosCharAuxiliar);
            Ingrediente_setProteinas(pIngrediente, proteinasCharAuxiliar);

            ll_add(pArrayListPartner, pIngrediente);
            retorno = 0;
        }
    }
    return retorno;
}



int controller_editIngrediente(LinkedList* pArrayListIngrediente)
{
    eIngrediente* pIngrediente;

    int retorno = -1;
    int i;

    char idChar[10];
    int idCharAuxiliar;
    int idObtenido;

    char opcionChar[50];
    int opcionCharAuxiliar;


    char nombreChar[50];

    char caloriasChar[50];
    int caloriasCharAuxiliar;

    char grasaChar[50];
    int grasaCharAuxiliar;

    char sodioChar[50];
    int sodioCharAuxiliar;

    char carbohidratosChar[50];
    int carbohidratosCharAuxiliar;

    char proteinasChar[50];
    int proteinasCharAuxiliar;



    if(pArrayListIngrediente != NULL)
    {
        printf("Insert the ID: ");
        fflush(stdin);
        gets(idChar);



        while(isNumeric(idChar)==0)
        {
            printf("You've put a wrong ID. Please, try again: ");
            fflush(stdin);
            gets(idChar);
        }
        idCharAuxiliar=atoi(idChar);

        for(i = 0; i< ll_len(pArrayListIngrediente); i++)
        {
            pIngrediente = ll_get(pArrayListIngrediente,i);
            Ingrediente_getId(pIngrediente,&idObtenido);

            if(idObtenido == idCharAuxiliar)
            {
                do
                {

                printf("===========================================\n");
                printf("Que quiere editar? \n 1) Nombre \n 2) Calorias \n 3) Grasa \n 4) Sodio \n 5) Carbohidratos \n 6) Proteinas \n\n 7) Dejar de editar\n");
                printf("===========================================\n\n");

                printf("\nSelect your option: ");
                fflush(stdin);
                gets(opcionChar);

                while(isNumeric(opcionChar)==0)
                {
                    printf("You've put a wrong option. Please, try again: ");
                    fflush(stdin);
                    gets(opcionChar);
                }
                opcionCharAuxiliar=atoi(opcionChar);

                switch(opcionCharAuxiliar)
                {
                case 1:
                    printf("Nuevo nombre: ");
                    fflush(stdin);
                    gets(nombreChar);

                    while(isOnlyLetters(nombreChar)==0)
                    {
                        printf("You've put a wrong name. Please, try again: ");
                        fflush(stdin);
                        gets(nombreChar);
                    }

                    stringToUpper(nombreChar);
                    retorno = 0;
                    Ingrediente_setNombre(pIngrediente, nombreChar);
                    break;

                case 2:
                    printf("Inserte calorias nuevas: ");
                    fflush(stdin);
                    gets(caloriasChar);

                    while(isNumeric(caloriasChar)==0)
                    {
                        printf("You've put a wrong DNI. Please, try again: ");
                        fflush(stdin);
                        gets(caloriasChar);
                    }

                    caloriasCharAuxiliar= atoi(caloriasChar);
                    retorno = 0;
                    Ingrediente_setCalorias(pIngrediente, caloriasCharAuxiliar);
                    break;

                case 3:
                    printf("Inserte grasa nueva: ");
                    fflush(stdin);
                    gets(grasaChar);

                    while(isNumeric(grasaChar)==0)
                    {
                        printf("You've put a wrong grasa. Please, try again: ");
                        fflush(stdin);
                        gets(grasaChar);
                    }

                    grasaCharAuxiliar= atoi(grasaChar);
                    retorno = 0;
                    Ingrediente_setGrasa(pIngrediente, grasaCharAuxiliar);
                    break;

                case 4:
                    printf("Inserte sodio nuevo: ");
                    fflush(stdin);
                    gets(sodioChar);

                    while(isNumeric(sodioChar)==0)
                    {
                        printf("You've put a wrong sodio. Please, try again: ");
                        fflush(stdin);
                        gets(sodioChar);
                    }

                    sodioCharAuxiliar= atoi(sodioChar);
                    retorno = 0;
                    Ingrediente_setSodio(pIngrediente, sodioCharAuxiliar);
                    break;

                case 5:
                    printf("Inserte carbohidratos nuevos: ");
                    fflush(stdin);
                    gets(carbohidratosChar);

                    while(isNumeric(carbohidratosChar)==0)
                    {
                        printf("You've put a wrong carbohidratos. Please, try again: ");
                        fflush(stdin);
                        gets(carbohidratosChar);
                    }

                    carbohidratosCharAuxiliar= atoi(carbohidratosChar);
                    retorno = 0;
                    Ingrediente_setCarbohidratos(pIngrediente, carbohidratosCharAuxiliar);
                    break;

                case 6:
                    printf("Inserte proteinas nuevas: ");
                    fflush(stdin);
                    gets(proteinasChar);

                    while(isNumeric(proteinasChar)==0)
                    {
                        printf("You've put a wrong DNI. Please, try again: ");
                        fflush(stdin);
                        gets(proteinasChar);
                    }

                    proteinasCharAuxiliar= atoi(proteinasChar);
                    retorno = 0;
                    Ingrediente_setProteinas(pIngrediente, proteinasCharAuxiliar);
                    break;
                case 7:
                    opcionCharAuxiliar=7;
                    printf("\nExit...\n\n");
                    break;


                default:
                    printf("You've put a wrong option. Please, try again: ");
                }
            }while(opcionCharAuxiliar != 7);

            }
        }
    }


    return retorno;
}



int controller_removeIngrediente(LinkedList* pArrayListIngrediente)
{
    char idChar[10];
    int retorno = -1;
    int i;
    int contador = 0;
    int idCharAuxiliar;
    int idObtenido;
    int opcionAConfirmar;

    eIngrediente* pIngrediente;

    if(pArrayListIngrediente != NULL)
    {
        printf("Inserte ID: ");
        fflush(stdin);
        gets(idChar);

        while(isNumeric(idChar)==0)
        {

            printf("You've put a wrong ID. Please, try again: ");
            fflush(stdin);
            gets(idChar);
        }

        idCharAuxiliar=atoi(idChar);


        for(i=0; i< ll_len(pArrayListIngrediente); i++)
        {
            pIngrediente = ll_get(pArrayListIngrediente,i);
            Ingrediente_getId(pIngrediente, &idObtenido);

            if(idObtenido == idCharAuxiliar)
            {

                contador++;



                if (contador == 1)
                {
                    printf("\nVa a remover el ingrediente? (1 CONFIRMATION)\n");
                    printf("1) YES!\n");
                    printf("2) NO!\n");
                    scanf("%d",&opcionAConfirmar);
                }
                else
                {
                    printf("\nAre you sure you want to remove the ingrediente? (2 CONFIRMATION)\n");
                    printf("1) YES!\n");
                    printf("2) NO!\n");
                    scanf("%d",&opcionAConfirmar);
                }

                switch(opcionAConfirmar)
                {

                case 1:
                    Ingrediente_delete(pIngrediente);
                    ll_remove(pArrayListIngrediente,i);
                    retorno = 0;
                    break;

                case 2:
                    retorno = -2;
                    break;

                default:
                    printf("You've put a wrong option. Please, try again: ");
                    retorno = -2;
                    break;
                }

            }
        }
    }

    contador = 0;
    return retorno;
}



int controller_ListIngredientes(LinkedList* pArrayListIngrediente)
{
    int retorno = -1;
    int i;

    int id;
    char nombre[50];
    int calorias;
    int grasa;
    int sodio;
    int carbohidratos;
    int proteinas;

    eIngrediente* pIngrediente;

    if(pArrayListIngrediente != NULL)
    {
        retorno = 0;
        printf("\n\nID -- \t\t   NOMBRE -- CALORIAS -- GRASAS -- SODIO -- CARBOH -- PROTEINAS \n\n");

        for(i=0; i < ll_len(pArrayListIngrediente); i++)
        {
            pIngrediente = ll_get(pArrayListIngrediente,i);

            Ingrediente_getId(pIngrediente,&id);
            Ingrediente_getNombre(pIngrediente, nombre);
            Ingrediente_getCalorias(pIngrediente, &calorias);
            Ingrediente_getGrasa(pIngrediente, &grasa);
            Ingrediente_getSodio(pIngrediente, &sodio);
            Ingrediente_getCarbohidratos(pIngrediente, &carbohidratos);
            Ingrediente_getProteinas(pIngrediente, &proteinas);

            printf("------------------------------------------------------------------------\n");
            printf("%d -- %20s -- %d -- %d -- %d -- %d -- %d\n", id, nombre, calorias, grasa, sodio, carbohidratos, proteinas);
        }
    }
    return retorno;
}


int controller_ListRecetas(LinkedList* pArrayListReceta)
{
    int retorno = -1;
    int i;

    int idReceta;
    char nombreReceta[50];
    int idIngrediente;
    int cantidadIngrediente;

    eReceta* pReceta;

    if(pArrayListReceta != NULL)
    {
        retorno = 0;
        printf("\n\nID -- \t\t   NOMBRE -- ID ING -- CANTIDAD\n\n");

        for(i=0; i < ll_len(pArrayListReceta); i++)
        {
            pReceta = ll_get(pArrayListReceta,i);

            Receta_getidReceta(pReceta,&idReceta);
            Receta_getNombreReceta(pReceta, nombreReceta);
            Receta_getidIngrediente(pReceta, &idIngrediente);
            Receta_getCantidad(pReceta, &cantidadIngrediente);

            printf("------------------------------------------------------------------------\n");
            printf("%d -- %20s -- %d -- %d\n", idReceta, nombreReceta, idIngrediente, cantidadIngrediente);
        }
    }
    return retorno;
}



int controller_sortIngrediente(LinkedList* pArraylistIngrediente)
{
    int retorno = -1;

    if(pArraylistIngrediente != NULL)
    {
        Ingrediente_sortIngrediente(pArraylistIngrediente);
        retorno = 0;
    }

    return retorno;
}

/**
int controller_saveAsText(char* path, LinkedList* pArrayListPartner)
{

    FILE* pArchivo;
    eIngrediente* parterAux;

    int retorno = -1;
    int i;

    int* auxiliarID;
    char* auxiliarNombre;
    char* auxiliarApellido;
    int* auxiliarDNI;
    char* auxiliarClave;

    if(pArrayListPartner != NULL && path != NULL)
    {
        retorno = 1;
        auxiliarID = malloc(sizeof(int));
        auxiliarNombre = malloc(sizeof(char)*100);
        auxiliarApellido = malloc(sizeof(char)*100);
        auxiliarDNI = malloc(sizeof(int));
        auxiliarClave = malloc(sizeof(char)*100);

        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"id,nombre,apellido,dni,clave\n");

        for(i=0; i< ll_len(pArrayListPartner); i++)
        {
            parterAux = ll_get(pArrayListPartner,i);
            Partner_getId(parterAux,auxiliarID);
            Partner_getNombre(parterAux, auxiliarNombre);
            Partner_getApellido(parterAux, auxiliarApellido);
            Partner_getDNI(parterAux,auxiliarDNI);
            Partner_getClave(parterAux, auxiliarClave);
            fprintf(pArchivo,"%d,%s,%s,%d,%s\n",*auxiliarID,auxiliarNombre,auxiliarApellido,*auxiliarDNI, auxiliarClave);
        }

        free(auxiliarNombre);
        free(auxiliarID);
        free(auxiliarApellido);
        free(auxiliarDNI);
        free(auxiliarClave);
        fclose(pArchivo);
    }
    return retorno;
}
*/


void controller_firstMessage (void)
{
    printf("*********************************************************************************\n");
    printf("******************************** READ BEFORE USE ********************************\n");
    printf("******** YOU SHOULD LOAD THE LIST BEFORE USE THE LINKED LIST. IF YOU DONT *******\n");
    printf("**************************** THE LIST WILL BE REMPLACED ************************\n");
    printf("*********************************************************************************\n\n\n");

    printf("*********************************************************************************\n");
    printf("*************** THIS CODE HAS BEEN MADE FOR WINDOWS 7 (32 BITS) ****************\n");
    printf("*********************************************************************************\n\n\n");
}


int controller_ListarValorNutricional(LinkedList* pArrayListRecetas, LinkedList* pArrayListIngredientes)
{
    int retorno = -1;
    int i;
    int j;

    int idReceta;
    char nombreReceta[128];
    int idIngrediente;
    int cantidad;
    char estado[50];



    int id;
    char nombre[128];
    int calorias;
    int grasa;
    int sodio;
    int carbohidratos;
    int proteinas;


    int recetaAVer;

    eReceta* pReceta;
    eIngrediente* pIngrediente;


    if(pArrayListRecetas != NULL && pArrayListIngredientes != NULL)
    {

        printf("Ingrese la receta a ver:");
        scanf("%d", &recetaAVer);

        //printf("\n\nIDF-- \t   IDS \t HORA \tMINUTO \tDIA \tMES \tANIO \tINGRESO\n\n");

            for(i=0; i < ll_len(pArrayListRecetas); i++)
            {
                pReceta = ll_get(pArrayListRecetas,i);
                Receta_getidReceta(pReceta,&idReceta);

                    if (recetaAVer == pReceta->idReceta)
                    {

                        Receta_getNombreReceta(pReceta, nombreReceta);
                        Receta_getidIngrediente(pReceta, &idIngrediente);
                        Receta_getCantidad(pReceta, &cantidad);

                        printf("------------------------------------------------------------------------\n");
                        printf("%d - %s - %d - %d\n", idReceta, nombreReceta, idIngrediente, cantidad);

                        for (j=0; j< ll_len(pArrayListIngredientes); j++)
                        {
                            pIngrediente = ll_get(pArrayListIngredientes,j);
                            Ingrediente_getId(pIngrediente, &id);

                            if (pIngrediente->id == pReceta->idReceta)
                            {
                                Ingrediente_getNombre(pIngrediente, nombre);
                                Ingrediente_getCalorias(pIngrediente, &calorias);
                                Ingrediente_getGrasa(pIngrediente, &grasa);
                                Ingrediente_getSodio(pIngrediente, &sodio);
                                Ingrediente_getCarbohidratos(pIngrediente, &carbohidratos);
                                Ingrediente_getProteinas(pIngrediente, &proteinas);
                            printf("\n\nID -- \t\t   NOMBRE -- CALORIAS -- GRASAS -- SODIO -- CARBOH -- PROTEINAS \n\n");
                            printf("%d  -- %20s-- %d -- %d -- %d -- %d -- %d\n", id, nombre, calorias, grasa, sodio, carbohidratos, proteinas);


                            }




                        }

                    }
            }
    }

    return retorno;
}
