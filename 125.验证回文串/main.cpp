#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;

        auto i = 0;
        auto j = s.size() - 1;

        while (i < j){
            if (!((s[i] >= 48 && s[i] <=57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))){
                ++i;
                continue;
            }

            if (!((s[j] >= 48 && s[j] <=57) || (s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122))){
                --j;
                continue;
            }

            if ((s[i] == s[j]) || (s[i] + 32 == s[j] && s[i] >= 65 && s[i] <= 90) ||
                (s[i] == s[j] + 32 && s[j] >= 65 && s[j] <= 90)){
                ++i;
                --j;
            } else
                return false;
        }

        return true;
    }
};

int main() {
    string string1 = "ab@a";
    Solution s;

    auto r = s.isPalindrome(string1);
    cout << r << endl;

    return 0;
}
