#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto temp = vector<int>(2, -1);
        auto low = 0;
        auto high = numbers.size() - 1;

        while (low < high){
            if (numbers[low] + numbers[high] == target){
                temp[0] = low + 1;
                temp[1] = high + 1;
                break;
            }

            if (numbers[low] + numbers[high] < target)
                ++low;
            else
                --high;
        }

        return temp;
    }
};

int main() {
    auto t = 9;
    auto v = vector<int>();
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);

    Solution s;
    auto r = s.twoSum(v, t);

    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }

    return 0;
}
