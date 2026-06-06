#include <stdio.h>
#include <stdlib.h>
typedef struct node {
       int number;
       struct node *next;
} Node;
Node* formList ( ) {
    int number;
    Node* head = NULL;
    Node* last = NULL;
    while(scanf("%d", &number)==1){
        Node* node = calloc(1, sizeof(Node));
        node->number = number;
        node->next = NULL;
        
        if(last==NULL){
            head=node;
        }else{
            last->next=node;
        }
        last=node;
    }
    return head;
}
