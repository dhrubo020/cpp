#include<bits/stdc++.h>
struct node
{
    char name[30];
    char  roll[10];
    float cgpa;
    struct node *next;
};
typedef struct node link; // link = struct node
link *head;  // = struct node head

void get_info(void)
{
    printf("Enter the number of students\n");
    int n;
    scanf("%d%*c",&n);

    link *tail, *input;
    tail=head=NULL;

    for(int i=1; i<=n; i++){
        input = (link*) malloc(sizeof(link));
        printf("Student name : ");
        gets(input->name);
        fflush(stdin);
        printf("Student Roll : ");
        gets(input->roll);
        fflush(stdin);
        printf("Student cgpa : ");
        scanf("%f%*c",&input->cgpa);

        input->next = NULL;

        if( head == NULL)
            head = input ;
        else
            tail->next = input ;

        tail = input ;
        printf("\n\n");
    }
    while( head != NULL){
        printf("\n\t%s\t%s\t%.2f", head->name, head->roll,head->cgpa);
        head = head ->next;
    }
}
int main()
{
    get_info();
    return 0;
}
