/* Doubly Linked List implementation */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "doublyLinkedList.h"

typedef struct Cnctr
{
    struct Cnctr* pNext;
    struct Cnctr* pPrev;
    void* pItem;
} tCnct;

typedef struct tlst
{
    tCnct Head;
    tCnct* pCurr;
} tList;

tList* createList()
{
    tList* pList;
    pList = (tList*) malloc(sizeof(tList));
    if(pList)
    {
        pList->pCurr = NULL;
        pList->Head.pNext = (tCnct*) pList;
        pList->Head.pPrev = (tCnct*) pList;
    }
    return pList;
}

int insCnctBehCnct(tCnct* pBef, void* pIn)
{
    tCnct* tmp;
    tmp = malloc(sizeof(tCnct));
    if (tmp)
    {
        tmp->pItem = pIn;
        tmp->pNext = pBef->pNext;
        tmp->pPrev = pBef->pNext->pPrev;
        tmp->pNext->pPrev = tmp;
        pBef->pNext = tmp;
        
    }
    
    return tmp ? OK : FAIL;
}

int insertHead  (tList* pList, void* pItemIns)
{
    return insCnctBehCnct(&(pList->Head), pItemIns);
}

int insertTail  (tList* pList, void* pItemIns)
{
    return insCnctBehCnct(pList->Head.pPrev, pItemIns);
}

void* getFirst(tList* pList)
{
    pList->pCurr = pList->Head.pNext;
    return pList->pCurr->pItem;
}

void* getNext(tList* pList)
{
    pList->pCurr = pList->pCurr->pNext;
    return pList->pCurr->pItem;
}

//int removeItem  (tList* pList)
//{
    //pList->pCurr->pPrev
//}

// testing the list
int main(int argc, char* args[])
{
    tList* myList = createList();
    for(int i = 1; i <  argc && args[i] ; i++)
    {
        insertHead(myList, args[i]);
    }
    for(char* pc = getFirst(myList);
        pc;
        pc = getNext(myList)
    )
        printf("%s\n", pc);
    
    return 0;
}



