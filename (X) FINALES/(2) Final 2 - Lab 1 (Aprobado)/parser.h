
/** \brief Parsea los datos de los empleados desde el archivo socios.csv (modo texto).
 *
 * \param pArrayListPartner LinkedList*                -List.
 * \return int                                          NULL - Not enough memory. // (-1) NULL // (0) Everything works.
 *
 */
int parser_IngredienteFromText(FILE* pFile , LinkedList* pArrayListPartner);


/** \brief Parsea los datos de los empleados desde el archivo fichajes.csv (modo texto).
 *
 * \param pArrayListPartner LinkedList*                -List.
 * \return int                                          NULL - Not enough memory. // (-1) NULL // (0) Everything works.
 *
 */
int parser_RecetaFromText(FILE* pFile , LinkedList* pArrayListReceta);
