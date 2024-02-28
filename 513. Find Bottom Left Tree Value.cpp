//dfs
class Solution {
public:
    void solve(TreeNode *root, int &ans, int depth, int &maxdepth) {
        if (root == nullptr) return;
        if (depth > maxdepth) {
            maxdepth = depth;
            ans = root->val;
        }
        solve(root->left, ans, depth + 1, maxdepth);
        solve(root->right, ans, depth + 1, maxdepth);
    }
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = root->val;
        int maxdepth = -1;
        solve(root, ans, 0, maxdepth);
        return ans;
    }
};

//bfs1
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        //bfs 1
        if(root==NULL) return NULL;
        int bottomleft=root->val;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            bottomleft = node->val;
            if(node->right) que.push(node->right);
            if(node->left) que.push(node->left);
        }
        return bottomleft;
    }
};

//bfs 2
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        //bfs 2
        if(root==NULL) return NULL;
        queue<TreeNode*>que;
        que.push(root);
        int ans=root->val;
        while(!que.empty()){
            int n=que.size();
            while(n--){
                TreeNode *node = que.front();
                que.pop();
                ans=node->val;
                if(node->right) que.push(node->right);
                if(node->left) que.push(node->left);
            }
        }
        return ans;
    }
};
