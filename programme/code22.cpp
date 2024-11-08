// 7-23 栈操作的合法性
// 分数 15
// 作者 DS课程组
// 单位 浙江大学
// 假设以S和X分别表示入栈和出栈操作。
// 如果根据一个仅由S和X构成的序列，对一个空堆栈进行操作，相应操作均可行（如没有出现删除时栈空）且最后状态也是栈空，
// 则称该序列是合法的堆栈操作序列。请编写程序，输入S和X序列，判断该序列是否合法。

// 输入格式:
// 输入第一行给出两个正整数 n 和 m，其中 n 是待测序列的个数，m（≤50）是堆栈的最大容量。随后 n 行，
// 每行中给出一个仅由S和X构成的序列。序列保证不为空，且长度不超过100。

// 输出格式:
// 对每个序列，在一行中输出YES如果该序列是合法的堆栈操作序列，或NO如果不是。

// 输入样例：
// 4 10
// SSSXXSXXSX
// SSSXXSXXS
// SSSSSSSSSSXSSXXXXXXXXXXX
// SSSXXSXXX
// 输出样例：
// YES
// NO
// NO
// NO
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        int max_size=0;
        bool error=false;
        string s;
        cin >> s;
        for (char c : s)
        {
            if (c == 'S')
            {
                max_size++;
            }
            else if(c=='X')
            {
                max_size--;
            }
            if (max_size < 0 || max_size > m)
            {
                error=true;//标记，最后再输出
                break;
            }
        }
        if (max_size==0&&!error)
        {
            cout <<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}