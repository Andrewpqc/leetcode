#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int result = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            set<char> char_set;
            int sub_max = 0;
            for (int j = i; j < len; ++j) {
                auto ret = char_set.insert(s[j]);
                if (ret.second == true) {
                    sub_max += 1;
                } else {
                    if (sub_max > max) {
                        max = sub_max;
                    }
                    break;
                }
            }
            if (sub_max > max) max = sub_max;

        }
        return max;
    }
};


int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("a") << endl;
    return 0;
}