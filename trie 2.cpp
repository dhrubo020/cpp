#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool endmark;
    node *next[26+1];
    node()
    {
        endmark=false;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }
} *root ;

void insert(char *str, int len)
{
    node *curr=root;
    for(int i=0; i<len; i++){
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool search(char *str, int len)
{
    node *curr=root;
    for(int i=0; i<len; i++){
        int id = str[i] - 'a';
        if(curr->next[id]==NULL)
            return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}
void del(node *curr)
{
    for(int i=0; i<26; i++)
        if(curr->next[i]){
                  cout<<(char)curr->next[i]<<endl;
            del(curr->next[i]);
        }
    delete(root);
}
int main()
{
    root = new node();
    puts("ENTER THE NUMBER OF WORDS : ");
    int word;
    cin >> word;
    for(int i=1; i<=word; i++){
        char str[20];
        cin >> str;
        insert(str, strlen(str));
    }
    puts("ENTER THE NUMBER OF QUERY : ");
    int query;
    cin >> query;
    for(int i=1; i<=query; i++){
        char str[20];
        cin >> str;
        if(search(str, strlen(str)))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
    del(root);
}
