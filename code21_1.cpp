// 7-22 符号配对
// 分数 15
// 作者 DS课程组
// 单位 浙江大学
// 请编写程序检查C语言源程序中下列符号是否配对：/*与*/、(与)、[与]、{与}。

// 输入格式:
// 输入为一个C语言源程序。当读到某一行中只有一个句点.和一个回车的时候，标志着输入结束。程序中需要检查配对的符号不超过100个。

// 输出格式:
// 首先，如果所有符号配对正确，则在第一行中输出YES，否则输出NO。
// 然后在第二行中指出第一个不配对的符号：如果缺少左符号，则输出?-右符号；如果缺少右符号，则输出左符号-?。

// 输入样例1：
// void test()
// {
//     int i, A[10];
//     for (i=0; i<10; i++) { /*/
//         A[i] = i;
// }
// .

// 输出样例1：
// NO
// /*-?

// 输入样例2：
// void test()
// {
//     int i, A[10];
//     for (i=0; i<10; i++) /**/
//         A[i] = i;
// }]
// .

// 输出样例2：
// NO
// ?-]

// 输入样例3：
// void test()
// {
//     int i
//     double A[10];
//     for (i=0; i<10; i++) /**/
//         A[i] = 0.1*i;
// }
// .

// 输出样例3：
// YES

#include<bits/stdc++.h>

using namespace std;

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int main() {
    stack<char> s;
    string line;
    while (getline(cin, line)) {
        if (line == ".") break;
        for (size_t i = 0; i < line.length(); i++) {
            char c = line[i];
            if (c == '/' && i + 1 < line.length() && line[i + 1] == '*') {
                s.push(c);
                s.push(line[++i]); // 必须用++i，i++ (后缀递增)：先使用i的当前值，然后将i的值加1。
                                    //++i (前缀递增)：先将i的值加1，然后使用新的值。
            } else if (c == '*' && i + 1 < line.length() && line[i + 1] == '/') {
                if (!s.empty() && s.top() == '*') {//碰到右符号，栈非空并且栈顶是*
                    s.pop(); // Remove '*'
                    s.pop(); // Remove '/'
                } else if(s.empty()){//多种情况！！！！！！
                    cout << "NO\n"<<"?-*/\n";
                    return 0;
                }else{//非空，就是左边的符号不匹配
                    cout << "NO\n"<<s.top()<<"-?\n";
                    return 0;
                }
                i++; // 跳过 the next '/' character
            } else if (c == '(' || c == '[' || c == '{') {
                s.push(c);//碰到左符号就压入栈
            } else if (c == ')' || c == ']' || c == '}') {//右符号就看栈是否为空再比对
                if (!s.empty() && isMatchingPair(s.top(), c)) {
                    s.pop();
                } else {
                    cout << "NO\n";
                    if(s.empty()){//栈为空
                        cout<<"?-"<<c;
                    }else{//比对不上
                        if(s.top()!='*'){
                            cout<<s.top()<< "-?\n";
                        }else{//如果栈顶是/*
                            cout<<"/*"<<"-?\n";
                        }
                    }
                    return 0;
                }
            }
        }
    }

    // Check remaining symbols in the stack
    if (!s.empty()) {
        char top = s.top();
        s.pop();
        if (top == '*') {
                cout << "NO\n"<<"/*-?\n";
                return 0;
        } else {
            cout << "NO\n" << top << "-?\n";
            return 0;
        }
    }else{
            cout << "YES\n";
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// bool match(char a, char b)
// {
//     return (a == '(' && b == ')')||(a == '[' && b == ']')||
//         (a == '{' && b == '}');
// }
// int main()
// {
//     string s;
//     stack<char> cs;
//     while (getline(cin, s))//处理每一行
//     {
//         if (s == ".")
//         {
//             break;
//         }
//           for (size_t i = 0; i < s.length(); i++)
//         {
//             if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//             {
//                 cs.push(s[i]);
//             }
//             else if (s[i] == '/' &&i+1<s.length()&&s[i + 1] == '*')//防止越界
//             {
//                 cs.push(s[i]);
//                 ++i;
//                 cs.push(s[i]);
//             }
//             else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
//             {
//                 if (!cs.empty())
//                 {
//                     char temp = cs.top();
//                     bool flag = match(temp, s[i]);
//                     if (flag)
//                     {
//                         cs.pop();
//                     }
//                     else
//                     {
//                         if(cs.top()=='*'){
//                         cout << "NO" << endl;
//                         cout <<"/*-?";
//                         return 0;
//                         }else{
//                         cout << "NO" << endl;
//                         cout << cs.top()<<"-?";
//                         return 0;
//                         }
//                     }
//                 }
//                 else
//                 {
//                     cout << "NO" << endl;
//                     cout << "?-" << s[i];
//                     return 0;
//                 }
//             }
//             else if (s[i] == '*'&&i+1<s.length()&& s[i + 1] == '/')
//             {
//                 if(!cs.empty()&&cs.top()=='*'){
//                     cs.pop();
//                     cs.pop();
//                     ++i;
//                 }else if(!cs.empty()){
//                     cout << "NO" << endl;
//                     cout << cs.top()<<"-?";
//                     return 0;
//                 }else{
//                     cout << "NO" << endl;
//                     cout << "?-*/";
//                     return 0;
//                 }
//             }
//         }
//     }
          
//     if (!cs.empty())
//     {
//         char temp = cs.top();
//         if (temp != '*')
//         {
//             cout << "NO" << endl;
//             cout << temp << "-?";
//             return 0;
//         }
//         else
//         {
//             cout << "NO" << endl;
//             cout << "/*-?";
//             return 0;
//         }
//     }else{
//             cout << "YES";//正确是YES
//     }
//     return 0;

// }