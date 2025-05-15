#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;



int main(){
    int count = 5;
    node *head = (node*)malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;
    node *current = head;
    for (int i = 1; i < count; i++)
    {
        int x;
        scanf("%d", &x);
        current->data = x;
        current->next = (node*)malloc(sizeof(node));
        current = current->next;
    }
    scanf("%d", &current->data);
    current->next=NULL;
    current = head;
    for (int i = 0; current!=NULL; i++)
    {
        printf("%d ", current->data);
        current = current->next;   
    }
    
    
    // current->data = 2;
    // current->next = NULL;
    // current = current->next;
    // current->data = 3;
    // current->next = NULL;
    // current = current->next;
    // current->data = 4;
    // current->next = NULL;
    // current = current->next;
    // current->data = 5;
    // current->next = NULL;
    // current = current->next;
    // current->data = 6;
    // current->next = NULL;
    // current = current->next;
    // current->data =
    return 0;
}