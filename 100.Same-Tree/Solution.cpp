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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL)     //递归终止条件
            if(q!=NULL)
                return false;
            else
                return true;
        if(q==NULL)     //为了美观，就对称地写，其实可以不用这么写
            if(p!=NULL)
                return false;
            else
                return true;
                
        if((p->val==q->val)&&(isSameTree(p->left,q->left))&&(isSameTree(p->right,q->right)))    //递归左子树和右子树
            return true;
        else
            return false;
    }
};
