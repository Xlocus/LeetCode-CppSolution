#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//    vector<int> getVec(int num, vector<vector<int>> &vec){
//        auto locVec = vector<int>();
//
//        if (num == 1){
//            locVec.push_back(1);
//            vec.push_back(locVec);
//            return locVec;
//        }
//
//        if (num == 2){
//            locVec.push_back(1);
//            locVec.push_back(1);
//            vec.push_back(locVec);
//            return locVec;
//        }
//
//        vector<int> tempVec = getVec(num - 1, vec);
//
//    }

    vector<vector<int>> generate(int numRows) {
        auto resVec = vector<vector<int>>();
        auto tmpVec = vector<int>();

        if (numRows == 0)
            return resVec;

        tmpVec.push_back(1);
        resVec.push_back(tmpVec);
        if (numRows == 1) return resVec;

        tmpVec.push_back(1);
        resVec.push_back(tmpVec);
        if (numRows == 2) return resVec;

        for (int i = 2; i < numRows; ++i) {
            tmpVec.clear();
            tmpVec.push_back(1);
            for (int j = 1; j < resVec[i - 1].size(); ++j) {
                tmpVec.push_back(resVec[i - 1][j] + resVec[i - 1][j - 1]);
            }
            tmpVec.push_back(1);

            resVec.push_back(tmpVec);
        }

        return resVec;
    }
};

int main() {
    int x = 10;
    Solution s;

    auto r = s.generate(x);

    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
