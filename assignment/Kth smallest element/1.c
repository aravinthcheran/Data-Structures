int maxi(int node1,int node2)
{
    if(node1>node2)
    {
        return node1;
    }
    else
    {
        return node2;
    }
}
int diameter(struct TreeNode *root, int *d)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftdepth=diameter(root->left,d);
    int rightdepth=diameter(root->right,d);
    int depth=leftdepth+rightdepth;
    *d=maxi(*d,depth);
    int maximum=maxi(leftdepth,rightdepth);
    return maximum+1;
}
int diameterOfBinaryTree(struct TreeNode* root){
    if (root==NULL)
    {
        return 0;
    }
    int d=0;
    diameter(root,&d);
    return d;
}