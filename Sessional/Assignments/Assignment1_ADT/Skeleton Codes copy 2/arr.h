#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *array;
    int size;
    int capacity;
    int current_index;
} arrayList;

void init(arrayList* list)
{
    list->array = (int *)malloc(sizeof(int)*2);
    list->size = 0;
    list->capacity = 2;
    list->current_index = 0;
}

void free_list(arrayList* list)
{
    free(list->array);
    list->array = NULL;
    list->size = 0;
    list->capacity = 0;
    list->current_index = 0;
}

void increase_capacity(arrayList* list)
{
    int new_capacity = list->capacity * 2;
    int *new_array = (int *)malloc(sizeof(int) * new_capacity);
    
    for (int i = 0; i < list->size; i++) {
        new_array[i] = list->array[i];
    }
    
    free(list->array);
    list->array = new_array;
    list->capacity = new_capacity;
}

void decrease_capacity(arrayList* list)
{
    if (list->capacity <= 2) return;
    
    int new_capacity = list->capacity / 2;
    if (new_capacity < list->size) return;
    
    int *new_array = (int *)malloc(sizeof(int) * new_capacity);
    
    for (int i = 0; i < list->size; i++) {
        new_array[i] = list->array[i];
    }
    
    free(list->array);
    list->array = new_array;
    list->capacity = new_capacity;
}

void print(arrayList* list)
{
    printf("[");
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->array[i]);
        if (i < list->size - 1) printf(", ");
    }
    printf("]\n");
}

void insert(int item, arrayList* list)
{
    if (list->size == list->capacity) {
        increase_capacity(list);
    }
    
    for (int i = list->size; i > list->current_index; i--) {
        list->array[i] = list->array[i-1];
    }
    
    list->array[list->current_index] = item;
    list->size++;
}

int delete_cur(arrayList* list)
{
    if (list->size == 0 || list->current_index >= list->size) {
        return -1;
    }
    
    int deleted_item = list->array[list->current_index];
    
    for (int i = list->current_index; i < list->size-1; i++) {
        list->array[i] = list->array[i+1];
    }
    
    list->size--;
    
    if (list->size < list->capacity/2 && list->capacity > 2) {
        decrease_capacity(list);
    }
    
    return deleted_item;
}

void append(int item, arrayList* list)
{
    if (list->size == list->capacity) {
        increase_capacity(list);
    }
    
    list->array[list->size] = item;
    list->size++;
}

int size(arrayList* list)
{
    return list->size;
}

void prev(int n, arrayList* list)
{
    list->current_index = (list->current_index - n >= 0) ? 
                         list->current_index - n : 0;
}

void next(int n, arrayList* list)
{
    list->current_index = (list->current_index + n < list->size) ? 
                         list->current_index + n : list->size - 1;
}

int is_present(int n, arrayList* list)
{
    for (int i = 0; i < list->size; i++) {
        if (list->array[i] == n) {
            return 1;
        }
    }
    return 0;
}

void clear(arrayList* list)
{
    free(list->array);
    list->array = (int *)malloc(sizeof(int)*2);
    list->size = 0;
    list->capacity = 2;
    list->current_index = 0;
}

void delete_item(int item, arrayList* list)
{
    int i = 0;
    while (i < list->size) {
        if (list->array[i] == item) {
            for (int j = i; j < list->size-1; j++) {
                list->array[j] = list->array[j+1];
            }
            list->size--;
            if (list->size < list->capacity/2 && list->capacity > 2) {
                decrease_capacity(list);
            }
        } else {
            i++;
        }
    }
}

void swap_ind(int ind1, int ind2, arrayList* list)
{
    if (ind1 >= 0 && ind1 < list->size && ind2 >= 0 && ind2 < list->size) {
        int temp = list->array[ind1];
        list->array[ind1] = list->array[ind2];
        list->array[ind2] = temp;
    }
}