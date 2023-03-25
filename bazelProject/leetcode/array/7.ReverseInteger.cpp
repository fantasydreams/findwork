#include "7.ReverseInteger.h"


//判断溢出  res < INT_MIN / 10 || res > INT_MAX / 10
int reverse(int x)
{
    //printf("%d\n", x % 10); // 这里求出来的值是否带符号只与被余数的符号有关
    int res = 0;
    while(x)
    {
        int remain = x % 10;
        if(res < INT_MIN / 10 || (res == INT_MIN / 10 && remain > 8) || res > INT_MAX / 10 || 
          (res == INT_MAX / 10 && remain >7 )){
            return 0;
        }
        res = res * 10 + remain;
        x /= 10;
    }

    return res;
}



int reverse1(int x) {
    int ans = 0;
    while(x) {
        int remain = x % 10;
        if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && remain > 8) || ans > INT_MAX / 10 || (ans == INT_MAX / 10 && remain > 7)) {
            return 0;
        }
        x /= 10;
        ans = ans * 10 + remain;
    }
    return ans;
}