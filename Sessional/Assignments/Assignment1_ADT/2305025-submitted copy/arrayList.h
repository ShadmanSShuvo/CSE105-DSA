#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int capacity;
    int size;
    int cur;
    // declare variables you need

} arrayList;
void check_capacity(arrayList *list);
void init(arrayList *list)
{
    list->capacity = 2;
    list->size = 0;
    list->cur = 0;
    list->array = (int *)malloc(sizeof(int) * list->capacity);

    // implement initialization
}

void free_list(arrayList *list)
{
    free(list->array);
    list->array = NULL;
    // implement destruction of list
}

void increase_capacity(arrayList *list)
{
    // implement capacity increase

    int *new_array = (int *)malloc(sizeof(int) * 2 * list->capacity);
    for (int i = 0; i < list->size; ++i)
        new_array[i] = list->array[i];

    printf("Capacity increased from %d to %d\n", list->capacity, 2 * list->capacity);
    free(list->array);
    list->array = new_array;
    list->capacity *= 2;
}

void decrease_capacity(arrayList *list)
{
    // implement capacity decrease
    int *new_array = (int *)malloc(sizeof(int) * list->capacity / 2);
    for (int i = 0; i < list->size; ++i)
        new_array[i] = list->array[i];

    printf("Capacity decreased from %d to %d\n", list->capacity, list->capacity / 2);
    free(list->array);
    list->array = new_array;
    list->capacity /= 2;
}

void print(arrayList *list)
{
    // implement list printing
    if (list->size == 0)
    {
        printf("[ . ]\n");
        return;
    }
    printf("[ ");
    for (int i = 0; i < list->size; ++i)
    {
        printf("%d ", list->array[i]);
        if (i == list->cur - 1)
            printf("| ");
        else
            printf(" ");
    }
    printf("]\n");
}

void insert(int item, arrayList *list)
{
    // implement insert function

    for (int i = list->size; i > list->cur; i--)
    {
        list->array[i] = list->array[i - 1];
    }
    list->array[list->cur] = item;
    list->cur++;
    list->size++;
    check_capacity(list);
    print(list);
}

int delete_cur(arrayList *list)
{
    // implement deletion of current index function
    if (list->size == 0) {
        printf("Nothing to delete\n");
        return -1;
    }
    int temp = list->array[list->cur - 1];
    for (int i = list->cur - 1; i < list->size - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }

    if (list->cur > 0)
        list->cur--;
    list->size--;
    print(list);
    check_capacity(list);
    return temp;
}

void append(int item, arrayList *list)
{
    // implement append function
    check_capacity(list);
    list->array[list->size] = item;
    // list->cur++;
    list->size++;
    if (list->cur == 0){
        list->cur = 1;
    }
    print(list);
}

int size(arrayList *list)
{
    // implement size function
    return list->size;
}

void prev(int n, arrayList *list)
{
    // implement prev function
    list->cur -= n;
    if (list->cur <= 0){
        list->cur = 1;
    }
    print(list);
}

void next(int n, arrayList *list)
{
    // implement next function
    list->cur += n;
    if (list->cur <= 0){
        list->cur = 1;
    }
    print(list);
}

int is_present(int n, arrayList *list)
{
    // implement presence checking function
    for (int i = 0; i < list->size; ++i){
        if (n == list->array[i]){
            return 1;
        }
    }
    return 0;
}

void clear(arrayList *list)
{
    // implement list clearing function
    free(list->array);
    init(list);
}

void delete_item(int item, arrayList *list)
{
    // implement item deletion function
    for (int i = 0; i < list->size; ++i)
    {
        if (item == list->array[i])
        {
            for (int j = i; j < list->size - 1; j++)
            {
                list->array[j] = list->array[j + 1];
            }
            list->size--;
            print(list);
            check_capacity(list);
            return;
        }
    }
    check_capacity(list);
    printf("%d is not found\n", item);
    return;
}

void swap_ind(int ind1, int ind2, arrayList *list)
{
    // implement swap function
    if (ind1 < 0 || ind1 >= list->size || ind2 < 0 || ind2 >= list->size)
    {
        printf("Swap indices out of bounds\n");
        return;
    }
    int temp = list->array[ind2];
    list->array[ind2] = list->array[ind1];
    list->array[ind1] = temp;
    print(list);
}

// you can define helper functions you need

void check_capacity(arrayList *list)
{
    // implement capacity checking function
    if (list->size > list->capacity / 2)
    {
        increase_capacity(list);
    }
    else if (list->size < list->capacity / 4)
    {
        decrease_capacity(list);
    }
}

int findMiddle(arrayList *list){
    return list->array[list->size/2];
}

void merge_sorted(arrayList *list1, arrayList *list2, arrayList *result) {
    init(result);
    int i = 0, j = 0;
    while (i < list1->size && j < list2->size) {
        if (list1->array[i] <= list2->array[j]) {
            append(list1->array[i], result);
            i++;
        } else {
            append(list2->array[j], result);
            j++;
        }
    }
    while (i < list1->size) {
        append(list1->array[i], result);
        i++;
    }
    while (j < list2->size) {
        append(list2->array[j], result);
        j++;
    }
}

void remove_duplicates(arrayList *list) {
    if (list->size <= 1) return;
    int write = 1;
    for (int i = 1; i < list->size; i++) {
        if (list->array[i] != list->array[write - 1]) {
            list->array[write] = list->array[i];
            write++;
        }
    }
    list->size = write;
    if (list->cur > list->size) list->cur = list->size;
    check_capacity(list);
    print(list);
}

void rotate_right(arrayList *list, int k) {
    if (list->size <= 1 || k == 0) return;
    k = k % list->size;
    if (k < 0) k += list->size;
    // Reverse entire array
    for (int i = 0; i < list->size / 2; i++) {
        swap_ind(i, list->size - 1 - i, list);
    }
    // Reverse first k elements
    for (int i = 0; i < k / 2; i++) {
        swap_ind(i, k - 1 - i, list);
    }
    // Reverse remaining elements
    for (int i = k; i < (list->size + k) / 2; i++) {
        swap_ind(i, list->size - 1 - i + k, list);
    }
    list->cur = (list->cur + k) % list->size;
    print(list);
}


