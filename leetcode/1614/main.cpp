#include <iostream>

using namespace std;

class Solution {
public:
    int maxDepth_1(string s) {
        int max_depth = 0, depth = 0;

        for (auto &ch : s) {
            if (ch == '(') {
                ++depth;
                max_depth = depth > max_depth ? depth : max_depth;
            } else if (ch == ')') {
                --depth;
            }
        }

        return max_depth;
    }

    int maxDepth_2(string s) {
        int max_depth = 0, depth = 0;

        for(int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                ++depth;
                max_depth = depth > max_depth ? depth : max_depth;
            } else if (s[i] == ')') {
                --depth;
            }
        }

        return max_depth;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.maxDepth(s) << endl;
}
