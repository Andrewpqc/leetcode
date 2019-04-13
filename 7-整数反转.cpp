#include<iostream>
using namespace std;

//要AC就必须在溢出的时候返回0
//此题太搞人，要考虑溢出
class Solution {
public:
    long long reverse(int x) {
        if (x ==0) return 0;
        long long needReverse= (x<0)?-x:x;
        long long result =0;
        while(needReverse){
            int lowBitNumbe =needReverse%10;
            result = result*10 + lowBitNumbe;
             if (result > INT_MAX/10 || (result == INT_MAX / 10 && lowBitNumbe > 7)) return 0;
            if (result < INT_MIN/10 || (result == INT_MIN / 10 && lowBitNumbe < -8)) return 0;
            needReverse = needReverse/10;
        }
        
        if(x<0) result = -result;
        
        if(result >(2<<31 -1) || result < (- 2<<31)) return 0;
        return result;
    }
};


int main(){
    Solution s;
    cout<<s.reverse(1534236469)<<endl;
    return 0;
}