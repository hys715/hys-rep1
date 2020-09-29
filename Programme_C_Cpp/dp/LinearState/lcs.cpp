//读入从1到n的两组全排列，求最长公共子序列

#include <iostream>
#include <algorithm>
using namespace std;

//f记录数字位置，dp记录最长不下降子序列
int f[100005], dp[100005];

int main()
{
	int n, x, len = 0;
	cin >> n;
	//读入第一组数字，并将数字位置记录下来
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		f[x] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		//读入第二组数字，找到数字在第一组数字的位置
		//将问题转换为求解最长不下降子序列
		cin >> x;
		//若f[x]大于序列最后一个元素，则直接插入
		if (f[x] > dp[len])
			dp[++len] = f[x];
		//否则在现有不下降序列中找到第一个大于f[x]的数替换
		else 
			*upper_bound(dp + 1, dp + 1 + len, f[x]) = f[x];
	}
	//输出不下降子序列长度
	cout << len << endl;
	return 0;
}