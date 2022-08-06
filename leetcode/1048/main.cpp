#include <cstdio>
#include <string>
#include <vector>
#include <map>


using namespace std;

bool isPredecessorOfB(const string& word_a, const string& word_b){
    for(int i=0; i<word_b.size(); ++i) {
        int p=0;
        bool is_same = true;
        while(p < word_a.size()) {
            int k = p < i ? p : p + 1;
            if(word_a[p] != word_b[k]) {
                is_same = false;
                break;
            }
            ++p;
        }
        if (is_same)
            return true;
    }
    return false;
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<int, vector<int>> words_by_length;
        for (int i=0;i<words.size(); ++i) {
            words_by_length[words[i].size()].push_back(i);
        }

        vector<int> d(words.size(), 1);
        int longest = 1;
        for (const auto& iter : words_by_length) {
            if (words_by_length.find(iter.first-1) == words_by_length.end())
                continue;

            vector<int>& words_b = words_by_length[iter.first];
            vector<int>& predecessors = words_by_length[iter.first-1];
            for (int i : words_b) {
                for(int j : predecessors) {
                    if (d[i] == words[i].size())
                        break;
                    if (isPredecessorOfB(words[j], words[i])) {
                        d[i] = d[j]+1 > d[i] ? d[j]+1 : d[i];
                    }
                }
                longest = d[i] > longest ? d[i] : longest;
            }
        }
        return longest;
    }
};

int main() {
    Solution solution;
    //vector<string> words  = {"a","b","ba","bca","bda","bdca"};
    vector<string> words = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
    printf("%d\n", solution.longestStrChain(words));
    return 0;
}
