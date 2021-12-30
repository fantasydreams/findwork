#include "1015.SmallestIntegerDivisiblebyK.h"

/*
A fraction is either a finite decimal or an infinite loop decimal
3 / 5 = 0.6
2 / 7. = 0.285714 285714 2857...
Furthermore the length of the loop does not exceed the denominator.
because 0 <= remainder < denominator

=>  R2 = n2 % k 
=>  R2 = (n1 * 10 + 1) % k                        ... [ putting in value of n2 ]
=>  R2 = [(n1 % k) * (10 % k)] % k + 1 % k        ... [ modulo property ]
=>  R2 = [R1 * (10 % k)] % k + 1 % k              ... [ ∵ R1 = n1 % k ]
=>  R2 = (R1 * 10 + 1) % k


k = 7 can stop after 6 transfers, so we return 6

1 % 7 = 1
11 % 7 = ( 1 * 10  + 1 ) % 7 = 4
111 % 7 = ( 11 * 10 + 1 ) % 7 = (((7 + 4) * 10 + 1 ) % 7) % 7 = (4 * 10 + 1) % 7 = 6
1111 % 7 = (111 * 10 + 1) % 7 = 
*/

//!! 没想明白

int smallestRepunitDivByK(int k)
{
    if(k % 2 == 0 || k % 5 ==0 ) return -1;

    std::vector<bool> hit(k + 1, 0);
    int remain = 0, res = 0;
    while(true)
    {
        remain = (remain * 10 + 1) % k;
        ++res;
        if(hit[remain]){
            return -1;
        }
        hit[remain] = true;
        if(remain == 0){
            break;
        }
    }

    return res;
}