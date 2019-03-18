#include <stdlib.h>

typedef struct _listElement *ListElement;
typedef struct _list *List;

List makeList(int (*cmp)(const void *, const void *), void (*destroy)(const void *));
void addFirst(List list, const void *data);
void addLast(List list, const void *data);
void removeFirst(List list);
void removeLast(List list);
void *findElement(List list, const void *data);
int removeElement(List list, const void *data);
void loopList(List list, void (*func)(void *));
void sortList(List list);
