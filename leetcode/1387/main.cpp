#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int calculatePowerOfX(int x, map<int, int>& cache) {
        if (x == 1 || cache[x] > 0) {
            return cache[x];
        }

        if (x%2 == 0)
            cache[x] = calculatePowerOfX(x/2, cache) + 1;
        else
            cache[x] = calculatePowerOfX(3*x+1, cache) + 1;
        return cache[x];
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> powers_of_interval;
        map<int, int> cache;

        cache[1] = 0;
        for (int i=lo; i<=hi; ++i) {
            powers_of_interval.push_back(pair<int, int>(i, calculatePowerOfX(i, cache)));
        }

        sort(powers_of_interval.begin(),
             powers_of_interval.end(),
             [](const pair<int, int>& a, const pair<int, int>& b){
                return (a.second < b.second) || (a.second == b.second && a.first < b.first);
        });

        return powers_of_interval[k-1].first;
    }
};

map<int, int> cache;

int calculatePowerOfX(int x) {
    if (x == 1 || cache[x] > 0) {
        return cache[x];
    }

    if (x%2 == 0)
        cache[x] = calculatePowerOfX(x/2) + 1;
    else
        cache[x] = calculatePowerOfX(3*x+1) + 1;
    return cache[x];
}

class OptimalSolution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> power_and_x;

        for (int i=lo; i<=hi; ++i) {
            power_and_x.push_back(pair<int, int> (calculatePowerOfX(i), i));
        }

        sort(power_and_x.begin(), power_and_x.end());

        return power_and_x[k-1].second;
    }
};

int main() {
    OptimalSolution solution;
    cout << solution.getKth(335, 1000, 100) << endl;
    return 0;
}
