/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root==NULL)
            return 0;
        if((root->left==NULL)&&(root->right==NULL))
            return 1;
            
        int lmax=maxDepth(root->left)+1;    //左子树深度
        int rmax=maxDepth(root->right)+1;   //右子树深度
        
        return lmax>rmax?lmax:rmax;         //树的深度
    }
};
