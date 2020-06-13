#include<bits/stdc++.h>
using namespace std;

//Using 2 stack technique
//watch tushar roy's video
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>v;
        if(root==NULL)
            return v;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        vector<int>temp;
        while(!s1.empty() || !s2.empty())
        {
            temp.clear();
            while(!s1.empty())
            {
                TreeNode* current=s1.top();
                s1.pop();                       
                if(current->left!=NULL)
                    s2.push(current->left);
                if(current->right!=NULL)
                    s2.push(current->right);
                temp.push_back(current->val);
            }
            v.push_back(temp);
            temp.clear();
            while(!s2.empty())
            {
                TreeNode* current=s2.top();
                s2.pop();
                if(current->right!=NULL)
                    s1.push(current->right);
                if(current->left!=NULL)
                    s1.push(current->left);
                temp.push_back(current->val);
            }
            if(!temp.empty())
            v.push_back(temp);
           
        }
        return v;
    }