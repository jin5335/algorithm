#include <iostream>
#include <vector>

using namespace std;

class SolutionWithRecursion {
public:
    void generate_combination(int n, int k, vector<int>& combination, vector<vector<int>>& combinations) {
        if (k == 0) {
            combinations.push_back(vector<int>(++combination.begin(), combination.end()));
            return;
        }

        for(int i=combination.back()+1; i<=n; ++i) {
            combination.push_back(i);
            generate_combination(n, k-1, combination, combinations);
            combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combination;
        combination.push_back(0);
        generate_combination(n, k, combination, combinations);
        return combinations;
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;

        vector<int> combination(k, 0);
        int p = 0;
        while (p >= 0) {
            ++combination[p];
            if (combination[p] > n) --p;
            else if (p+1 == k) combinations.push_back(combination);
            else {
                ++p;
                combination[p] = combination[p-1];
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> combinations = solution.combine(4,2);
    for(auto combi : combinations) {
        for(auto c : combi) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
