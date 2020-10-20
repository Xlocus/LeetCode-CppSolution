#include <iostream>
#include <vector>
using namespace std;

// 普通方法
//class Solution {
//public:
//    int countPrimes(int n) {
//        if (n < 2)
//            return 0;
//
//        int count = 0;
//
//        for (int i = 2; i < n; ++i) {
//            auto flag = false;
//
//            for (int j = 2; j*j <= i; ++j) {
//                if (i % j == 0){
//                    flag = true;
//                    break;
//                }
//            }
//
//            if (!flag)
//                ++count;
//        }
//
//        return count;
//    }
//};

// 线性筛法
//class Solution {
//public:
//    int countPrimes(int n) {
//        if (n < 2)
//            return 0;
//
//        int count = 0;
//        auto check = vector<int>(n, 0);
//        check[0] = 1;
//        check[1] = 1;
//        auto prime = vector<int>(n, 0);
//
//        for (int i = 2; i < n; ++i) {
//            if (!check[i])
//                prime[count++] = i;
//
//            for (int j = 0; j < count && i * prime[j] < n; ++j) {
//                check[i * prime[j]] = 1;
//
//                if (i % prime[j] == 0)
//                    break;
//            }
//        }
//
//        return count;
//    }
//};

// 厄拉多塞筛法
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;

        int count = 0;
        auto check = vector<int>(n, 0);
        check[0] = 1;
        check[1] = 1;

        for (int i = 2; i < n; ++i) {
            if (!check[i]){
                ++count;

                for (int j = 2 * i; j < n; j += i) {
                    check[j] = 1;
                }
            }
        }

        return count;
    }
};

int main() {
    int x = 10;
    Solution s;
    auto r = s.countPrimes(x);
    cout << r << endl;

    return 0;
}
