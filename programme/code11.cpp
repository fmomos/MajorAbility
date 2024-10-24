// 7-11 念数字
// 分数 15
// 作者 翁恺
// 单位 浙江大学
// 输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出fu字。十个数字对应的拼音如下：

// 0: ling
// 1: yi
// 2: er
// 3: san
// 4: si
// 5: wu
// 6: liu
// 7: qi
// 8: ba
// 9: jiu
// 输入格式：
// 输入在一行中给出一个整数，如：1234。

// 提示：整数包括负数、零和正数。

// 输出格式：
// 在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如
// yi er san si。

// 输入样例：
// -600
// 输出样例：
// fu liu ling ling
#include <bits/stdc++.h>
using namespace std;
int main(){
    string num;
    cin>>num;
    int cnt=0;
    for(char c:num){//获取每一个数字
        if(c=='-'){
            cout<<"fu";
        }else if(c=='0'){
            cout<<"ling";
        }else if(c=='1'){
            cout<<"yi";
        }else if(c=='2'){
            cout<<"er";
        }else if(c=='3'){
            cout<<"san";
        }else if(c=='4'){
            cout<<"si";
        }else if(c=='5'){
            cout<<"wu";
        }else if(c=='6'){
            cout<<"liu";
        }else if(c=='7'){
            cout<<"qi";
        }else if(c=='8'){
            cout<<"ba";
        }else if(c=='9'){
            cout<<"jiu";
        }
        cnt++;
        if(cnt!=num.size()){
            cout<<" ";//行末没有最后的空格。用cnt计数。
        }
    }
}
//一开始获取每个数字的代码，更复杂
// #include<bits/stdc++.h>
// using namespace std;
// vector<int> getnum(int n){//获取每一位
//     vector<int> getnumber;
//     while(n>0){
//     getnumber.push_back(n%10);
//     n=n/10;
//     }
//     return getnumber;
// }
// void out(int i){
//         if(i==0){
//             cout<<"ling";
//         }else if(i==1){
//             cout<<"yi";
//         }else if(i==2){
//             cout<<"er";
//         }else if(i==3){
//             cout<<"san";
//         }else if(i==4){
//             cout<<"si";
//         }else if(i==5){
//             cout<<"wu";
//         }else if(i==6){
//             cout<<"liu";
//         }else if(i==7){
//             cout<<"qi";
//         }else if(i==8){
//             cout<<"ba";
//         }else if(i==9){
//             cout<<"jiu";
//         }
// }//判断
// int main(){
//     int n;
//     cin>>n;
//     if (n == 0) {
//         cout << "ling";}//处理n等于零的情况
//     else if(n>0){
//     vector<int>num=getnum(n);
//     reverse(num.begin(),num.end());//翻转数组
//     int count=0;
//     for(int i:num){
//         count ++;
//         out(i);
//         if(count!=num.size()){
//             cout<<" ";
//         }
//     };
//     }else{
//     n=abs(n);
//     vector<int>num=getnum(n);
//     reverse(num.begin(),num.end());//反转
//     cout<<"fu"<<" ";
//     int count=0;
//     for(int i:num){
//         count ++;
//         out(i);
//         if(count!=num.size()){//行末没空格
//             cout<<" ";
//         }
//     };
//     }
// }