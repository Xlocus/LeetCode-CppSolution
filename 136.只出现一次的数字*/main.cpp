#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto ret = 0;
        for (auto num : nums) {
            ret ^= num;
        }

        return ret;
    }
};

int main() {
    auto v = vector<int>();
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);

    Solution s;
    auto r = s.singleNumber(v);
    cout << r << endl;

    return 0;
}
