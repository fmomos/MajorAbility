// 7-3 计算阶乘和
// 分数 15
// 作者 陈越
// 单位 浙江大学
// 对于给定的正整数N，需要你计算 S=1!+2!+3!+...+N!。

// 输入格式：
// 输入在一行中给出一个不超过10的正整数N。

// 输出格式：
// 在一行中输出S的值。

// 输入样例：
// 3
// 输出样例：
// 9
#include <bits/stdc++.h>
using namespace std;
int factorial(int n){
    int s=1;
    for(int i=1;i<=n;i++){
        s*=i;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++){
        s+=factorial(i);
    }
    cout<<s;

}
//while（n--）
//第一次判断：符号在后，后递减，先参与运算，也就是先将n本身作为while()语句判断，n=5 > 0，即while()判断结果为真，判断执行结束后，此时将n递减 n=4