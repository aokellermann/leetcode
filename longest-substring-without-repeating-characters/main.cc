#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        std::unordered_set<char> set;
        int i = 0, j = 0, longest = 1;
        while (true) {
            while (set.emplace(s[j]).second && j < s.size()) j++;
            longest = max(longest, j - i);
            if (j == s.size()) break;
            while (set.extract(s[i++]).value() != s[j] && i < j) {}
        }

        return longest;
    }
};