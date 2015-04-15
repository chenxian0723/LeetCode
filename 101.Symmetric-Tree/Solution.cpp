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

    bool symTree(TreeNode *root1,TreeNode *root2){
        if((root1==NULL)&&(root2==NULL))
            return true;
        if((root1==NULL)||(root2==NULL))
            return false;
        if(root1->val!=root2->val)
            return false;
        return symTree(root1->left,root2->right)&&symTree(root1->right,root2->left);
        //左子树的左儿子和右子树的右儿子是否对称
        //左子树的右儿子和右子树的左儿子是否对称
        //节点的值也必须相等
    }
    
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)
            return true;
        return symTree(root->left,root->right);   
    }
    
};
