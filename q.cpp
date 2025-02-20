#include <iostream>
#include <queue>

using namespace std;

class TreeNode
{   
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void bfs(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            TreeNode* node = q.front();
            q.pop();

            cout<<node->val<<" ";

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout<<endl;
    }
}

int diameter(TreeNode* root, int& maxHeight)
{
    if(root == NULL)
        return 0;

    int l = diameter(root->left, maxHeight);
    int r = diameter(root->right, maxHeight);

    maxHeight = max(l + r, maxHeight);

    return max(l, r) + 1;
}


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    //root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->left->left = new TreeNode(10);
    root->right->left->left->left = new TreeNode(11);

    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    root->right->right->right->right = new TreeNode(9);
    root->right->right->right->right->right = new TreeNode(12);

    /*
        ->     1
    ->    2          3
   ->       5    6     7
                10          8
              11                 9
                                    12
        ANS = 7
    */
    
    int maxHeight = 0;
    diameter(root, maxHeight);
    cout<<maxHeight<<endl;
    return 0;
}