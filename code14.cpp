// 7-14 不变初心数
// 分数 15
// 作者 陈越
// 单位 浙江大学
// 不变初心数是指这样一种特别的数，它分别乘 2、3、4、5、6、7、8、9 时，所得乘积各位数之和却不变。
//例如 18 就是这样的数：18 的 2 倍是 36，3+6=9；18 的 3 倍是 54，5+4=9；…… 18 的 9 倍是 162，1+6+2=9。
//对于 18 而言，9 就是它的初心。本题要求你判断任一个给定的数是否有不变的初心。

// 输入格式：
// 输入在第一行中给出一个正整数 N（≤ 100）。随后 N 行，每行给出一个不超过 10^5 
//   的正整数。

// 输出格式：
// 对每个给定的数字，如果它有不变的初心，就在一行中输出它的初心；否则输出 NO。

// 输入样例：
// 4
// 18
// 256
// 99792
// 88672
// 输出样例：
// 9
// NO
// 36
// NO
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,num;
    cin>>n;
    while(n--){
        cin>>num;
        bool flag=true;//设置标记
        int result[10]={0};//记录结果
        for(int i=2;i<=9;i++){
        int temp=num;
        temp*=i;
        while(temp){
            int j=temp%10;
            temp/=10;
            result[i]+=j;
        }
        if(i>2&&result[i]!=result[2]){//如果出现不相等就不是初心数
                cout<<"NO"<<endl;
                flag=false;
                break;
        }
    }
        if(flag){
                cout<<result[2]<<endl;
        }
    }
   
}