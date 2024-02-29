//bfs
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>que;
        que.push(root);
        bool even_level=true;
        int prev;
        while(!que.empty()){
            int n=que.size();
            if(even_level){
                prev=INT_MIN;
            }else{
                prev=INT_MAX;
            }

            while(n--){
                TreeNode *node = que.front();
                que.pop();
                if(even_level){
                    //if even level then odd interger && node->val>prev
                    if(node->val%2!=1 || node->val<=prev) return false;
                }
                else{
                    //if odd level then even interger && node->val<prev
                    if(node->val%2!=0 || node->val>=prev) return false;
                } 

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

                prev=node->val;
            }
            even_level=!even_level;
        }
        return true;
    }
};

//dfs
class Solution {
public:
    bool solve(TreeNode*root,vector<int>&level,int depth){
        if(!root) return true;

        //even level e odd integer
        if(depth%2==0 && root->val%2!=1) return false;
        // odd level e even integer
        else if(depth%2==1 && root->val%2!=0) return false;

        if(depth>=level.size()) level.resize(depth+1);//resize take O(n)

        if(level[depth]!=0){//if already there's a value present of past level
            if(depth%2==0 && root->val<=level[depth]) return false;
            if(depth%2==1 && root->val>=level[depth]) return false;
        }
        level[depth]=root->val;
        bool left=solve(root->left,level,depth+1);
        bool right=solve(root->right,level,depth+1);
        return left&&right;

    }
    bool isEvenOddTree(TreeNode* root) {
        vector<int>level;
        return solve(root,level,0);
    }
};
