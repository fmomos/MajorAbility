// 7-5 计算天数
// 分数 15
// 作者 沈睿
// 单位 浙江大学
// 本题要求编写程序计算某年某月某日是该年中的第几天。

// 输入格式:
// 输入在一行中按照格式“yyyy/mm/dd”（即“年/月/日”）给出日期。注意：闰年的判别条件是
// 该年年份能被4整除但不能被100整除、或者能被400整除。闰年的2月有29天。

// 输出格式:
// 在一行输出日期是该年中的第几天。

// 输入样例1:
// 2009/03/02
// 输出样例1:
// 61
// 输入样例2:
// 2000/03/02
// 输出样例2:
// 62
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string date;
    cin >> date;
    int year, month, day;
    bool flag = false;
    int result;
    stringstream s(date);//使用了stringstream（字符串流）来解析一个日期字符串，并从中提取年、月、日的信息。
    s >> year;
    s.ignore(1);
    s >> month;
    s.ignore(1);
    s >> day;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        flag = true;
    }
    int day31, day30, month2;// 3:1,2       6:1,2,3,4,5
    day31 = ceil((month - 1) / 2.0);
    day30 = floor((month - 1) / 2.0) - 1;
    if (flag)
    {
        month2 = 29;
    }
    else
    {
        month2 = 28;
    }
    if (month == 1)
    { 
        result = day;
    }
    else if (month == 2)
    {
        result = day31 * 31 + day;
    }
    else
    {
        result = day31 * 31 + day30 * 30 + month2 + day;
    }
    cout<<result;
}
// //stringstream 是 C++ 标准库中的一个类，位于 <sstream> 头文件中。它允许你像操作流（如 cin 和 cout）一样操作字符串。stringstream 可以用来将字符串分解成多个部分，或者将多个数据组合成一个字符串。
// 主要用途
// 字符串解析：将字符串分解成多个部分，例如从日期字符串中提取年、月、日。
// 字符串格式化：将多个数据项组合成一个格式化的字符串。
//     // 创建 stringstream 对象
//     stringstream ss;

//     // 使用 << 操作符将数据添加到 stringstream 中
//     ss << "Name: " << name << ", Age: " << age << ", Height: " << height << " cm";

//     // 获取最终的字符串
//     string result = ss.str();