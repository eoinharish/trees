#include<bits/stdc++.h>
using namespace std;

vector<int> postorder(struct node *root)
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
        struct node*temp =st.top()->right;
        if(temp==NULL)
        {
            temp=st.top();st.pop();
            v.push_back(temp->data);
            while(!st.empty() && st.top()->right==temp){
                temp=st.top();st.pop();
                v.push_back(temp);

            }
        }
        else{
            curr=temp;
        }
        
    }
    return v;

}