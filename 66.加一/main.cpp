#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
//        vector<int> out;
        bool n = false;

        int i = int(digits.size() - 1);

        for (int j = i; j >= 0; --j) {
            int d = digits[j];

            if (j == i){
                if (d + 1 == 10){
                    result.push_back(0);
                    n = true;
                } else{
                    result.push_back(d + 1);
                    n = false;
                }
            } else{
                if (n){
                    if (d + 1 == 10){
                        result.push_back(0);
                        n = true;
                    } else{
                        result.push_back(d + 1);
                        n = false;
                    }
                } else{
                    result.push_back(d);
                    n = false;
                }
            }
        }

        if (n)
            result.push_back(1);

//        for (vector<int>::reverse_iterator j = result.rbegin(); j != result.rend(); ++j) {
//            out.push_back(*j);
//        }
//        return out;

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> v1;
    v1.push_back(4);
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(1);

    Solution s;
    vector<int> r = s.plusOne(v1);
        for (vector<int>::iterator i = r.begin(); i != r.end(); ++i) {
        cout << *i << endl;
    }

    return 0;
}

