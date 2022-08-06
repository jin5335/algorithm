#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

bool cmp(vector<int> &a, vector<int>& b) {
    return (a[0] < b[0]) || (a[0] == b[0] && a[1] <= b[1]);
}

class SolutionWithPQ {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> ongoing;
        int res = 0;
        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
            while (!ongoing.empty() && ongoing.top() <= (*it)[0]) {
                ongoing.pop();
            }
            ongoing.push((*it)[1]);

            if (ongoing.size() > res)
                res = ongoing.size();
        }
        return res;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> times;
        for(auto it: intervals){
            // 같은 시간일 경우 끝 시간이 시작 시간보다 먼저 오도록 second 셋팅
            times.push_back(make_pair(it[0], 1)); // 시작 시간
            times.push_back(make_pair(it[1], 0)); // 끝 시간
        }
        sort(times.begin(), times.end());
        int res = 0, cnt_rooms=0;
        for (auto it: times) {
            if (it.second == 1) {
                ++cnt_rooms; // 새로운 meeting 추가
            } else {
                --cnt_rooms; // 진행중이던 강의가 끝남
            }
            res = cnt_rooms > res ? cnt_rooms : res;
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15,20}};
    Solution sol;
    cout << sol.minMeetingRooms(intervals) << endl;
    return 0;
}