/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
public:
    //(1)
    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     if(nums.empty()) return nullptr;
    //     auto max_it=max_element(nums.begin(), nums.end());
    //     TreeNode*root=new TreeNode(*max_it);
    //     vector<int> left(nums.begin(), max_it);
    //     vector<int> right(max_it+1, nums.end());
    //     root->left=constructMaximumBinaryTree(left);
    //     root->right=constructMaximumBinaryTree(right);
    //     return root;
    // }
    //(2)
    // TreeNode* makeMBT(vector<int>& nums,int left, int right) {
    //     if(left>=right) return nullptr;
    //     auto max_it=max_element(nums.begin()+left, nums.begin()+right);
    //     int max_index=max_it-nums.begin();
    //     TreeNode*root=new TreeNode(*max_it);
    //     root->left=makeMBT(nums, left, max_index);
    //     root->right=makeMBT(nums, max_index+1, right);
    //     return root;
    // }
    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     return makeMBT(nums, 0, nums.size());
    // }
    //(3) monotonic stack
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> s;
        for (auto num:nums) {
            auto c = new TreeNode(num);
            while (!s.empty() && s.top()->val < c->val) {
                    c->left = s.top();
                    s.pop();
            }
            if (!s.empty()) s.top()->right = c;
            s.push(c);
        }
        // get the root
        while (s.size() != 1) s.pop();
        return s.top();
    }
};

