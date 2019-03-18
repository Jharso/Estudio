#include <stdio.h>
#include <stdlib.h>
#include <libio.h>
#include <errno.h>

/* This struct is the node of the list */
typedef struct node{
    void *data;        // pointer to the generic content
    struct node *prev; // pointer to the previous node
    struct node *next; // pointer to the next node
} node;

/* =========================PROTOTYPES=========================*/

void * my_malloc();

long list_get_quantity();

node * list_create();

void list_add(void *data);

void list_insert(void *data, long index);

void * list_get(long index);

void * list_get_last();

void list_remove(long index);

void list_remove_last();

void list_wipe();

/* =========================GLOBAL_VARIABLES=========================*/

node *head;                 // pointer to first node of the list
node *tail;                 // pointer to the last node of the lis
long *currentNodes = 0;     // node's quantity

int main(int argc, char **argv[]){
    int val = -500;
    node *lista = list_create();
    list_add(&val);
    return 0;
}

/* =========================IMPLEMENTATION=========================*/

/* safer version of malloc function */
void * my_malloc(size_t size){

    // allocates space for 'size'
    void *p = malloc(size);

    // verifies correct allocation
    if (p == NULL){

        // prints error number
        fprintf(stderr, "[myMalloc] - Fatal error allocating data. Errno = %i.\n",errno);
        
        // exits with failure
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "[myMalloc] - Success. %i byte/s of data allocated.\n", size);
    return p;
}

/* returns how many nodes are in the list */
long list_get_quantity(){
    return *currentNodes;
}

/* initializes the list and returns its head */
node * list_create(){

    printf("Creating list   => ");
    // allocates the head
    head = my_malloc(sizeof(node));

    // initializes head
    head->next = NULL;
    head->prev = NULL;
    head->data = NULL;

    // allocates the counter
    currentNodes = malloc(sizeof(long));

    // initializes the counter
    *currentNodes = 0;

    // initializes tail
    tail = head;

    return head;
}

/* appends a node to the list */
void list_add(void *data){

    printf("Allocating node => ");
    // allocates space for the new node
    node *n = my_malloc(sizeof(node));

    //printf("Allocating data => ");
    // allocates space for the data
    n->data = data;
    printf("Node added. Data => %p.\n", *data);

    // initializes new node pointers
    n->next = NULL;
    n->prev = NULL;

    // list is empty
    if (head->data == NULL){
        // new node is now the head of the list
        head = n;
    }
    // list is not empty
    else{
        // old last node connects to new node 
        tail->next = n;

        // new node connects to old last node
        n->prev = tail;        
    }

    // new node is now the tail
    tail = n;

    // updates nodes
    *currentNodes++;
}

/* inserts a new node to the list in the index provided */
void list_insert(void *data, long index){


}


void * list_get(long index){

}


void * list_get_last(){

}

/* removes the node at the provided index */
void list_remove(long index){
    // auxiliar pointer to tail
    node *p = tail;

    if(index < 0 || index > *currentNodes){
        return;
    }


    // updates nodes
    *currentNodes--;


}

/* removes the last node of the list */
void list_remove_last(){
    // auxiliar pointer to tail
    node *p = tail;

    // it is the only node in the list
    if (head == tail){
        head = tail = NULL;
    }else{
        // updates tail to the previous node of tail
        tail = tail->prev;

        // updates tail's next node
        tail->next = NULL;
    }

    // frees allocated spaces
    free(p->data);
    free(p);

    // updates nodes
    *currentNodes--;
}

/* wipes completely the list */
void list_wipe(){



    *currentNodes = 0;

}