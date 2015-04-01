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
    bool isBalanced(TreeNode *root) {
        if(root==NULL)
            return true;
        int depth=0;
        return isBalancedTree(root,depth);
    }
    
    bool isBalancedTree(TreeNode *root,int &depth){
        if(root==NULL){
            depth=0;    //注意要设置深度，空节点的深度为0
            return true;
        }
        int left,right;
        bool flag=isBalancedTree(root->left,left)&&isBalancedTree(root->right,right);   //此步完成时已经获得了左右子树的深度
        if((left-right>1)||(right-left>1))
            return false;
        depth=max(left,right)+1;    //设置深度
        return flag;
    }
};
