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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> nodes;
        queue<TreeNode*> next;
        nodes.push(root);     //保存当前层要输出的节点
        next.push(root);      //保存下一层的节点
        while(!nodes.empty()){        //广度优先搜索，用队列储存节点
            vector<int> level;        //记录每一层节点的值
            while(!nodes.empty()){          //一次输出一层
                TreeNode *temp=nodes.front();
                nodes.pop();
                next.pop();
                level.push_back(temp->val);
                if(temp->left)
                    next.push(temp->left);
                if(temp->right)
                    next.push(temp->right);
            }
            res.push_back(level);
            nodes=next;
        }
        return res;
    }
};
