#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);

        int cnt_weak = 0, max_y = 0;
        for (int i=properties.size()-1; i>=0; --i) {
            if (properties[i][1] < max_y) {
                ++cnt_weak;
            }
            max_y = max(max_y, properties[i][1]);
        }

        return cnt_weak;
    }
};

int main() {
    vector<vector<int>> input = {{5,5},{6,3},{3,6}};

    Solution sol;
    cout << sol.numberOfWeakCharacters(input) << endl;
    return 0;
}
