#include <iostream>

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
    void findAndSumLeafNum(TreeNode* root, int& sumNumbers, int number) {
        if (root == nullptr)
            return;

        number = number*2 + root->val;

        if (root -> left != nullptr) {
            findAndSumLeafNum(root->left, sumNumbers, number);
        }

        if (root -> right != nullptr) {
            findAndSumLeafNum(root->right, sumNumbers, number);
        }

        if (root->left == nullptr && root -> right == nullptr) {
           sumNumbers += number;
        }
    }

    int sumRootToLeaf(TreeNode* root) {
        int sumNumbers = 0;
        this->findAndSumLeafNum(root, sumNumbers, 0);
        return sumNumbers;
    }
};

int main() {
    TreeNode n4(0), n5(1), n6(0), n7(1);
    TreeNode n3(1, &n6, &n7), n2(0, &n4, &n5);
    TreeNode n1(1, &n2, &n3);

    Solution solution;
    std::cout << solution.sumRootToLeaf(&n1) << std::endl;
    return 0;
}