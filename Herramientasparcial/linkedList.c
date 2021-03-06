#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this=(LinkedList*)malloc(sizeof(LinkedList));

    if (this!=NULL)
    {
        this->size=0;
        this->pFirstNode=NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux=-1;
    if (this!=NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* returnAux=NULL;
    int i;

    if (this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        returnAux=this->pFirstNode;//guarda en el aux la dire del primer nodo indice 0

        for (i=0; i<nodeIndex; i++)//recorre hasta el indice
        {
            returnAux=returnAux->pNextNode;//el aux tiene la dire del prox nodo
        }
    }

    return returnAux;// regresa el nodo aux
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{

    int returnAux = -1, i;
    Node* aux;
    Node* aux2;
    Node* aux3;
    if (this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
        if (nodeIndex==0)
        {
            aux=malloc(sizeof(Node));
            aux->pElement=pElement;
            aux2=this->pFirstNode;
            aux->pNextNode=aux2;
            this->pFirstNode=aux;
            returnAux=0;
            this->size++;
        }
        else if (nodeIndex!=0)
        {
            aux=malloc(sizeof(Node));
            aux->pElement=pElement;
            aux2=getNode(this,nodeIndex);
            aux->pNextNode=aux2;
            aux3=getNode(this,nodeIndex-1);
            aux3->pNextNode=aux;
            returnAux=0;
            this->size++;
        }


    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)

{
    int returnAux = -1,aux;

    if (this!=NULL)
    {
        aux=addNode(this,ll_len(this),pElement);
        if (aux==0)
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Obtiene el elemento del indice pasado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* aux;

    if (this!=NULL && index>=0 && index<ll_len(this))
    {
        aux=getNode(this,index);
        if (aux!=NULL)
        {
            returnAux=aux->pElement;
        }

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* aux;
    if (this!=NULL && index>=0 && index<ll_len(this))
    {
        aux=getNode(this,index);
        if (aux!=NULL)
        {
            aux->pElement=pElement;
            returnAux=0;
        }

    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* aux, *aux2;
    if (this!=NULL && index>=0 && index<ll_len(this))
    {
        aux=getNode(this,index);
        if (index==0)
        {
            this->pFirstNode=this->pFirstNode->pNextNode;
            this->size--;
            free(aux->pElement);
            free(aux);
            returnAux=0;
        }
        else if (index!=0)
        {
            aux2=getNode(this,index-1);
            aux2->pNextNode=aux->pNextNode;
            free(aux->pElement);
            free(aux);
            this->size--;
            returnAux=0;
        }

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1,i,aux,flag=0;

    if (this!=NULL)
    {
        for (i=0; i<ll_len(this); i++)
        {
            aux=ll_remove(this,i);
            if (aux==-1)
            {
                flag=1;
            }
        }
        if (flag==0)
        {
            returnAux=0;
        }

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1,aux;
    if (this!=NULL)
    {
        aux=ll_clear(this);
        free(this);
        if (aux==0)
        {
            returnAux=0;
        }

    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1, i;
    Node* aux;
    if (this!=NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            aux=getNode(this,i);
            if (aux!=NULL && aux->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1,len;
    if (this!=NULL)
    {
        len=ll_len(this);
        if (len==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if (this!=NULL && index>=0 && index<=ll_len(this))
    {
        returnAux=addNode(this,index,pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if (this!=NULL && index>=0 && index<ll_len(this))
    {

        returnAux=ll_get(this,index);
        ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1,i;
    if(this!=NULL)
    {
        i=ll_indexOf(this,pElement);
        if (i!=-1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{

    int returnAux = -1,contador=0,i;
    void* aux;

    if (this!=NULL && this2!=NULL)
    {
        returnAux=0;
        if (ll_len(this)>=ll_len(this2))
        {
            for (i=0; i<ll_len(this2); i++)
            {
                aux=ll_get(this2,i);
                if (ll_contains(this,aux)==1)
                {
                    contador++;
                }
            }
            if (contador==ll_len(this))
            {
                returnAux=1;
            }
        }

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    Node* aux;
    if (this!=NULL && from>=0 && from<=ll_len(this) && to>=0 && to<=ll_len(this))
    {
        cloneArray=ll_newLinkedList();
        for (i=from; i<to; i++)
        {
            aux=getNode(this,i);
            if (aux!=NULL)
            {
                addNode(cloneArray,i,aux->pElement);
            }

        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if (this!=NULL)
    {
        cloneArray=ll_subList(this,0,this->size);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    //?
    int returnAux =-1;

    void* pElementUno;
    void* pElementDos;
    void* pElementAux;
    int i;
    int flag;
    int len;

    if(this!=NULL)
    {
        if (pFunc!= NULL)
        {
            if (order == 0 || order == 1)
            {
                len = ll_len(this);
                if(len > 0)
                {
                    do
                    {
                        flag = 0;
                        for(i=0; i<len-1; i++)
                        {
                            pElementUno = ll_get(this,i);
                            pElementDos = ll_get(this,i+1);

                            if((pFunc(pElementUno, pElementDos) <0 && order==0) || (pFunc(pElementUno, pElementDos) >0 && order==1))
                            {
                                pElementAux = pElementUno;
                                ll_set(this,i,pElementDos);
                                ll_set(this,i+1,pElementAux);
                                flag=1;
                            }
                            returnAux=0;
                        }
                    }
                    while(flag);
                }
            }
        }
    }
    return returnAux;

}


