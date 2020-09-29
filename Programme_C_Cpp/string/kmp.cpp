#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    int next[1000005] = {0}, j = 0;
    cin >> s1 >> s2;
    for (int i = 1; i < (int)s2.size(); ++i)
    {
        while (j && s2[i] != s2[j])
            j = next[j - 1];
        if (s2[i] == s2[j])
            next[i] = ++j;
    }
    j = 0;
    for (int i = 0; i < (int)s1.size(); ++i)
    {
        while (j && s1[i] != s2[j])
            j = next[j - 1];
        if (s1[i] == s2[j])
            ++j;
        if (j == (int)s2.size())
        {
            cout << i - j + 2 << endl;
            j = next[j - 1];
        }
    }
    for (int i = 0; i < (int)s2.size(); ++i)
        cout << next[i] << ' ';
    cout << endl;
    return 0;
}