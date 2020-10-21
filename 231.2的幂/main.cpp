#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0)
            return false;

        if (n == 1)
            return true;

        if (n % 2 == 0)
            return isPowerOfTwo(n / 2);
        else
            return false;
    }
};

// 位运算法
//class Solution {
//public:
//    bool isPowerOfTwo(int n) {
//        return n > 0 && (n & n - 1) == 0;
//    }
//};

int main() {
    int x = 25;
    Solution s;

    auto r = s.isPowerOfTwo(x);
    cout << r << endl;

    return 0;
}
