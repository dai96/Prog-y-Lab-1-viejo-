#ifndef Partner_H_INCLUDED
#define Partner_H_INCLUDED

#define TAMNOMBRE 100

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int calorias;
    int grasa;
    int sodio;
    int carbohidratos;
    int proteinas;
    int isEmpty;
}eIngrediente;

typedef struct
{
    int idReceta;
    char nombreReceta[128];
    int idIngrediente;
    int cantidad;
    int isEmpty;
}eReceta;



/** \brief Function that build a new Partner.
 * \param   void
 * \return  (NULL) not enough memory to create the new Partner.
 *          Partner* - Everything has worked.
 */
eIngrediente* Partner_new();

eReceta* Receta_new();


/** \brief Function that creates a new Partner with parameters in.
 *
 * \param idStr char*               Contains id.
 * \param nombreStr char*           Contains name.
 * \param horasTrabajadasStr char*  Contains work hours.
 * \param sueldoStr char*           Contains salary.
 * \return Partner*                NULL - Not enough memory / Parameters are void.
 *                                  0    - Everything has worked.
 */
eIngrediente* Ingrediente_newParametros(char* idStr, char* nombreStr, char* caloriasStr , char* grasaStr, char* sodioStr, char* carbohidratosStr, char* proteinasStr);

eReceta* Receta_newParametros(char* idStr, char* nombreRecetaStr, char* idIngredienteStr , char* cantidadStr);

//eFichaje* Fichaje_newParametros(char* idFichajeStr, char* idSocioStr, char* horaStr, char* minutoStr, char* diaStr, char* mesStr, char* anioStr, char* estadoStr);

/** \brief Function that delete an Partner.
 *
 * \param this Partner*            - Partner that will be deleted.
 * \return void                     - VOID.
 *
 */
void Partner_delete(eIngrediente* this);




/** \brief Function that set ID.
 *
 * \param this Partner*            - Partner that will set the ID.
 * \param id int                    - New ID.
  * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_setId(eIngrediente* this,int id);




/** \brief Function that get ID.
 *
 * \param this Partner*            - Partner where the function get the ID
 * \param id int*                   - Current ID.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_getId(eIngrediente* this,int* id);




/** \brief Function that set name.
 *
 * \param this Partner*            - Partner that will set the name.
 * \param nombre char*              - New name.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_setNombre(eIngrediente* this,char* nombre);




/** \brief Function that get name.
 *
 * \param this Partner*            - Partner where the function get the name.
 * \param nombre char*              - Current name.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_getNombre(eIngrediente* this,char* nombre);



/** \brief Function that set name.
 *
 * \param this Partner*            - Partner that will set the name.
 * \param nombre char*              - New name.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_setCalorias(eIngrediente* this,int calorias);




/** \brief Function that get name.
 *
 * \param this Partner*            - Partner where the function get the name.
 * \param nombre char*              - Current name.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_getCalorias(eIngrediente* this,int* calorias);


/** \brief Function that set work hours.
 *
 * \param this Partner*            - Partner that will set the work hours.
 * \param horasTrabajadas int       - New work hours.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_setGrasa(eIngrediente* this,int grasa);




/** \brief Function that get work hours.
 *
 * \param this Partner*            - Partner where the function get the work hours.
 * \param horasTrabajadas int*      - Current salary.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_getGrasa(eIngrediente* this,int* grasa);




/** \brief Function that set name.
 *
 * \param this Partner*            - Partner that will set the name.
 * \param nombre char*              - New name.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_setSodio(eIngrediente* this,int sodio);




/** \brief Function that get name.
 *
 * \param this Partner*            - Partner where the function get the name.
 * \param nombre char*              - Current name.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_getSodio(eIngrediente* this,int* sodio);


int Ingrediente_setCarbohidratos(eIngrediente* this,int carbohidratos);
int Ingrediente_getCarbohidratos(eIngrediente* this,int* carbohidratos);
int Ingrediente_setProteinas(eIngrediente* this,int proteinas);
int Ingrediente_getProteinas(eIngrediente* this,int* proteinas);


int Receta_setidReceta(eReceta* this,int idReceta);
int Receta_setNombre(eReceta* this,char* nombre);
int Receta_setidIngrediente(eReceta* this,int idIngrediente);
int Receta_setCantidad(eReceta* this,int cantidad);




int Receta_getNombreReceta(eReceta* this,char* nombreReceta);
int Receta_getidReceta(eReceta* this,int* idReceta);
int Receta_getidIngrediente(eReceta* this,int* idIngrediente);
int Receta_getCantidad(eReceta* this,int* cantidad);

/**
int Fichaje_setIDSocio(eFichaje* this,int idSocio);
int Fichaje_setIDFichaje(eFichaje* this,int idFichaje);
int Fichaje_setHora(eFichaje* this,int hora);
int Fichaje_setMinuto(eFichaje* this,int minuto);
int Fichaje_setDia(eFichaje* this,int dia);
int Fichaje_setMes(eFichaje* this,int mes);
int Fichaje_setAnio(eFichaje* this,int anio);
int Fichaje_setEstado(eFichaje* this,char* estado);



int Fichaje_getIDSocio(eFichaje* this,int* idSocio);
int Fichaje_getIDFichaje(eFichaje* this,int* idFichaje);
int Fichaje_getHora(eFichaje* this,int* hora);
int Fichaje_getMinuto(eFichaje* this,int* minuto);
int Fichaje_getDia(eFichaje* this,int* dia);
int Fichaje_getMes(eFichaje* this,int* mes);
int Fichaje_getAnio(eFichaje* this,int* anio);
int Fichaje_getEstado(eFichaje* this,char* estado);
*/

/** \brief Function that sort the Partner list.
 *
 * \param pArrayListPartner LinkedList*    -List will be sorted.
 * \return int                              - (0) - Work everything // (-1) - NULL
 *
 */
int Ingrediente_sortIngrediente(LinkedList* pArrayListIngrediente);




/** \brief Function that sort by salary.
 *
 * \param DNIA void*                   - Variable A to be compared.
 * \param DNIB void*                   - Variable B to be compared.
 * \return int                              (1) / (-1) Compared // (0) - NULL
 *
 */
int Ingrediente_ordenarPorNombre(void* variableA, void* variableB);



#endif // Partner_H_INCLUDED
