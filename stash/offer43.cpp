#include <iostream>
// 数位dp:统计[1,n]中1出现的次数

// 定义： T(M)表示小于等于M的所有数字中1出现的个数
// 不妨设置M = N * 10 + T N就是M的前n-1位，T是最后一位
// 于是有：T(M) = T(N)

/*
 * 设M共有n位
    T(M,x)表示小于等于M的数字中出现x个1的数字的个数
    于是最后结果 = \Sigma  T(M,i) * i
   转移方程
   T(M,x) =  A + B
   最后一位是1 
   最后一位不是1



 */

int countDigitOne(int n) { return 0; }
int main() { return 0; }