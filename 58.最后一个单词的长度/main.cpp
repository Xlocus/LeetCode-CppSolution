#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(const string &s)
    {
        if (s.length() == 0)
            return 0;

        int sLength = s.length();
        int i = sLength - 1;
        int count = 0;

        while (i >= 0)
        {
            if (s[i] == ' ')
                --i;
            else
            {
                for (int j = i; j >= 0; --j)
                {
                    if (s[j] != ' ')
                        count += 1;
                    else
                        break;
                }

                break;
            }
        }

        return count;
    }
};

int main() {
    string s1 = "Hello world ";
    Solution sol;
    int sl = sol.lengthOfLastWord(s1);
    cout << sl << endl;
    return 0;
}

