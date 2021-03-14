#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
        height=1;
    }
};
// Node* root;
// void Insert(int item){
//     root=insert(root,item);
// }
int height(Node* root)
{
    if(root==nullptr)
        return 0;
    return root->height;
}
int bal_fact(Node* root)
{
    if(root==nullptr)
        return 0;
    return height(root->left)-height(root->right);
}
// LL imbalance
Node* RightRotate(Node* c)    //bf at c is imbalanced
{
    Node *b=c->left;
    Node *T3=b->right;
    //rotate
    b->right=c;
    c->left=T3;
    //update heights
    c->height=max(height(c->left),height(c->right))+1;
    b->height=max(height(b->left),height(b->right))+1;

    return b;
}
Node* LeftRotate(Node* c)
{
    //capture required values first
    Node* b=c->right;
    Node* T2=b->left;
    //rotate 
    b->left=c;
    c->right=T2;
    //updare heights
    c->height=max(height(c->left),height(c->right))+1;
    b->height=max(height(b->left),height(b->right))+1;
    
    return b;
}
Node* insert(Node* root,int item)
{    
    if(root==nullptr){
        Node* node=new Node(item);
        return node;
    }
    if(item > root->data){
        root->right = insert(root->right,item);
    }
    else{
        root->left=insert(root->left,item);
    }

    root->height=max(height(root->left),height(root->right))+1;
    int bf=bal_fact(root);
    //detect LL case
    if(bf>1 &&  item< root->left->data)
    {
        return RightRotate(root);

    }

    //detect RR case
    if(bf<-1 && item > root->right->data)
    {
        return LeftRotate(root);
    }

    //detect LR case
    if(bf>1 && item > root->left->data)
    {
        Node* a=LeftRotate(root->left);
        root->left=a;
        return RightRotate(root);
    }

    //detect RL case
    if(bf<-1 && item< root->right->data )
    {
        Node* a=RightRotate(root->right);
        root->right=a;
        return LeftRotate(root);

    }
    return root;
}


void inorder(Node* root)
{
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main()
{
    Node* root=nullptr;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,6);
    root=insert(root,5);
    root=insert(root,-2);
    root=insert(root,-5);
    root=insert(root,-8);
    inorder(root);

    cout<<endl<<height(root);


    return 0;
}