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
    TreeNode *sortedArrayToBST2(vector<int> &num,int begin,int end) {
        if(begin>end)
            return NULL;
        int mid=(begin+end)/2;
        TreeNode *root=new TreeNode(num[mid]);        //中间值为根节点
        root->left=sortedArrayToBST2(num,begin,mid-1);        //小于中间值的插入左子树
        root->right=sortedArrayToBST2(num,mid+1,end);         //大于中间值的插入右子树
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        int end=num.size()-1;
        return sortedArrayToBST2(num,0,end);
    }
};
