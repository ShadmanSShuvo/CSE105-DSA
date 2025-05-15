#include <stdio.h>
#include <stdlib.h>

// Correct typedef with struct tag
typedef struct node {
    int element;
    struct node* next;
    struct node* prev;
} node;

typedef struct {
    node* head;
    node* tail;
    node* cur;
    int size;
} linkedList;

void init(linkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL;
    list->size = 0;
}

void free_list(linkedList* list) {
    node* current = list->head;
    while (current != NULL) {
        node* next_node = current->next;
        free(current);
        current = next_node;
    }
    list->head = list->tail = list->cur = NULL;
    list->size = 0;
}

void print(linkedList* list) {
    node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->element);
        current = current->next;
    }
    printf("\n");
}

void insert(int item, linkedList* list) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->element = item;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (list->head == NULL) {
        // First node
        list->head = list->tail = list->cur = new_node;
    } else {
        new_node->next = list->cur->next;
        new_node->prev = list->cur;

        if (list->cur->next != NULL) {
            list->cur->next->prev = new_node;
        } else {
            list->tail = new_node;
        }

        list->cur->next = new_node;
        list->cur = new_node;
    }
    list->size++;
    print(list); // Print after insertion
}

int delete_cur(linkedList* list) {
    if (list->cur == NULL) {
        return -1; // Nothing to delete
    }

    node* to_delete = list->cur;
    int deleted_item = to_delete->element;

    if (to_delete->prev != NULL) {
        to_delete->prev->next = to_delete->next;
    } else {
        list->head = to_delete->next;
    }

    if (to_delete->next != NULL) {
        to_delete->next->prev = to_delete->prev;
    } else {
        list->tail = to_delete->prev;
    }

    // Update cur pointer before freeing
    if (to_delete->prev != NULL) {
        list->cur = to_delete->prev;
    } else {
        list->cur = to_delete->next;
    }

    free(to_delete);
    list->size--;

    if (list->size == 0) {
        list->head = list->tail = list->cur = NULL;
    }

    return deleted_item;
    print(list); // Print after deletion
}

void append(int item, linkedList* list) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->element = item;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (list->size == 0) {
        list->head = list->tail = list->cur = new_node;
    } else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }

    list->size++;
    list->cur = new_node; // Move current index to the new node
    print(list); // Print after appending
}

int size(linkedList* list) {
    return list->size;
}

void prev(int n, linkedList* list) {
    while (n-- > 0 && list->cur != NULL && list->cur->prev != NULL) {
        list->cur = list->cur->prev;
    }
    if (list->cur == NULL) {
        list->cur = list->head; // Reset to head if cur is NULL
    }
    print(list); // Print after moving to previous
}

void next(int n, linkedList* list) {
    while (n-- > 0 && list->cur != NULL && list->cur->next != NULL) {
        list->cur = list->cur->next;
    }
    if (list->cur == NULL) {
        list->cur = list->tail; // Reset to tail if cur is NULL
    }
    print(list); // Print after moving to next
}

int is_present(int n, linkedList* list) {
    node* current = list->head;
    while (current != NULL) {
        if (current->element == n) return 1;
        current = current->next;
    }
    return 0;
}

void clear(linkedList* list) {
    free_list(list); // reuse
}

void delete_item(int item, linkedList* list) {
    node* current = list->head;
    while (current != NULL) {
        if (current->element == item) {
            if (current == list->cur) {
                list->cur = current->prev ? current->prev : current->next;
            }
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
        print(list); // Print after deletion
    }
    printf("Item not found\n");
}

void swap_ind(int ind1, int ind2, linkedList* list) {
    if (ind1 < 0 || ind1 >= list->size || ind2 < 0 || ind2 >= list->size || ind1 == ind2) {
        return;
    }

    node* node1 = list->head;
    node* node2 = list->head;
    for (int i = 0; i < ind1; i++) node1 = node1->next;
    for (int i = 0; i < ind2; i++) node2 = node2->next;

    int temp = node1->element;
    node1->element = node2->element;
    node2->element = temp;
    print(list); // Print after swapping
}