#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> rq;
    int size = 0;
public:
    int ping(int t) {
        rq.push(t);
        ++size;

        while (!rq.empty() && rq.front() < t-3000){
            rq.pop();
            --size;
        }

        return size;
    }
};

int main() {
    RecentCounter rc;
    cout << rc.ping(1) << " ";
    cout << rc.ping(100) << " ";
    cout << rc.ping(3001) << " ";
    cout << rc.ping(3002) << " ";
    return 0;
}
