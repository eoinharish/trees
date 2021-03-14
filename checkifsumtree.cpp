//add func return the sum of all nodes in a binary tree

int add(Node* root)
{
    if(root==nullptr)
        return 0;
    int sum=root->data+add(root->left)+add(root->right);
    return sum;
}

bool isSumTree(Node* root)
{
     if(root==nullptr)
        return true;
    if(root->left==nullptr && root->right==nullptr)
        return true;
        
    int leftsum=add(root->left);
    int rightsum=add(root->right);
    if(root->data==leftsum+rightsum)
        return true;
    return false;
    
}