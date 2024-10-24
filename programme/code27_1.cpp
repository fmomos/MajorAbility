// 7-27 样本方差
// 分数 15
// 作者 ldm
// 单位 成都信息工程大学
// u=3226723262,278720713&fm=15&gp=0.jpg

// 作为概率论随便考100分的你，口算出给定样本的方差自然也不在话下，不过今天需要你编程实现这样的程序。

// 输入格式:
// 输入共两行。

// 第一行为一个正整数n,(2≤n≤10000)，即给定样本的数量。

// 第二行为n个整数，为每个样本的值。

// 输出格式:
// 输出仅 1 行，为计算出来的样本方差（保留 2 位小数，不足用 0 补齐）。

// 输入样例:
// 4
// 974 559 974 233
// 输出样例:
// 129074.00
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double sum=0,s1=0;
    vector<double> sample(n);
    for(int i=0;i<n;i++){
        cin>>sample[i];
    }
    for(double i:sample){
        sum+=i;
    }
    double x=sum/n;
     for(double i:sample){
        s1+=(i-x)*(i-x);
    }
    double s=s1/(n-1);
    cout<<fixed<<setprecision(2)<<s;
}
//double