#include <iostream>
#include "Stack.cpp"

using namespace std;

/*****************************************************
* 函数作用：完成字符串的计算功能
* 输入参数：参数1：传入的字符串S
* 输出参数：无
* 返回值  ：计算器的返回结果
* 完成日期：2019.04.10
******************************************************/
int CalculateString(string S) {

    if (S.empty() || S.length() == 0) {
        return 0;
    }

    Stack stack = Stack();
    int res = 0;
    int sign = 1;
    for (int i = 0; i < S.length(); i++) {
        char c = S[i];
        if (isdigit(c)) {
            int cur = c - '0';//转换为数字
            while (i + 1 < S.length() && isdigit(S[i + 1])) {
                cur = 10 * cur + int(S[++i] - '0');//连续数字
            }
            res += sign * cur;
        } else if (c == '-') {
            sign = -1;
        } else if (c == '+') {
            sign = 1;
        } else if(c== '('){//如果为左括号将其push进去
            stack.Push(res);
            res = 0;
            stack.Push(sign);
            sign = 1;
        } else if(c==')'){//如果右括号将其pop出来并计算
            res = stack.Pop()*res + stack.Pop();
            sign = 1;
        }
    }
    return res;
}

/**
 * 测试样例为"1 + 1"
 * 预计输出为 2
 */
void test1(){
    string s= "1 + 1";
    if(CalculateString(s) != 2){
        printf("test1 failed");
    } else{
        printf("test1 successfully\n\n");
    }
}

/**
 * 测试样例为" 2-1 + 2 "
 * 预计输出为 3
 */

void test2(){
    string s= " 2-1 + 2 ";
    if(CalculateString(s) != 3){
        printf("test2 failed");
    } else{
        printf("test2 successfully\n\n");
    }

}

/**
 * 测试样例为"(1+(4+5+2)-3)+(6+8)"
 * 预计输出为 23
 */
void test3(){
    string s= "(1+(4+5+2)-3)+(6+8)";
    if(CalculateString(s) != 23){
        printf("test3 failed");
    } else{
        printf("test3 successfully\n\n");
    }
}
int main() {

    printf("test example1: 1 + 1 \n");
    printf("test result: %d \n",CalculateString("\"1 + 1\""));
    test1();

    printf("test example2:  2-1 + 2  \n");
    printf("test result: %d \n",CalculateString("\" 2-1 + 2 \""));
    test2();

    printf("test example3: (1+(4+5+2)-3)+(6+8) \n");
    printf("test result: %d \n",CalculateString("(1+(4+5+2)-3)+(6+8)"));
    test3();
}