#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
    {
        data=x;
        left=nullptr;
        right=nullptr;
    }
};
vector<int> MorrisTraversal(TreeNode* root)
{
    vector<int>ans;
    TreeNode* tourist=root;

    while(tourist!=NULL)
    {
        TreeNode* guide=tourist->left;
        
        if(guide!=nullptr)  //when tourist is not at the leftmost end or the guide is not lost
        {
            while(guide->right!=NULL && guide->right!=tourist){           //IMPORTANT
                guide=guide->right;
            }
            if(guide->right==nullptr){      //CREATE A BRIDGE FROM GUIDE TO TOURIST
                guide->right=tourist;
                tourist=tourist->left;
            }
            else{
                guide->right=nullptr;       //IF BRIDGE ALREADY EXISTS, THEN DESTROY THE BRIDGE and MOVE TOURIST TO THE RIGHT
                ans.push_back(tourist->data);
                tourist=tourist->right;
            }
        }
        else{
            ans.push_back(tourist->data);
            tourist=tourist->right;

        }
        
    }
    return ans;

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
    vector<int> output = MorrisTraversal(root);
    for(int x:output)
    {
        cout<<x<<" ";
    }

    
}