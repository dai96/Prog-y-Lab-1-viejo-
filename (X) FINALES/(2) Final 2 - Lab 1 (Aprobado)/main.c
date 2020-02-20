#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Ingredientes.h"

int main()
{
    system("color 0F");
    int option;
    int validateReturn;

    int validateOpenText = 1;
    int validateSaveText = 0;

    LinkedList* listaIngredientes = ll_newLinkedList();
    LinkedList* listaRecetas = ll_newLinkedList();

    controller_firstMessage();

    system("pause");
    system("cls");


    do
    {
        system("color 0F");
        printf("===================================================================\n");
        printf("===================================================================\n");
        printf("== (10) LOAD INGREDIENT DATA FROM INGREDIENTE.csv (TEXT).        ==\n");
        printf("== (9) LOAD RECETAS DATA FROM RECETA.csv (TEXT).                 ==\n");
        printf("\n");
        printf("== (1) ADD NEW INGREDIENT.                                       ==\n");
        printf("== (2) EDIT INGREDIENT.                                          ==\n");
        printf("== (3) REMOVE INGREDIENT.                                        ==\n");
        printf("== (4) LIST INGREDIENT.                                          ==\n");
        printf("== (5) ------------.                                             ==\n");
        printf("== (6) VALOR NUTRICIONAL.                                        ==\n");
        printf("\n");
        printf("== (7) LIST RECETAS                                              ==\n");
        printf("==                                                               ==\n");
        printf("== (11) EXIT.                                                    ==\n");
        printf("===================================================================\n");
        printf("===================================================================\n\n");

        printf("\nSelect your option: ");
        scanf("%d", &option);


        switch(option)
        {

        case 1:
            validateReturn = controller_addIngrediente(listaIngredientes);
            if(validateReturn == 0)
            {
                system("cls");
                system("color 02");
                printf("\nIngredient has been added!\n\n");
            }
            else
            {
                printf("\nIngredient hasn't been added!\n\n");
            }
            break;

        case 2:

            controller_ListIngredientes(listaIngredientes);
            validateReturn = controller_editIngrediente(listaIngredientes);
            if (validateReturn == -1)
            {
                system("cls");
                system("color 04");
                printf("\n*************** The ID doesn't exist.\n\n");
            }
            else
            {
                system("cls");
                system("color 02");
                printf("\n*************** Ingredient has been modify!\n\n");
            }
            break;

        case 3:

            controller_ListIngredientes(listaIngredientes);
            validateReturn = controller_removeIngrediente(listaIngredientes);
            if (validateReturn == -1)
            {
                system("cls");
                system("color 04");
                printf("\n*************** The ID doesn't exist.\n\n");
            }
            else if (validateReturn == -2)
            {
                system("cls");
                system("color 04");
                printf("\n*************** You have cancel the remove.\n\n");
            }
            else
            {
                system("cls");
                system("color 02");
                printf("\n*************** Ingredient removed!\n\n");
            }
            break;

        case 4:
            controller_sortIngrediente(listaIngredientes);
            validateReturn = controller_ListIngredientes(listaIngredientes);
            if (validateReturn == -1)
            {
                printf("\n*************** The list doesn't exist.\n\n");
            }
            else
            {
                printf("\n*************** The list is here!\n\n");
            }
            break;


        case 7:
            controller_ListRecetas(listaRecetas);
            break;

        case 6:
            controller_ListRecetas(listaRecetas);
            controller_ListarValorNutricional(listaRecetas, listaIngredientes);

            break;

        case 9:
            controller_loadFromText("receta.csv", listaRecetas);

            break;

        case 10:
            if (validateOpenText == 1)
            {
                validateReturn = controller_loadFromText("ingrediente.csv",listaIngredientes);
                if (validateReturn == 1)
                {
                    printf("\n*************** File open!\n\n");
                }
                else
                {
                    printf("\nError while trying to open file!\n\n");
                }

            }
            else
            {
                system("cls");
                system("color 04");
                printf("\nYou've already open the file! You'll bug it (TEXT)!!\n\n");
            }
            validateSaveText = 1;
            validateOpenText++;
            break;


        case 11:
            option=11;
            printf("\nExit...\n\n");
            break;

        default:
            printf("You've put a wrong option. Please, try again: ");
        }

        system("pause");
        system("cls");
    }
    while(option != 11);

    return 0;
}
