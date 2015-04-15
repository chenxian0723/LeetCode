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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *pre=NULL;
        while((root!=NULL)||(!s.empty())){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            if((s.top()->right)&&(s.top()->right!=pre))     //使用一个pre指针记录右子树是否被遍历过
                root=s.top()->right;                        //遍历右子树并且不弹出
            else{
                res.push_back(s.top()->val);                //右子树被遍历后，弹出并输出
                pre=s.top();
                s.pop();
            }
        }
        return res;
    }
};
