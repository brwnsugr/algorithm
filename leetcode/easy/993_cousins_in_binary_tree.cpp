class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        unordered_map<int, vector<int>> cousins;
        int x_depth;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int size = int(q.size());
            while(size--){
                TreeNode *here = q.front();
                q.pop();
                if(here->val == x) x_depth = depth;
                cousins[depth].push_back(here->val);
                if(here->left != nullptr){
                    q.push(here->left);
                }
                if(here->right != nullptr){
                    q.push(here->right);
                }
                if(here->left != nullptr && here->right != nullptr){
                    if((here->left->val == x && here->right->val == y) ||
                       (here->left->val == y && here->right->val == x)){
                        return false;
                    }
                }
            }
            depth++;
        }
        for(int i = 0; i < cousins[x_depth].size(); i++){
            if(cousins[x_depth][i] == y){
                return true;
            }
        }
        return false;
    }
};