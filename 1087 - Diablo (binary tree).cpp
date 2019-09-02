#include<bits/stdc++.h>
using namespace std;

struct node
{
      int key;
      node *left , *right;
};

struct node *newnode(int temp)
{
      node *temp = new node;
      temp->key = temp;
      temp->left = temp->right = NULL;
      return temp;
}
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
            return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

int main()
{
      int tc;
      scanf("%d",&tc);
      for(int t=1;<=tc; t++)
      {
            printf("Case :%d\n",t);
            int Qu;
            scanf("%d",&Qu);
            while(Qu--)
            {
                  char c;
                  int idx , value;
                  scanf(" %c",&c);
                  if( c == 'c')
                  {
                        scanf("idx");
                        printf("%d\n",SEARCH(A[idx]));
                  }
                  else
                  {
                        scanf("%d",&value);
                        ADD(value);
                  }
            }
      }
}
