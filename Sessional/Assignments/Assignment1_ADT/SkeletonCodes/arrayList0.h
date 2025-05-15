#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *array;
    // declare variables you need
    //array = (int*)malloc(sizeof(int)*10);
    int capacity;
    int size;
    int cur;
    //int head=0;
    // int tail;
} arrayList;

void init(arrayList* list)
{
    // implement initialization
    arrayList* list = (arrayList*)malloc(sizeof(arrayList));
    list->array = (int*)malloc(sizeof(int) * 10);
    list->capacity = 10;
    list->size = 0;
}

void free_list(arrayList* list)
{
    // implement destruction of list
    free(list->array);
    free(list);
}

void increase_capacity(arrayList* list)
{
    // implement capacity increase
    int new_capacity = 2 * list->capacity;
    int* new_array = (int*)malloc(sizeof(int) * new_capacity);
    
    for (int i = 0; i < list->size; i++)
        new_array[i] = list->array[i];
    
    free(list->array);  // free old array
    list->array = new_array;
    list->capacity = new_capacity;
}

void decrease_capacity(arrayList* list)
{
    // implement capacity decrease
    int new_capacity = list->capacity / 2;
    int* new_array = (int*)malloc(sizeof(int) * new_capacity);
    
    for (int i = 0; i < list->size; i++)
        new_array[i] = list->array[i];
    

    free(list->array);  // free old array
    list->array = new_array;
    list->capacity = new_capacity;
}

void print(arrayList* list)
{
    // implement list printing
    printf("[");
    for (int i = 0; i < list->size; i++){
        printf("%d", list->array[i]);
        if(i==list->cur)
        {
            printf("|");
        }
        else
        {
            printf(" ");
        }
    }
    printf("]\n");
}



void insert(int item, arrayList* list)
{
    // implement insert function
    if (list->size == list->capacity)
    {
        increase_capacity(list);
    }
    for (int i = list->size; i > list->cur; i--)
    {
        list->array[i] = list->array[i - 1];
    }
    list->array[list->cur] = item;
    list->size++;
    list->cur++;
}

int delete_cur(arrayList* list)
{
    // implement deletion of current index function
    if (list->size == 0)
    {
        return -1; // or some error code
    }
    int deleted_item = list->array[list->cur];
    for (int i = list->cur; i < list->size - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    if (list->size < list->capacity / 4)
    {
        decrease_capacity(list);
    }
    return deleted_item;
}

void append(int item, arrayList* list)
{
    // implement append function
    if (list->size == list->capacity)
    {
        increase_capacity(list);
    }
    list->array[list->size] = item;
    list->size++;
    list->cur = list->size - 1; // move current index to the end
}

int size(arrayList* list)
{
    // implement size function
    return list->size;
}

void prev(int n, arrayList* list)
{
    // implement prev function
    if (list->cur - n >= 0)
    {
        list->cur -= n;
    }
    else
    {
        list->cur = 0; // or some error handling
    }

}

void next(int n, arrayList* list)
{
    // implement next function
    if (list->cur + n < list->size)
    {
        list->cur += n;
    }
    else
    {
        list->cur = list->size - 1; // or some error handling
    }
}

int is_present(int n, arrayList* list)
{
    // implement presence checking function
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == n)
        {
            return 1; // present
        }
    }
    return 0; // not present
}

void clear(arrayList* list)
{
    // implement list clearing function
    list->size = 0;
    list->cur = 0;
    free(list->array);
    list->array = (int*)malloc(sizeof(int) * 10); // reset to initial capacity
    list->capacity = 10;
}

void delete_item(int item, arrayList* list)
{
    // implement item deletion function
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == item)
        {
            for (int j = i; j < list->size - 1; j++)
            {
                list->array[j] = list->array[j + 1];
            }
            list->size--;
            if (list->size < list->capacity / 4)
            {
                decrease_capacity(list);
            }
            return;
        }
    }
}

void swap_ind(int ind1, int ind2, arrayList* list)
{
    // implement swap function
    if (ind1 < 0 || ind1 >= list->size || ind2 < 0 || ind2 >= list->size)
    {
        return; // out of bounds
    }
    int temp = list->array[ind1];
    list->array[ind1] = list->array[ind2];
    list->array[ind2] = temp;

}

// you can define helper functions you need