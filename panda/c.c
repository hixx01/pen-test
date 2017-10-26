#include <iostream>  //标准的c++头,任何符合标准的C++开发环境都有这个头文件。
#include <algorithm>//algorithm意为"算法",是C++的标准模版库（STL）中最重要的头文件之一，提供了大量基于迭代器的非成员模版函数。简而言之，
                    //这是一个功能强大的算法库，可以在这里找到大量通用的算法。
#include <vector>
using namespace std;

bool isValid(string s)
{
    if(s.size() > 1 && s[0] == '0')
        return false;
    int res = atoi(s.c_str());  //c_str()执行的意思

    return res <= 255 && res >= 0;
}

void DFS(string s, string tmp, int count, vector<string> &result)
{
    if(count == 3 && isValid(s))
    {
        result.push_back(tmp+s);
        return;
    }

    //可以取1-3个字符
    for(int i = 1; i <= 3 && i < s.size(); ++i) //特别需要注意i<s.size()
    {
        string subs = s.substr(0, i);
        if(isValid(subs))
            DFS(s.substr(i), tmp+subs+".", count+1, result);
    }
}

int main()
{


    string s;
 cin>>s;
    while(cin >> s)//将会一直测试输入流是否正常，如果输入流正常，就会继续循环，如果输入流错误，
                   //或者达到文件末尾（在windows下Ctrl+Z，在Linux下Ctrl+D），循环就会终止。搜索
    {
        vector<string> result;

        if(s.size() < 4 || s.size() > 12)
            return 0;

        DFS(s, "", 0, result);

        for(int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << endl;  //先输出result[i]再换行;
        }

    }


    return 0;
}