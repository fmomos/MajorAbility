// 7-7 人民币兑换
// 分数 15
// 作者 林颖贤
// 单位 浙江大学
// 1元5角钱人民币兑换5分、2分和1分的硬币（每一种都要有）共100枚，会有很多种兑换方案。请编写程序给出各种兑换方案。

// 输入格式:
// 输入为一个正整数n，表示要求输出前n种可能的方案。方案的顺序，是按照5分硬币从少到多排列的。

// 输出格式:
// 显示前n种方案中5分、2分、1分硬币各多少枚。每行显示一种方案，数字之间空一格，最后一个数字后没有空格。

// 注意：如果全部方案不到n种，就顺序输出全部可能的方案。

// 输入样例:
// 5
// 输出样例:
// 1 46 53
// 2 42 56
// 3 38 59
// 4 34 62
// 5 30 65
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int totalmoney = 150;
    int money1 = 5, money2 = 2, money3 = 1;
    int totalcnt = 100;
    int coutcnt = 0;
    int n;
    cin >> n;
    for (int i = 1; i < totalmoney / money1; i++)
    {
        for (int j = 1; j < totalmoney / money2; j++)
        {
            for (int k = 1; k <= totalcnt - i - j; k++)////k<=100-i-j
            {
                if (i * 5 + j * 2 + k * 1 == 150&&i+j+k==100)//满足两个条件
                {
                    cout << i << " " << j << " " << k << endl;
                    coutcnt++;
                }
                if (coutcnt == n)
                {
                    return 0;
                }
            }
        }
    }
}