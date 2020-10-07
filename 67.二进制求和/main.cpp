#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string &a, string &b) {
        string result;
        string shortStr, longStr;

        if (a.length() < b.length()){
            shortStr = a;
            longStr = b;
        } else{
            shortStr = b;
            longStr = a;
        }

        reverse(shortStr.begin(), shortStr.end());
        reverse(longStr.begin(), longStr.end());

        bool flag;

        int r = shortStr[0] - '0' + longStr[0] - '0';

        if (r >= 2){
            result = to_string(r - 2);
            flag = true;
        } else{
            result  = to_string(r);
            flag = false;
        }

        for (int i = 1; i < shortStr.length(); ++i) {
            int val;
            if (flag)
                val = shortStr[i] - '0' + longStr[i] - '0' + 1;
            else
                val = shortStr[i] - '0' + longStr[i] - '0';

            if (val >= 2){
                result.insert(0, to_string(val - 2));
                flag = true;
            } else{
                result.insert(0, to_string(val));
                flag = false;
            }
        }

        for (int i = shortStr.length(); i < longStr.length(); ++i) {
            int val;
            if (flag)
                val = longStr[i] - '0' + 1;
            else
                val = longStr[i] - '0';

            if (val >= 2){
                result.insert(0, to_string(val - 2));
                flag = true;
            } else{
                result.insert(0, to_string(val));
                flag = false;
            }
        }

        if (flag)
            result.insert(0, to_string(1));

        return result;
    }
};

int main() {
    string s1 = "1001";
    string s2 = "1001";

    Solution s;
    string rs = s.addBinary(s1, s2);
    cout << rs << endl;
    return 0;
}

