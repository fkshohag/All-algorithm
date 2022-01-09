# include <bits/stdc++.h>
using namespace std;
struct BST
{
    int data;
    BST *left,*right;
}Node;
BST *GetNode()
{
    BST *temp;
    temp=(BST*)malloc(sizeof(BST));
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void InsertNode(BST *Root,BST *NewNode)
{
    if(NewNode->data<Root->data)
    {
        if(Root->left==NULL)Root->left=NewNode;
        else InsertNode(Root->left,NewNode);
    }
    else
    {
        if(Root->right==NULL)Root->right=NewNode;
        else InsertNode(Root->right,NewNode);
    }
    return;
}
void PreorderPrint(BST *Root)
{
    cout<<Root->data<<" ";
    if(Root->left!=NULL)PreorderPrint(Root->left);
    if(Root->right!=NULL)PreorderPrint(Root->right);
    return;
}
void InorderPrint(BST *Root)
{
    if(Root->left!=NULL)InorderPrint(Root->left);
    cout<<Root->data<<" ";
    if(Root->right!=NULL)InorderPrint(Root->right);
    return;
}
void PostorderPrint(BST *Root)
{
    if(Root->left!=NULL)PostorderPrint(Root->left);
    if(Root->right!=NULL)PostorderPrint(Root->right);
    cout<<Root->data<<" ";
    return;
}
BST *SearchBST(BST *Root,int key)
{
    while(Root!=NULL)
    {
        if(Root->data==key)return Root;
        else if(key<Root->data)
        {
            if(Root->left!=NULL)
            {
                Root=Root->left;
            }
            else return NULL;
        }
        else if(key>Root->data)
        {
            if(Root->right!=NULL)
            {
                Root=Root->right;
            }
            else return NULL;
        }

    }
    return NULL;
}
int main()
{
    BST *Root,*NewNode;
    Root=NULL;
    for(int i=0;i<5;i++)
    {
        NewNode=GetNode();
        cin>>NewNode->data;
        if(Root==NULL)Root=NewNode;
        else InsertNode(Root,NewNode);
    }
      PreorderPrint(Root);
      cout<<endl;
      InorderPrint(Root);
      cout<<endl;
      PostorderPrint(Root);
      cout<<endl;
      int Element;
      cin>>Element;
      if(SearchBST(Root,Element)==NULL)
      {
          cout<<"not found"<<endl;
      }
      else
      {
          cout<<"Element is found";
      }
      return 0;
}


