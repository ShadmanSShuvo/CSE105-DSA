#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node* next;
    struct node* prev;
} node;

typedef struct 
{
    // declare head, tail, cur and other variables you need
    node* head;
    node* tail;
    node* cur;
    int size;
    // int capacity;
} linkedList;

void init(linkedList* list)
{
    // implement initialization
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL;
    list->size = 0;
}

void free_list(linkedList* list)
{
    // implement destruction of list
    node* current = list->head;
    node* next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL;
    list->size = 0;
}

void print(linkedList* list)
{
    // implement list printing
    if (list->size == 0)
    {
        printf("[ . ]\n");
        return;
    }
    node* current = list->head;
    printf("[ ");
    while (current != NULL)
    {
        printf("%d ", current->element);
        if (current == list->cur)
            printf("| ");
        else
            printf(" ");
        current = current->next;
    }
    printf("]\n");
}

void insert(int item, linkedList* list)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->element = item;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (list->cur == NULL) {
        list->head = list->tail = list->cur = new_node;
    } else if (list->cur == list->head) {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
        list->cur = new_node;
    } else {
        new_node->next = list->cur;
        new_node->prev = list->cur->prev;
        list->cur->prev->next = new_node;
        list->cur->prev = new_node;
        list->cur = new_node;
    }
    list->size++;
    print(list);
}

int delete_cur(linkedList* list)
{
    if (list->cur == NULL) return -1;

    node* temp = list->cur;
    int deleted = temp->element;

    if (list->head == list->tail) {
        list->head = list->tail = list->cur = NULL;
    } else if (list->cur == list->head) {
        list->head = list->cur->next;
        list->head->prev = NULL;
        list->cur = list->head;
    } else if (list->cur == list->tail) {
        list->tail = list->cur->prev;
        list->tail->next = NULL;
        list->cur = list->tail;
    } else {
        list->cur->prev->next = list->cur->next;
        list->cur->next->prev = list->cur->prev;
        list->cur = list->cur->next;
    }
    free(temp);
    list->size--;
    print(list);
    return deleted;
}

void append(int item, linkedList* list)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->element = item;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail != NULL)
        list->tail->next = new_node;
    else
        list->head = new_node;

    list->tail = new_node;
    list->cur = new_node;
    list->size++;
    print(list);
}

int size(linkedList* list)
{
    return list->size;
}

void prev(int n, linkedList* list)
{
    while (n-- > 0 && list->cur != NULL && list->cur->prev != NULL) {
        list->cur = list->cur->prev;
    }
    print(list);
}

void next(int n, linkedList* list)
{
    while (n-- > 0 && list->cur != NULL && list->cur->next != NULL) {
        list->cur = list->cur->next;
    }
    print(list);
}

int is_present(int n, linkedList* list)
{
    node* temp = list->head;
    while (temp != NULL) {
        if (temp->element == n) return 1;
        temp = temp->next;
    }
    return 0;
}

void clear(linkedList* list)
{
    free_list(list);
    init(list);
}

void delete_item(int item, linkedList* list)
{
    node* temp = list->head;
    while (temp != NULL) {
        if (temp->element == item) {
            list->cur = temp;
            delete_cur(list);
            
            return;
        }
        temp = temp->next;
    }
    print(list);
}

void swap_ind(int ind1, int ind2, linkedList* list)
{
    if (ind1 == ind2) return;

    node* n1 = list->head;
    node* n2 = list->head;
    int i = 0;

    while (n1 != NULL && i < ind1) {
        n1 = n1->next;
        i++;
    }

    i = 0;
    while (n2 != NULL && i < ind2) {
        n2 = n2->next;
        i++;
    }

    if (n1 != NULL && n2 != NULL) {
        int temp = n1->element;
        n1->element = n2->element;
        n2->element = temp;
    }
    print(list);
}

// you can define helper functions you need