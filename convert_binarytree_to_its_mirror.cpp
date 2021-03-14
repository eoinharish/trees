struct node
{
    int data;
    node* left;
    node* right;
    node(int x): data(x),left(nullptr),right(nullptr) {}
};


void mirror(node* root)
{
    if(root==nullptr)
        return;
    mirror(root->left);
    mirror(root->right);

    struct node* temp;
    temp=root->left);
    root->left=root->right;
    root->right=temp;
    
}