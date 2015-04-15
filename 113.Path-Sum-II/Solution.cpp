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
    vector<vector<int>> paths;      //一个全局的数组来记录所有路径
    
    void getPathSum(TreeNode *root, int sum,vector<int> &path) {
        path.push_back(root->val);
        if((sum==root->val)&&(root->left==NULL)&&(root->right==NULL)){
            paths.push_back(path);
            return;
        }
        if(root->left){
            getPathSum(root->left,sum-root->val,path);        //遍历左边
            path.pop_back();        //由于path是引用，因此在上一步操作后多push了一个值，需要pop
        }
        if(root->right){
            getPathSum(root->right,sum-root->val,path);
            path.pop_back();
        }
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(root==NULL)
            return paths;
        vector<int> path;
        getPathSum(root,sum,path);      //path为单条路径
        return paths;
    }
};
