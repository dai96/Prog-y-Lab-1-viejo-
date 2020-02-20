#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Ingredientes.h"
#include "parser.h"


int parser_IngredienteFromText(FILE* pFile , LinkedList* pArrayListPartner)
{

    eIngrediente* pIngrediente;

    char auxiliarID[50];
    char auxiliarNombre[50];
    char auxiliarCalorias[50];
    char auxiliarGrasa[50];
    char auxiliarSodio[50];
    char auxiliarCarbohidratos[50];
    char auxiliarProteinas[50];
    int retorno = -1;
    int flagPrimario = 1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

            if(flagPrimario)
            {
                flagPrimario = 0;

                fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxiliarID, auxiliarNombre, auxiliarCalorias, auxiliarGrasa, auxiliarSodio, auxiliarCarbohidratos, auxiliarProteinas);
            }

            fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxiliarID, auxiliarNombre, auxiliarCalorias, auxiliarGrasa, auxiliarSodio, auxiliarCarbohidratos, auxiliarProteinas);
            printf("%s - %s - %s - %s - %s\n", auxiliarID, auxiliarNombre, auxiliarCalorias, auxiliarGrasa, auxiliarSodio, auxiliarCarbohidratos, auxiliarProteinas);

            pIngrediente = Ingrediente_newParametros(auxiliarID, auxiliarNombre, auxiliarCalorias, auxiliarGrasa, auxiliarSodio, auxiliarCarbohidratos, auxiliarProteinas);

            if(pIngrediente != NULL)
            {
                ll_add(pArrayListPartner, pIngrediente);
                retorno = 0;
            }
        }
    }

    return retorno;
}


int parser_RecetaFromText(FILE* pFile , LinkedList* pArrayListReceta)
{

    eReceta* pReceta;

    char auxiliarID[50];
    char auxiliarNombreReceta[50];
    char auxiliarIdIngrediente[50];
    char auxiliarCantidad[50];

    int retorno = -1;
    int flagPrimario = 1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

            if(flagPrimario)
            {
                flagPrimario = 0;

                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxiliarID, auxiliarNombreReceta, auxiliarIdIngrediente, auxiliarCantidad);
            }

            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxiliarID, auxiliarNombreReceta, auxiliarIdIngrediente, auxiliarCantidad);
            printf("%s - %s - %s - %s\n", auxiliarID, auxiliarNombreReceta, auxiliarIdIngrediente, auxiliarCantidad);

            pReceta = Receta_newParametros(auxiliarID, auxiliarNombreReceta, auxiliarIdIngrediente, auxiliarCantidad);

            if(pReceta != NULL)
            {
                ll_add(pArrayListReceta, pReceta);
                retorno = 0;
            }
        }
    }

    return retorno;
}


