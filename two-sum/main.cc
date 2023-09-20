#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (const auto it = s.find(target - nums[i]); it != s.end()) {
                return {i, it->second};
            }
            s[nums[i]] = i;
        }
        return {};
    }
};