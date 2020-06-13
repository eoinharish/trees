#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*left;
    struct node*right;
};
vector<int> inorder(struct node* root)
{
    vector<int>v;
    if(root==NULL)
        return v;
    stack<node*>st;

    struct node*curr=root;
    while(curr!=NULL || !st.empty())
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();st.pop();
        v.push_back(curr->data);
        curr=curr->right;
    }
    return v;

}