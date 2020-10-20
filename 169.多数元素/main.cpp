#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        auto mp = map<int, int>();
//        auto tempVal = nums.size() / 2;
//
//        for (int i = 0; i < nums.size(); ++i) {
//            if (mp.count(nums[i]) == 0)
//                mp[nums[i]] = 1;
//            else
//                mp[nums[i]] += 1;
//        }
//
//        for (auto i = mp.begin(); i != mp.end(); ++i) {
//            if (i->second > tempVal)
//                return i->first;
//        }
//
//        return -1;
//    }
//};

//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        unordered_map<int, int> counts;
//        int majority = 0, cnt = 0;
//
//        for(auto num : nums){
//            ++counts[num];
//
//            if (counts[num] > cnt){
//                majority = num;
//                cnt = counts[num];
//            }
//        }
//
//        return majority;
//    }
//};

class Solution {
public:
    int count_in_range(vector<int> &nums, int target, int left, int right){
        int count = 0;
        for (int i = left; i <= right; ++i) {
            if (nums[i] == target)
                ++count;
        }

        return count;
    }

    int majority_element_rec(vector<int> &nums, int left, int right){
        if (left == right)
            return nums[left];

        int mid = (left + right) / 2;
        int left_majority = majority_element_rec(nums, left, mid);
        int right_majority = majority_element_rec(nums, mid + 1, right);

        if (count_in_range(nums, left_majority, left, right) > (right - left + 1) / 2)
            return left_majority;

        if (count_in_range(nums, right_majority, left, right) > (right - left + 1) / 2)
            return right_majority;

        return -1;
    }

    int majorityElement(vector<int>& nums) {
        return majority_element_rec(nums, 0, nums.size() - 1);
    }
};

int main() {
    auto v = vector<int>();
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    Solution s;
    auto r = s.majorityElement(v);
    cout << r << endl;

    return 0;
}
