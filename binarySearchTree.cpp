#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* getNewNode(int data)
{
    struct node* temp=new node;
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
struct node* insert(struct node* root,int data)
{
    struct node *temp=getNewNode(data);
    if(root==NULL)
    {
        root=temp;
    }
    else
    { 
      if(data>root->data)
      {
          root->right=insert(root->right,data);
      }
      else
      {
          root->left=insert(root->left,data);
      }
    }
    return root;
}
bool bstSearch(struct node* root,int data)
{
    if(root==NULL)
    return false;
    else if(root->data==data)
    return true;
    else if(root->data<data)
    return bstSearch(root->right,data);
    else 
    return bstSearch(root->left,data);
}
int findMax(struct node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(root->right==NULL)
    {
        return root->data;
    }
    return findMax(root->right);
}
int findMin(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(root->left==NULL)
    {
        return root->data;
    }
    return findMin(root->left);
}
int max(int a,int b)
{
    if(a>=b)
    return a;
    else return b;
}
int findHeight(node * root)
{
    if(root==NULL)
    return -1;
    return max(findHeight(root->left),findHeight(root->right))+1;   
}
void preorderTras(node* root)
{
    if(root==NULL)
    {
     return;
    }
    cout<<root->data<<" ";
    preorderTras(root->left);
    preorderTras(root->right);
}
void postorderTrans(node* root)
{
    if(root==NULL)
    return;
    
    postorderTrans(root->left);
    postorderTrans(root->right);
    cout<<root->data<<" ";
}
void inorderTrans(node* root)
{
    if(root==NULL)
    return;
    
    inorderTrans(root->left);
    cout<<root->data<<" ";
    inorderTrans(root->right);
    
}
/*
int main()
{
    struct node *root=NULL;
    root=insert(root,20);root=insert(root,10);root=insert(root,21);
    root=insert(root,5);root=insert(root,18);root=insert(root,22);
    root=insert(root,17);root=insert(root,19);root=insert(root,23);
    if(bstSearch(root,22))
        cout<<"found"<<"\n";
    else
        cout<<"Not found"<<"\n";
    
    cout<<findMax(root)<<"\n";
    cout<<findMin(root)<<"\n";
    cout<<findHeight(root)<<"\n";
    
    preorderTras(root);cout<<"\n";
    inorderTrans(root);cout<<"\n";
    postorderTrans(root);cout<<"\n";
    return 0;
}
*/


