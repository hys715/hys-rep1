#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int st[100001][18];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    int n, m, l, r, k;
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        st[i][0] = read();
    for (int j = 1; j < 18; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    while (m--)
    {
        l = read(), r = read();
        k = log(r - l + 1) / log(2);
        printf("%d\n", max(st[l][k], st[r - (1 << k) + 1][k]));
    }
    return 0;
}