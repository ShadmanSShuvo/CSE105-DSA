#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int element;
    node* next;
    node* prev;
} node;

typedef struct 
{
    node* head;
    node* tail;
    node* cur;
    int size;
    // you can add more variables if needed
    // for example, you might want to keep track of the current index
    // int cur_index;
    // or you might want to keep track of the capacity if you are using a dynamic array
    // int capacity;
    // or you might want to keep track of the number of elements in the list
    // declare head, tail, cur and other variables you need
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
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

void print(linkedList* list)
{
    // implement list printing
    node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->element);
        current = current->next;
    }
    printf("\n");
}

void insert(int item, linkedList* list)
{
    // implement insert function
    node* new_node = (node*)malloc(sizeof(node));
    new_node->element = item;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
        list->cur = new_node;
    } else {
        new_node->next = list->cur->next;
        new_node->prev = list->cur;
        if (list->cur->next != NULL) {
            list->cur->next->prev = new_node;
        } else {
            list->tail = new_node; // update tail if inserting at the end
        }
        list->cur->next = new_node;
    }
    list->size++;
    list->cur = new_node; // move current index to the new node
    if (list->size == 1) {
        list->head = new_node; // if this is the first node
    }
    if (list->size == 2) {
        list->tail = new_node; // if this is the second node
    }
    // you can add more logic if needed
    // for example, if you want to keep track of the current index
    // list->cur_index = list->size - 1; // move current index to the end
    // or if you want to keep track of the capacity
    // list->capacity = list->size; // update capacity
    // or if you want to keep track of the number of elements in the list
    // list->num_elements = list->size; // update number of elements
    // or if you want to keep track of the current index
    // list->cur_index = list->size - 1; // move current index to the end
}

int delete_cur(linkedList* list)
{
    // implement deletion of current index function
    if (list->cur == NULL) {
        return -1; // nothing to delete
    }
    node* to_delete = list->cur;
    if (to_delete->prev != NULL) {
        to_delete->prev->next = to_delete->next;
    } else {
        list->head = to_delete->next; // update head if deleting the first node
    }
    if (to_delete->next != NULL) {
        to_delete->next->prev = to_delete->prev;
    } else {
        list->tail = to_delete->prev; // update tail if deleting the last node
    }
    int deleted_item = to_delete->element;
    free(to_delete);
    list->size--;
    if (list->size == 0) {
        list->head = NULL;
        list->tail = NULL;
        list->cur = NULL; // reset current index
    } else if (list->cur->prev != NULL) {
        list->cur = list->cur->prev; // move current index to the previous node
    } else {
        list->cur = list->head; // move current index to the head
    }
    return deleted_item; // return the deleted item
}

void append(int item, linkedList* list)
{
    // implement append function
    node* new_node = (node*)malloc(sizeof(node));
    new_node->element = item;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->cur = new_node;
    } else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
    list->size++;
    // you can add more logic if needed
    // for example, if you want to keep track of the current index
    // list->cur_index = list->size - 1; // move current index to the end
    // or if you want to keep track of the capacity
    // list->capacity = list->size; // update capacity
    // or if you want to keep track of the number of elements in the list
    // list->num_elements = list->size; // update number of elements
    // or if you want to keep track of the current index
}

int size(linkedList* list)
{
    // implement size function
    return list->size; // return the size of the list
    // you can add more logic if needed
}

void prev(int n, linkedList* list)
{
    // implement prev function
    if (list->cur == NULL) {
        return; // nothing to move
    }
    for (int i = 0; i < n && list->cur->prev != NULL; i++) {
        list->cur = list->cur->prev; // move current index to the previous node
    }
    // you can add more logic if needed
}

void next(int n, linkedList* list)
{
    // implement next function
    if (list->cur == NULL) {
        return; // nothing to move
    }
    for (int i = 0; i < n && list->cur->next != NULL; i++) {
        list->cur = list->cur->next; // move current index to the next node
    }
}

int is_present(int n, linkedList* list)
{
    // implement presence checking function
    node* current = list->head;
    while (current != NULL) {
        if (current->element == n) {
            return 1; // present
        }
        current = current->next;
    }
    return 0; // not present
}

void clear(linkedList* list)
{
    // implement list clearing function
    node* current = list->head;
    node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL; // reset current index
    list->size = 0; // reset size
}

void delete_item(int item, linkedList* list)
{
    // implement item deletion function
    node* current = list->head;
    while (current != NULL) {
        if (current->element == item) {
            if (current == list->head) {
                list->head = current->next;
            }
            if (current == list->tail) {
                list->tail = current->prev;
            }
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            list->size--;
            return;
        }
        current = current->next;
    }
    printf("Item not found\n");
}

void swap_ind(int ind1, int ind2, linkedList* list)
{
    // implement swap function
    if (ind1 < 0 || ind1 >= list->size || ind2 < 0 || ind2 >= list->size) {
        return; // invalid indices
    }
    node* node1 = list->head;
    node* node2 = list->head;
    for (int i = 0; i < ind1; i++) {
        node1 = node1->next; // move to the first node
    }
    for (int i = 0; i < ind2; i++) {
        node2 = node2->next; // move to the second node
    }
    if (node1 == node2) {
        return; // nothing to swap
    }
    // swap the elements
    int temp = node1->element;
    node1->element = node2->element;
    node2->element = temp;
    // you can add more logic if needed
}

// you can define helper functions you need