#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode*left;
    TreeNode* right;
    TreeNode(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    } 
};
unordered_set<int>s;
void inorder(TreeNode* root,int sum)
{
    if(root==nullptr)
        return;
    inorder(root->left,sum);
    if(s.find(sum-root->data)!=s.end()){
        cout<<"("<<sum-root->data<<","<<root->data<<")";
        return;
    }
    else{
        s.insert(root->data);
    }
    inorder(root->right,sum);
}
void findPair(TreeNode* root,int sum)
{
    inorder(root,sum);

}
int main()
{
    TreeNode* root=new TreeNode(15);
    root->left=new TreeNode(10);
    root->right= new TreeNode(20);
    root->left->left=new TreeNode(8);
    root->left->right= new TreeNode(12);
    root->right->left=new TreeNode(16);
    root->right->right=new TreeNode(25);
    int sum=28;
    findPair(root,sum);

}