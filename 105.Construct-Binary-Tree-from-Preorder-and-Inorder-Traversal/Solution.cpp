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
    TreeNode *buildTree2(vector<int> &preorder,int b1,int e1,vector<int> &inorder,int b2,int e2) {
        if(b1>e1)
            return NULL;
        int rval=preorder[b1];     //前序第一个节点为根节点
        TreeNode *root=new TreeNode(rval);
        if(b1!=e1){
            int pos=b2;
            while(inorder[pos]!=rval)       //找到根节点在中序的位置
                pos++;      
            root->left=buildTree2(preorder,b1+1,pos+b1-b2,inorder,b2,pos-1);     //中序中根节点左边的为左子树
            root->right=buildTree2(preorder,pos+b1-b2+1,e1,inorder,pos+1,e2);    //中序中根节点右边的为右子树
            //找准左右子树在前序和中序中的位置，递归建立树
        }
        return root;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int size=preorder.size();
        if(size!=0)
            return buildTree2(preorder,0,size-1,inorder,0,size-1);
        else
            return NULL;
    }
};
