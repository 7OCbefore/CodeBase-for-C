// 编程在算式123 45 67 8 9=N的下划线部分填上加号（+）或减号（-），使该等式成立。要求程序运行时输出该等式。
//（保证数据存在满足的等式）
// 输入要求：输入一个整数N。
// 输出要求：输出满足条件的等式。若不存在满足的等式，则输出"impossible"（输出不包括引号）
// 输入样例：100
// 输出样例：123+45-67+8-9=100

//设计思路:四个二进制位。1-16的二进制中，0000四个位置上1会各出现8次
//4个2进制位，组成0到15这16个数
//每一个二进制位对应一个操作符的位置， 1代表加号 ， 0代表减号
//0000 表示所有的操作符都是减号，1111表示所有操作符都是加号
//1010 表示第一第三操作符是加号，第二第四操作符是减号
//穷举所有的可能就好了
//类似的，你可以把乘除引入进来，那就要把位数扩大一倍， 8位二进制数，一共256种状态了
//不过由于那就要考虑到运算符优先级的问题了，会更复杂一些

#include <stdio.h>

int main() {
    int x, target;
    scanf("%d", &target);
    for (x = 0; x < 16; x++) {
        int v = 123;
        char c1, c2, c3, c4;
        c1 = x & 8 ? '+' : '-';
        if (x & 8) v += 45; else v -= 45;
        c2 = x & 4 ? '+' : '-';
        if (x & 4) v += 67; else v -= 67;
        c3 = x & 2 ? '+' : '-';
        if (x & 2) v += 8; else v -= 8;
        c4 = x & 1 ? '+' : '-';
        if (x & 1) v += 9; else v -= 9;
        if (v == target) {
            printf("123%c45%c67%c8%c9=100\n", c1, c2, c3, c4);
            break;
        }
    }
    return 0;
}