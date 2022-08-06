#include <cstdio>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool myfindLeaves(TreeNode* root, vector<int>& leaves) {
        if (root -> left == nullptr && root -> right == nullptr) {
            leaves.push_back(root->val);
            return true;
        }

        if (root -> left != nullptr) {
            if(myfindLeaves(root->left, leaves))
                root->left = nullptr;
        }
        if (root -> right != nullptr){
            if(myfindLeaves(root->right, leaves))
                root->right = nullptr;
        }

        return false;
    }
    vector<vector<int>> myfindLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        while (root != nullptr) {
            vector<int> leaves;
            if (myfindLeaves(root, leaves))
                root = nullptr;
            if (!leaves.empty())
                ans.push_back(leaves);
        }

        return ans;
    }

    int sortLeavesByHeight(TreeNode* root, vector<vector<int>>& leaves_by_height) {
        if (root == nullptr)
            return -1;

        int h = max(sortLeavesByHeight(root->left, leaves_by_height),
                    sortLeavesByHeight(root->right, leaves_by_height)) + 1;

        if (leaves_by_height.size() == h) {
            leaves_by_height.push_back({});
        }
        leaves_by_height[h].push_back(root->val);

        return h;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        sortLeavesByHeight(root, ans);
        return ans;
    }
};

int main() {
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n2(2, &n4, &n5);
    TreeNode n3(3);
    TreeNode n1(1, &n2, &n3);

    Solution solution;
    vector<vector<int>> leaves = solution.findLeaves(&n2);
    for(auto it=leaves.begin(); it != leaves.end(); ++it) {
        printf("%d", (*(*it).begin()));
        for (auto jt=++(*it).begin(); jt != (*it).end(); ++jt) {
            printf(", %d", *jt);
        }
        printf("\n");
    }
}
