#include<bits/stdc++.h>

struct node
{
    int     x;
    struct node *next;
};

struct node *head;

void addnode(struct node *link)
{
    scanf("%d",&link->x);
    if(link->x==0)
        link->next=NULL;
    else{
        link->next = (struct node*) malloc(sizeof( struct node));
        addnode(link->next);
    }
}
void printlist(struct node *head)
{
    struct node *localhead=head;
    printf("\nElements are: head");
    while(NULL != localhead->next){
        printf(" -> %d", localhead->x);
        localhead = localhead->next;
    }
}
int main()
{
    head = (struct node*) malloc(sizeof( struct node));
    addnode(head);
    printlist(head);
    free(head);
    return 0;
}
