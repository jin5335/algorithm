#include <iostream>
#include <vector>

using namespace std;

int get_min_coins(int K, vector<int>& coins) {
    int cnt_coins = 0;
    for(int i=coins.size()-1; i>=0; --i) {
       if (K == 0)
           break;

       cnt_coins += (K/coins[i]);
       K -= (K/coins[i])*coins[i];
    }

    return cnt_coins;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> coins;
    for(int i=0; i<N; ++i) {
        int c;
        cin >> c;
        coins.push_back(c);
    }
    cout << get_min_coins(K, coins) << endl;
    return 0;
}