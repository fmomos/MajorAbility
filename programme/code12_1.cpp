// 7-12 检查密码
// 分数 15
// 作者 陈越
// 单位 浙江大学
// 本题要求你帮助某网站的用户注册模块写一个密码合法性检查的小功能。
// 该网站要求用户设置的密码必须由不少于6个字符组成，并且只能有英文字母、数字和小数点 .，还必须既有字母也有数字。

// 输入格式：
// 输入第一行给出一个正整数 N（≤ 100），随后 N 行，
// 每行给出一个用户设置的密码，为不超过 80 个字符的非空字符串，以回车结束。

// 注意： 题目保证不存在只有小数点的输入。

// 输出格式：
// 对每个用户的密码，在一行中输出系统反馈信息，分以下5种：

// 如果密码合法，输出Your password is wan mei.；
// 如果密码太短，不论合法与否，都输出Your password is tai duan le.；
// 如果密码长度合法，但存在不合法字符，则输出Your password is tai luan le.；
// 如果密码长度合法，但只有字母没有数字，则输出Your password needs shu zi.；
// 如果密码长度合法，但只有数字没有字母，则输出Your password needs zi mu.。
// 输入样例：
// 5
// 123s
// zheshi.wodepw
// 1234.5678
// WanMei23333
// pass*word.6

// 输出样例：
// Your password is tai duan le.
// Your password needs shu zi.
// Your password needs zi mu.
// Your password is wan mei.
// Your password is tai luan le.
//测试点2考察的是一行输入中含有空格的情况，遇到这种情况cin是不行的，需要使用getline和getchar!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;
void judge(string s){
    bool digitok=false;
    bool alphaok=false;
    if(s.size()<6){
        cout<<"Your password is tai duan le.";
        return;
    }
    for(char c:s){
        if(!isalpha(c)&&!isdigit(c)&&(c!='.')){
            cout<<"Your password is tai luan le.";
            return;
        }
        if(isdigit(c)){
            digitok=true;
        }
        if(isalpha(c)){
           alphaok=true;
        }
    }
     if(alphaok&&!digitok){
            cout<<"Your password needs shu zi.";
            return;
        } 
    if(digitok&&!alphaok){
            cout<<"Your password needs zi mu.";
            return;
        }
    cout<<"Your password is wan mei.";
        return;
}
int main()
{
    int n;
    string pwd;
    cin>>n;
    getchar();
    while (n--)
    {
        getline(cin,pwd);
        judge(pwd);
        cout<<endl;
    }
}
// #include<bits/stdc++.h>
// using namespace std;
// void out( string& pwd){
//     bool isdigit1 =false;
//     bool isalpha1 =false;
//     bool isnotlegal=false;
//     if(pwd.length()<6){//获取字符串长度
//         cout<<"Your password is tai duan le."<<endl;
//         return;
//     }else{
//         for(char c:pwd){
//          if((!isdigit(c))&&(!isalpha(c))&&(c!='.')){//单个字符用''
//         isnotlegal=true;
//              break;
//          }if(isdigit(c)){
//              isdigit1=true;
//              }else if(isalpha(c)){
//                 isalpha1=true;
//              }
//                  }}
//   if (isnotlegal) {
//         cout << "Your password is tai luan le." << endl;
//     } else if (!isdigit1) {
//         cout << "Your password needs shu zi." << endl;
//     } else if (!isalpha1) {
//         cout << "Your password needs zi mu." << endl;
//     } else {
//         cout << "Your password is wan mei." << endl;
//     }
//         }
// int main(){
//     int n;
//     cin>>n;
//     getchar();//使用getchar()接收上行末尾的回车
//     while(n--){
//         string s;
//         getline(cin,s);//测试点2考察的是一行输入中含有空格的情况，遇到这种情况cin是不行的，需要使用getline和getchar!!!!!!!!!!!!!
//         out(s);
//     }
// }