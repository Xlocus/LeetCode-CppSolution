#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = int(s.size()) - 1;

        while (i < j){
            swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
};

int main() {
    auto v = vector<char>();
    v.push_back('h');
    v.push_back('e');
    v.push_back('l');
    v.push_back('l');
    v.push_back('o');

    Solution s;
    s.reverseString(v);

    for (auto val : v) {
        cout << val << endl;
    }
    return 0;
}
