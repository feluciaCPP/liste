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
void printList ( Node *head ) {
    for(Node* current = head; current!=NULL; current=current->next){
        printf("%d ", current->number);
    }
}
int listSize ( Node *head ) {
    int cnt = 0;
    for(Node* current=head; current!=NULL; current=current->next){
        cnt++;
    }
    return cnt;
}

Node* searchFirst ( Node *head, int number ) {
    for(Node* current = head; current!=NULL; current=current->next){
        if(current->number==number)return current;
    }
    return NULL;
}

Node* searchLast ( Node *head, int number ) {
    Node* last = NULL;
    for(Node* current = head; current!=NULL; current=current->next){
        if(current->number==number)last=current;
    }
    return last;
}

void sortList ( Node *head ) {
    for(Node* i = head; i!=NULL; i=i->next){
        for(Node* j=i->next; j!=NULL; j=j->next){
            if(i->number > j->number){
                int tmp = i->number;
                i->number = j->number;
                j->number = tmp;
            }
        }
    }
}

void deallocateList ( Node *head ) {
    for(Node* current = head; current!=NULL; current=current->next){
        free(current);
    }
}

void deallocateList ( Node *head ) {
    for(Node* current = head; current!=NULL; current=current->next){
        free(current);
    }
}
Node* insertSorted ( Node *head, int number ) {
    Node *prev=NULL, *curr = head;
    while(curr && curr->number<number){
        prev=curr;
        curr=curr->next;
    }
    Node *tmp = malloc(sizeof(Node));
    tmp->number=number;
    tmp->next=curr;
    if(prev)prev->next=tmp;
    else head=tmp;
}

Node* removeElements ( Node *head, int number ) {
    Node *prev=NULL, *curr=head;
    while(curr){
        if(curr->number==number){
            Node* old = curr;
            curr=curr->next;
            if(prev)prev->next=curr;
            else head=curr;
            free(old);
        }else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}
Node* mergeLists ( Node *head0, Node *head1 ) {
    Node *head = 0, *first=head0, *second=head1, *tmp, *tail;
    while(first && second){
        if(first->number<second->number){
            tmp=first;
            first=first->next;
        }else{
            tmp=second;
            second=second->next;
        }
        if(!head)head=tmp;
        else tail->next=tmp;
        tail=tmp;
    }
    if(first){
        if(!head)head=first;
        else tail->next=first;
    }else{
        if(!head)head=second;
        else tail->next=second;
    }
    return head;
}
void removeDuplicates ( Node *head ) {
    while(head){
        Node *prev= head, *curr=head->next;
        while(curr && curr->number==head->number){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        deallocateList(head->next);
        head->next = curr;
        head=curr;
    }
}
Node* reverseList ( Node *head ) {
    Node *prev = NULL, *curr=head;
    while(head){
        curr=head;
        head=curr->next;
        curr->next=prev;
        prev=curr;
    }
    return curr;
}
int listSize ( Node *head ) {
    int cnt = 0;
    for(Node* current=head; current!=NULL; current=current->next){
        cnt++;
    }
    return cnt;
}
Node* getMiddle ( Node *head ) {
    int n = listSize(head);
    n/=2;
    Node *current = head;
    while(n--){
        current=current->next;
    }
    return current;
}

int listSize ( Node *head ) {
    int cnt = 0;
    for(Node* current=head; current!=NULL; current=current->next){
        cnt++;
    }
    return cnt;
}
Node* getNthFromEnd ( Node *head, int n ) {
    int sz = listSize(head);
    sz-=n;
    Node* current = head;
    while(sz--){
        current=current->next;
    }
    return current;
}
