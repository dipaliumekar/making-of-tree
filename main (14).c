/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
struct tree
{    
    int data;
    struct tree*left,*right;
};
struct tree*insert(struct tree* ,int );
struct tree*create(int);
void display(struct tree*);

void main ()
{
    int  n,d;
    struct tree*root=NULL;
    printf("enter the nodes :\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
     printf("Enter data\n");
     scanf("%d",&d);
     root=insert(root,d);
    }
     printf("Tree is\n");
    display(root);
        
}

struct tree*insert(struct tree*root,int d)
{
   
    if(root==NULL){
    return create(d);
}
else if(d< root->data)
root->left=insert(root->left,d);

else
    root->right=insert(root->right,d);

    return root;
}

struct tree*create(int d)
{
   struct tree*new;
   new= (struct tree*)malloc(sizeof(struct tree));
   new->data=d;
   new->left=NULL;
   new->right=NULL;
   return new;

}

void display(struct tree*root)
{
    if(root==NULL)
{
    return;
}
else{
    if(root!=NULL){
        display(root->left);
       
    }
    printf(" %d",root->data);
    display(root->right);
}
}