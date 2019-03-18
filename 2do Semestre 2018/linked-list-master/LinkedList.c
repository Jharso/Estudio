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
/*
Elementos que componen la lista
*/
typedef struct _listElement{

    void *data;
    ListElement previous;
    ListElement next;
} Element;

/*
Representa la lista
 */
typedef struct _list{

    unsigned int size; /* Número de elementos en la lista */
    ListElement head; /* Primer elemento de la lista */
    ListElement tail; /* Último artículo en la lista */
    int (*cmp)(const void *, const void *);
    void (*destroy)(const void *);
} Llist;

List makeList(int (*cmp)(const void *, const void *), void (*destroy)(const void *)){
    
    List list = malloc(sizeof(Llist));
    if(!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->cmp = cmp;
    list->destroy = destroy;
    return list;
}

void addFirst(List list, const void *data){

    ListElement element = malloc(sizeof(Element));

    if (list->size == 0){
	element->data = (void *)data;
	element->previous = NULL;
	element->next = NULL;
	list->head = element;
	list->tail = element;
	list->size++;
    }
    else{
	element->data = (void *)data;
	element->previous = NULL;
	element->next = list->head;
	list->head->previous = element;
	list->head = element;
	list->size++;
    }
}

void addLast(List list, const void *data){

    if (list->size == 0){
	addFirst(list, data);
    }
    
    else{
	ListElement element = malloc(sizeof(Element));
	element->data = (void *)data;
	element->previous = list->tail;
	element->next = NULL;
	list->tail->next = element;
	list->tail = element;
	list->size++;
    }
}

void removeFirst(List list){

    ListElement old_element;

    if (list->size > 0){
	old_element = list->head;
	list->head = old_element->next;
	list->head->previous = NULL;
	list->destroy(old_element->data);
	free(old_element->data);
	free(old_element);
	list->size--;
    }
}

void removeLast(List list){
    
    ListElement old_element;

    if (list->size > 0){
	old_element = list->tail;
	list->tail = old_element->previous;
	list->tail->next = NULL;
	list->destroy(old_element->data);
	free(old_element->data);
	free(old_element);
	list->size--;
    }
	
}

void *findElement(List list, const void *data){
    
    ListElement element;
    unsigned int i;
    int code;

    if (list->size > 0){
	element = list->head;
	for(i = 0; (i < (list->size)) && ((code = (list->cmp(element->data, data))) != 0); i++){
	    element = element->next;
	}
    }

    if(code == 0)
	return element->data;
    else
	return NULL;
}

int removeElement(List list, const void *data){

    ListElement element;
    unsigned int i;
    int code;

    if (list->size > 0){
	element = list->head;
	for(i = 0; (i < (list->size)) && ((code = (list->cmp(element->data, data))) != 0); i++){
	    element = element->next;
	}
    }

    if(code == 0){
	ListElement old_element;
	old_element = element;
	element = old_element->previous;
	if(element != NULL){
	    element->next = old_element->next;
	    if((element->next) != NULL){
		element->next->previous = element;
		list->destroy(old_element->data);
		free(old_element->data);
		free(old_element);
		list->size--;
	    }
	    else{
		list->tail = element;
		list->destroy(old_element->data);
		free(old_element->data);
		free(old_element);
		list->size--;
	    }
	}
	else{
	    old_element->next->previous = NULL;
	    element = old_element->next;
	    list->head = element;
	    list->destroy(old_element->data);
	    free(old_element->data);
	    free(old_element);
	    list->size--;
	}
	return 1;
    }
    else
	return 0;
}

void loopList(List list, void (*func)(void *)){

    unsigned int i;
    ListElement element;
    element = list->head;
    if(element == NULL) return;
    for(i = 0; i < list->size; i++){
	func(element->data);
	element = element->next;
    }
}

void sortList(List list){

    ListElement first, second, pred, succ, first2;
    int code;
    
    if((list->size) > 1){
	first = list->head;
	while((first->next)){
	    second = first->next;
	    while((second)){
		code = list->cmp(first->data, second->data);
		if(code == 1) {
		    pred = second->previous;
		    succ = second->next;
		    first2 = first;
		    second->previous = first->previous;
		    first->previous = second;
		    if(first == list->head){
			list->head = second;
		    }
		    second->next = first;
		    if(succ){
			if(succ->previous){
			    succ->previous = pred;
			}
		    }
		    pred->next = succ;
		    if(second->previous){
			second->previous->next = second;
		    }
		    first = second;
		    second = first2;
		}
		else{
		    second = second->next;
		}
		
	    }
	    first = first->next;
	}
    }
    
}
	
    
