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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;      
        stack<TreeNode*> s;         //栈用来存放节点
        while((root!=NULL)||(!s.empty())){
            while(root!=NULL){      //树进行深度优先遍历，每次往左走
                s.push(root);
                root=root->left;
            }
            if(!s.empty()){         //左边无法再走时，弹出一个节点，并往右走一步
                root=s.top();
                res.push_back(root->val);       //由于是求中序遍历，因此每次弹出的时候打印节点
                s.pop();
                root=root->right;
            }
        }
        return res;
    }
};
