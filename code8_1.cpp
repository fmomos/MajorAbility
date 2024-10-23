// 7-8 正整数A+B
// 分数 15
// 作者 陈越
// 单位 浙江大学
// 题的目标很简单，就是求两个正整数A和B的和，其中A和B都在区间[1,1000]。稍微有点麻烦的是，输入并不保证是两个正整数。

// 输入格式：
// 输入在一行给出A和B，其间以空格分开。问题是A和B不一定是满足要求的正整数，有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。

// 注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个空格，并且B不是一个空字符串。

// 输出格式：
// 如果输入的确是两个正整数，则按格式A + B = 和输出。如果某个输入不合要求，则在相应位置输出?，显然此时和也是?。

// 输入样例1：
// 123 456
// 输出样例1：
// 123 + 456 = 579
// 输入样例2：
// 22. 18
// 输出样例2：
// ? + 18 = ?
// 输入样例3：
// -100 blabla bla...33
// 输出样例3：
// ? + ? = ?
#include <bits/stdc++.h>
using namespace std;
bool CanAdd(string a)
{
    if (a.empty())
    {
        return false;
    }
    for (char c : a)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    int num = stoi(a);
    if (num >= 1 && num <= 1000)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string a, b, result;
    cin >> a;
    getchar();//读取空格
    getline(cin,b);//因为把输入中出现的第1个空格认为是A和B的分隔。所以用getline
    bool canA=CanAdd(a);
    bool canB=CanAdd(b);
    if(canA&&canB){
        int A=stoi(a);
        int B=stoi(b);
        cout<<A<<" + "<<B<<" = "<<A+B;
    }else if(!canA&&!canB){
        cout<<"? + ? = ?";
    }else if(!canA){
        int B=stoi(b);
        cout<<"? + "<<B<<" = ?";
       
    }else if(!canB){
        int A=stoi(a);
        cout<<A<<" + ? = ?";
    }
}
//关键在于bool函数，isdigit的判断
// getchar();清除空格，没有参数
// getchar() 是 C 语言标准库中的一个函数，定义在 <stdio.h> 头文件中。
// 它的功能是从标准输入（通常是键盘）读取一个字符，并返回该字符的 ASCII 码值。
// 设置变量int ch;用来存储从 getchar() 读取到的字符 ch = getchar();  // 读取用户输入的一个字符
