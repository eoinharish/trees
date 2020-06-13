#include<bits/stdc++.h>
using namespace std;

//Hard difficulty on leetcode 
//Postorder using two stacks
struct node{
    int data;
    struct node*left;
    struct node*right;
};

vector<int> postorder(struct node *root)
{
    vector<int>v;
    if(root==NULL)
        return v;
    stack<node*> s1;
    stack<node*> s2;

    s1.push(root);

    while(!s1.empty())
    {
        root=s1.top();s1.pop();
        s2.push(root);
        if(root->left !=NULL)
            s1.push(root->left);
        if(root->right!=NULL)
            s1.push(root->right);
    }
    while(!s2.empty())
    {
        v.push_back(s2.top()->data);
        s2.pop();
    }
    return v;
    
}