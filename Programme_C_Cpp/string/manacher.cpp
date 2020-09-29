#include <cstdio>
#include <cstring>

char str[1005], str2[2005];
int center, maxn;

void init()
{
    int size = strlen(str);
    str2[0] = '$';
    int k = 1;
    for (int i = 0; i < size; ++i)
        str2[k++] = '#', str2[k++] = str[i];
    str2[k] = '#';
}

void manacher()
{
    int id, mx = 0, size = strlen(str2);
    int len[1005] = {0};
    for (int i = 1; i < size; ++i)
    {
        if (i < mx)
            len[i] = mx - i < len[2 * id - i] ? mx - i : len[2 * id - i];
        else
            len[i] = 1;
        while (str2[i + len[i]] == str2[i - len[i]])
            ++len[i];
        if (len[i] + i > mx)
        {
            mx = len[i] + i;
            id = i;
            if (len[i] > maxn)
                maxn = len[i], center = i;
        }
    }
}

void print()
{
    for (int i = center - maxn + 1; i < center + maxn; ++i)
        if (str2[i] != '#')
            putchar(str2[i]);
    putchar('\n');
}

int main()
{
    scanf("%s", str);
    init();
    manacher();
    print();
    return 0;
}