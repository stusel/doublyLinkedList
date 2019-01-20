// doublyLinkedList.h
// Author Moritz Stötzner
// created 10.12.18

#define OK 1
#define FAIL 0

struct tlst;
typedef struct tlst tList;

tList* createList   (void);
int deleteList      (tList* pList);

int insertBehind(tList* pList, void* pItemIns);
int insertBefore(tList* pList, void* pItemIns);
int insertHead  (tList* pList, void* pItemIns);
int insertTail  (tList* pList, void* pItemIns);
int removeItem  (tList* pList);

void* getSelected   (tList* pList);
void* getFirst      (tList* pList);
void* getLast       (tList* pList);
void* getNext       (tList* pList);
void* getPrevious   (tList* pList);
void* getIndexed    (tList* pList, int Idx);
