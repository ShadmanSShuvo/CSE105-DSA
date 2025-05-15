#include "arrayList.h"
// #include "linkedlist.h"
#include <stdio.h>


int main()
{
    const char* input_filename= "books.txt";
    FILE *file = fopen(input_filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    
    int number_of_books;
    const int CAPACITY = 10;
    scanf("%d", &number_of_books);

    arrayList list;
    init(&list, CAPACITY);
    // LinkedList list;
    // init_linkedlist(&list);
    int i;
    for (i=0; i<number_of_books; i++)
    {
        int book_id;
        fscanf(file, "%d", &book_id);
        append(&list, book_id);
    }
    print(&list);
    printf("\n");

    // implement this function
    reverse(&list);

    printf("Reveresed list: ");
    print(&list);


    free_list(&list);
    fclose(file);
    return 0;
}