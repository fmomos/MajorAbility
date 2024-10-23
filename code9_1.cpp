// 7-9 个位数统计
// 分数 15
// 作者 陈越
// 单位 浙江大学
// 给定一个 k 位整数 N
// 请编写程序统计每种不同的个位数字出现的次数。例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

// 输入格式：
// 每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。

// 输出格式：
// 对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。要求按 D 的升序输出。

// 输入样例：
// 100311
// 输出样例：
// 0:2
// 1:3
// 3:1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    int a[10]={0};
    cin >> n;
    for(char temp:n)
    {

        if (temp == '0')
        {
            a[0]++;
        }else if(temp=='1'){
            a[1]++;
        }else if(temp=='2'){
            a[2]++;
        }else if(temp=='3'){
            a[3]++;
        }else if(temp=='4'){
            a[4]++;
        }else if(temp=='5'){
            a[5]++;
        }else if(temp=='6'){
            a[6]++;
        }else if(temp=='7'){
            a[7]++;
        }else if(temp=='8'){
            a[8]++;
        }else if(temp=='9'){
            a[9]++;
        }
    }
    for(int i=0;i<10;i++){
        if(a[i]!=0){
            cout<<i<<":"<<a[i]<<endl;
        }
    }
}
//应该用字符串，用整数的话1000位会超出整数最大范围！！