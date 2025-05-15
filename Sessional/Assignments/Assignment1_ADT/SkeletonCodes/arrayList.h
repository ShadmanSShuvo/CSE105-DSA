#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int capacity;
    int size;
    int cur;
} arrayList;

void init(arrayList* list)
{
    list->array = (int*)malloc(sizeof(int) * 10);
    list->capacity = 10;
    list->size = 0;
    list->cur = 0;
}

void free_list(arrayList* list)
{
    free(list->array);
}

void increase_capacity(arrayList* list)
{
    int new_capacity = 2 * list->capacity;
    int old_capacity = list->capacity;
    int* new_array = (int*)malloc(sizeof(int) * new_capacity);
    for (int i = 0; i < list->size; i++)
        new_array[i] = list->array[i];
    free(list->array);
    list->array = new_array;
    list->capacity = new_capacity;
    printf("Capacity increased from %d to %d\n", old_capacity, new_capacity);
}

void decrease_capacity(arrayList* list)
{
    int new_capacity = list->capacity / 2;
    int old_capacity = list->capacity;
    //if (new_capacity < 10) return; // Avoid shrinking too small
    int* new_array = (int*)malloc(sizeof(int) * new_capacity);
    for (int i = 0; i < list->size; i++)
        new_array[i] = list->array[i];
    free(list->array);
    list->array = new_array;
    list->capacity = new_capacity;
    printf("Capacity deccreased from %d to %d\n", old_capacity, new_capacity);
}

void print(arrayList* list)
{
    printf("[");
    for (int i = 0; i < list->size; i++) {
        if (i == list->cur)
            printf("%d| ", list->array[i]); // Show cursor after the value
        else
            printf("%d ", list->array[i]);
    }
    printf("]\n");
}

void insert(int item, arrayList* list)
{
    if (list->size == list->capacity)
        increase_capacity(list);
    for (int i = list->size; i > list->cur; i--)
        list->array[i] = list->array[i - 1];
    list->array[list->cur] = item;
    list->size++;
    list->cur++;
    print(list);
}

int delete_cur(arrayList* list)
{
    if (list->size == 0) return -1;
    int deleted_item = list->array[list->cur];
    for (int i = list->cur; i < list->size - 1; i++)
        list->array[i] = list->array[i + 1];
    list->size--;
    if (list->cur >= list->size)
        list->cur = list->size - 1;
    if (list->size < list->capacity / 4)
        decrease_capacity(list);
    
    print(list);
    return deleted_item;
    
}

void append(int item, arrayList* list)
{
    if (list->size == list->capacity)
        increase_capacity(list);
    list->array[list->size++] = item;
    list->cur = list->size - 1;
    print(list);
}

int size(arrayList* list)
{
    return list->size;
}

void prev(int n, arrayList* list)
{
    list->cur = (list->cur - n >= 0) ? list->cur - n : 0;
}

void next(int n, arrayList* list)
{
    list->cur = (list->cur + n < list->size) ? list->cur + n : list->size - 1;
}

int is_present(int n, arrayList* list)
{
    for (int i = 0; i < list->size; i++)
        if (list->array[i] == n)
            return 1;
    return 0;
}

void clear(arrayList* list)
{
    free(list->array);
    list->array = (int*)malloc(sizeof(int) * 10);
    list->capacity = 10;
    list->size = 0;
    list->cur = 0;
}

void delete_item(int item, arrayList* list)
{
    for (int i = 0; i < list->size; i++) {
        if (list->array[i] == item) {
            for (int j = i; j < list->size - 1; j++)
                list->array[j] = list->array[j + 1];
            list->size--;
            if (list->size < list->capacity / 4)
                decrease_capacity(list);
            printf("%d is deleted\n", item);
            print(list);    
            return;
        }
    }
}

void swap_ind(int ind1, int ind2, arrayList* list)
{
    if (ind1 < 0 || ind1 >= list->size || ind2 < 0 || ind2 >= list->size)
        return;
    int temp = list->array[ind1];
    list->array[ind1] = list->array[ind2];
    list->array[ind2] = temp;
    printf("Swapped %d and %d\n", list->array[ind1], list->array[ind2]);
    print(list);
}