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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> nodes;
        queue<TreeNode*> next;
        nodes.push(root);
        next.push(root);
        while(!nodes.empty()){
            vector<int> level;
            while(!nodes.empty()){
                TreeNode *temp=nodes.front();
                nodes.pop();
                next.pop();
                level.push_back(temp->val);
                if(temp->left)
                    next.push(temp->left);
                if(temp->right)
                    next.push(temp->right);
            }
            res.insert(res.begin(),level);      //每一层插在vector头部即可
            nodes=next;
        }
        return res;
    }
};
