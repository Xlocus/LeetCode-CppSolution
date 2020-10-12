#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        auto locVec = vector<int>();

        if (rowIndex == 0){
            locVec.push_back(1);
            return locVec;
        }

        if (rowIndex == 1){
            locVec.push_back(1);
            locVec.push_back(1);
            return locVec;
        }

        vector<int> tempVec = getRow(rowIndex - 1);

        locVec.push_back(1);
        for (int i = 1; i < tempVec.size(); ++i) {
            locVec.push_back(tempVec[i] + tempVec[i - 1]);
        }
        locVec.push_back(1);

        return locVec;
    }
};

// 使用动态规划优化
//class Solution {
//public:
//    vector<int> getRow(int rowIndex) {
//        vector<int> kRows(rowIndex+1);  // 第K行的vector大小为 rowIndex+1
//        for(int i = 0; i <= rowIndex; i++)  // 利用前一行求后一行，第K行要循环K遍
//        {
//            kRows[i] = 1;  // 行末尾为1
//            for(int j = i; j > 1; j--)  // 每一行的更新过程
//            {
//                kRows[j-1] = kRows[j-2] + kRows[j-1];
//            }
//        }
//        return kRows;
//    }
//};

int main() {
    int x = 4;
    Solution s;

    auto r = s.getRow(x);

    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }
    return 0;
}
