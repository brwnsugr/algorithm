class Solution {
public:
    Solution(): n(0){}
    void inorder(int& k, TreeNode* curr){
        if(curr->left != nullptr) inorder(k, curr->left);
        n++;
        if(n==k){
            answer = curr->val;
            return;
        }
        if(curr->right != nullptr) inorder(k, curr->right);
        return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(k, root);
        return answer;
    }
private:
    int answer;
    int n;
};