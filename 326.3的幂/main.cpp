#include <iostream>
using namespace std;

//class Solution {
//public:
//    bool isPowerOfThree(int n) {
//        if (n == 0)
//            return false;
//
//        if (n == 1)
//            return true;
//
//        if (n % 3 == 0)
//            return isPowerOfThree(n / 3);
//        else
//            return false;
//    }
//};

// 对数运算，换底公式
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;

        double a = log10(n) / log10(3) ;
        return  a == floor(a);
    }
};

// 正则匹配



int main() {
    int x = 27;
    Solution s;

    auto r = s.isPowerOfThree(x);
    cout << r << endl;

    return 0;
}
