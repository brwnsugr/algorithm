class Solution {
public:
    TreeNode* construct_bst(TreeNode* &root, int node_val){
        if(root == NULL){
            return root = new TreeNode(node_val); // 아무것도 없는 경우, 최초로 root element로 만들어서 return 해줌
        }
        else{
            if(node_val < root->val){
                root->left = construct_bst(root->left, node_val);
            }
            else{
                root->right = construct_bst(root->right, node_val);
            }
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) { // 프리오더
        TreeNode* root = NULL;

        for(int i = 0; i < preorder.size(); i++){
            construct_bst(root, preorder[i]);
        }
        return root;
    }
};