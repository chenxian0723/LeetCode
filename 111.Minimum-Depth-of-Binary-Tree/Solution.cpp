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
    int minDepth(TreeNode *root) {
        if(root==NULL)
            return 0;
        if((root->left==NULL)&&(root->right==NULL))       //叶子节点深度为1
            return 1;
        if((root->left==NULL))                            //左节点为空的话，深度为右子树+1
            return minDepth(root->right)+1;
        else if((root->right==NULL))                      //右节点为空的话，深度为左子树+1
            return minDepth(root->left)+1;
        else
            return min(minDepth(root->left),minDepth(root->right))+1;
    }

};
