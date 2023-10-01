#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) return s;
        if (s.size() == 2) return s[0] == s[1] ? s : s.substr(0, 1);

        string_view longest = string_view(s.c_str(), 1);
        for (int i = 0; i < s.size() - 1; ++i) {
            bool odd = true, even = s[i] == s[i + 1];
            if (even && longest.size() == 1) longest = string_view(s.c_str() + i, 2);
            int odd_j = -1, even_j = -1;
            for (int j = 1; i - j >= 0 && i + j < s.size() && (odd || even); ++j) {
                if (odd && s[i - j] == s[i + j]) {
                    odd_j = j;
                } else {
                    odd = false;
                }
                if (even && s[i - j] == s[i + j + 1]) {
                    even_j = j;
                } else {
                    even = false;
                }
            }

            if (odd_j * 2 + 1 > int(longest.size())) {
                longest = string_view(s.c_str() + i - odd_j, odd_j * 2 + 1);
            }

            if (even_j * 2 + 2 > int(longest.size())) {
                longest = string_view(s.c_str() + i - even_j, even_j * 2 + 2);
            }
        }

        return string(longest);
    }
};
