#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void generate_permutations(int k, vector<int>& p, vector<vector<int>>& permutations) {
        if (k == p.size()) {
            permutations.push_back(p);
        }

        for (int i=k; i<p.size(); ++i) {
            swap(p[k], p[i]);
            generate_permutations(k+1, p, permutations);
            swap(p[k], p[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;

        generate_permutations(0, nums, permutations);
        return permutations;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution solution;
    vector<vector<int>> permutations = solution.permute(nums);
    for (auto p : permutations) {
        for (auto num : p) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
