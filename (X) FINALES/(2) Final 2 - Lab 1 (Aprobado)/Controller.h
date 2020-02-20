/** \brief Load the data from the file data.csv (text mode).
 *
 * \param path char*                                - Direction / Name where the data is load.
 * \param pArrayListEmployee LinkedList*            - List where data is load.
 * \return int                                      - (-1) NULL // (1) Everything works.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

int controller_loadFromTextFichaje(char* path, LinkedList* pArrayListFichaje);


/** \brief
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee is.
 * \return int                                      - (-1) NULL // (X) Next ID.
 *
 */
int controller_nextID(LinkedList* pArrayListEmployee);


/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be add.
 * \return int                                      - (-1) NULL // (0) Employee added.
 *
 */
int controller_addIngrediente(LinkedList* pArrayListPartner);


/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be edited.
 * \return int                                      - (-1) NULL // (0) Employee edited.
 *
 */
int controller_editIngrediente(LinkedList* pArrayListIngrediente);


/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be removed.
 * \return int                                      - (-1) NULL // (0) Employee removed. // (-2) Canceled.
 *
 */
int controller_removeIngrediente(LinkedList* pArrayListIngrediente);


/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be list.
 * \return int                                      - (-1) NULL // (0) Employee listed.
 *
 */
int controller_ListIngredientes(LinkedList* pArrayListIngrediente);





int controller_ListFichajePorFecha(LinkedList* pArrayListFichaje, LinkedList* pArrayListPartner);


/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be sorted.
 * \return int                                      - (-1) NULL // (0) Employee sorted.
 *
 */
int controller_sortIngrediente(LinkedList* pArraylistIngrediente);


/** \brief Save the data into the file data.csv (text mode).
 *
 * \param path char*                                - Direction / Name where the data is save.
 * \param pArrayListEmployee LinkedList*            - List where data is save.
 * \return int                                      - (-1) NULL // (1) Everything works.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Show message
 *
 * \param                                           -void.
 * \return                                          -void.
 *
 */
void controller_firstMessage (void);

int controller_ListarValorNutricional(LinkedList* pArrayListRecetas, LinkedList* pArrayListIngredientes);
