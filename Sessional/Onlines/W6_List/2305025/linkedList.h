#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node *next;
    struct node *prev;
} node;

typedef struct
{
    // declare head, tail, cur and other variables you need
    node *head;
    node *tail;
    node *cur;
    int size;
} linkedList;

void init(linkedList *list)
{
    // implement initialization
    list->head = NULL;
    list->cur = NULL;
    list->tail = NULL;
    list->size = 0;
}

void free_list(linkedList *list)
{
    // implement destruction of list
    node *current = list->head;
    node *temp;
    while(current != NULL){
        temp = current->next;
        free(current);
        current = temp;
    }
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL;
    list->size = 0;
}

void print(linkedList *list)
{
    // implement list printing
    if(list->size == 0){
        printf("[ . ]\n");
        return;
    }
    node *temp = list->head;
    printf("[ ");
    while(temp != NULL){
        printf("%d ", temp->element);
        if(temp == list->cur)
            printf("| ");
        else
            printf(" ");
        temp = temp->next;
    }
    printf("]\n");
}


void insert(int item, linkedList *list)
{
    // implement insert function
    node *newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newNode->element = item;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(list->cur == NULL){
        list->head = list->tail = list->cur = newNode;
    }
    else{
        newNode->prev = list->cur;
        newNode->next = list->cur->next;

        if(list->cur->next != NULL)
            list->cur->next->prev = newNode;
        else
            list->tail = newNode;

        list->cur->next = newNode;
        list->cur = newNode;
    }

    list->size++;
    print(list); 
}

int delete_cur(linkedList *list)
{
    // implement deletion of current index function
    if(list->cur == NULL)
        return -1;

    node *temp = list->cur;
    int deleted = temp->element;

    if(list->head == list->tail){        // single element
        list->head = list->tail = list->cur = NULL;
    }
    else if(list->cur == list->head){   // delete head
        list->head = list->cur->next;
        list->head->prev = NULL;
        list->cur = list->head;
    }
    else if(list->cur == list->tail){    // delete tail
        list->tail = list->cur->prev;
        list->tail->next = NULL;
        list->cur = list->tail;
    }
    else{                              // delete middle
        list->cur->prev->next = list->cur->next;
        list->cur->next->prev = list->cur->prev;
        list->cur = list->cur->next;
    }
    free(temp);
    list->size--;
    print(list);
    return deleted;
}

void append(int item, linkedList *list)
{
    // implement append function
    node *newNode = (node *)malloc(sizeof(node));
    newNode->element = item;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if(list->tail != NULL)
        list->tail->next = newNode;
    else
        list->head = newNode;

    list->tail = newNode;
    list->cur = newNode;
    list->size++;
    print(list);
}

int size(linkedList *list)
{
    // implement size function
    return list->size;
}

void prev(int n, linkedList *list)
{
    // implement prev function
    while(n > 0 && list->cur != NULL && list->cur->prev != NULL){
        list->cur = list->cur->prev;
        n--;
    }
    print(list);
}

void next(int n, linkedList *list)
{
    // implement next function
    while(n > 0 && list->cur != NULL && list->cur->next != NULL){
        list->cur = list->cur->next;
        n--;
    }
    print(list);
}

int is_present(int n, linkedList *list)
{
    // implement presence checking function
    node *temp = list->head;
    while(temp != NULL){
        if(temp->element == n)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void clear(linkedList *list)
{
    // implement list clearing function
    free_list(list);
    init(list);
}

void delete_item(int item, linkedList *list)
{
    // implement item deletion function
    node *temp = list->head;
    while(temp != NULL){
        if(temp->element == item){
            list->cur = temp;
            delete_cur(list);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found\n", item);
}

void swap_ind(int ind1, int ind2, linkedList *list)
{
    // implement swap function
    if(ind1 == ind2)
        return;

    node *n1 = list->head;
    node *n2 = list->head;
    int i = 0;

    while(n1 != NULL && i < ind1){
        n1 = n1->next;
        i++;
    }

    i = 0;
    while(n2 != NULL && i < ind2){
        n2 = n2->next;
        i++;
    }

    if(n1 != NULL && n2 != NULL){
        int temp = n1->element;
        n1->element = n2->element;
        n2->element = temp;
    }
    print(list);
}

// you can define helper functions you need

void reverse_pos(int ind1, int ind2, linkedList *list){
    if(ind1 == ind2)
        return;
    
    if (ind1 < 0 || ind1 >= list->size || ind2 < 0 || ind2 >= list->size)
    {
        printf("Reverse indices out of bounds\n");
        return;
    }
    int x = ind1, y = ind2;

    node *n1 = list->head;
    node *n2 = list->head;
    int i = 0;

    while(n1 != NULL && i < ind1){
        n1 = n1->next;
        i++;
    }

    i = 0;
    while(n2 != NULL && i < ind2){
        n2 = n2->next;
        i++;
    }
    while(n1!=n2){
        int temp = n1->element;
        n1->element = n2->element;
        n2->element = temp;
        n1 = n1->next;
        n2 = n2->prev;
    }

    print(list);
}