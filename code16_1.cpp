// 7-16 幸运彩票
// 分数 15
// 作者 陈越
// 单位 浙江大学
// 彩票的号码有 6 位数字，若一张彩票的前 3 位上的数之和等于后 3 位上的数之和，则称这张彩票是幸运的。
// 本题就请你判断给定的彩票是不是幸运的。

// 输入格式：
// 输入在第一行中给出一个正整数 N（≤ 100）。随后 N 行，每行给出一张彩票的 6 位数字。

// 输出格式：
// 对每张彩票，如果它是幸运的，就在一行中输出 You are lucky!；否则输出 Wish you good luck.。

// 输入样例：
// 2
// 233008
// 123456
// 输出样例：
// You are lucky!
// Wish you good luck.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        int result[6]={0};//初始化成0！！要不然随机分配，当最前面是0的时候就会出错
        int j = 0,b=0,e=0;
        while (num>0)
        {
            int temp = num % 10;
            num /= 10;
            result[j++] = temp;
        }
        for(int i=0;i<3;i++){
            b+=result[i];
        }
        for(int i=3;i<6;i++){
            e+=result[i];
        }
        if(b==e){
            cout<<"You are lucky!"<<endl;
        }else{
            cout<<"Wish you good luck."<<endl;
        }
    }
}
// #include<bits/stdc++.h>
// using namespace std;
// bool lucky(int n){
//     int sum1=0,sum2=0;
//     int cnt=0;
//     while(n>0){
//         int d=n%10;
//         n=n/10;
//         cnt++;
//         if(cnt<=3){//后三位
//             sum1+=d;
//         }else{
//             sum2+=d;
//         }
//     }
//       if(sum1==sum2){
//             return true;
//         }else{
//             return false;
//         }
// }
// int main(){
//     int n;
//     cin>>n;
//     while(n--){
//         int n1=0;
//         cin>>n1;
//         bool luck=lucky(n1);
//         if(luck){
//             cout<<"You are lucky!"<<endl;
//         }else{
//             cout<<"Wish you good luck."<<endl;
//         }
//     }
// }