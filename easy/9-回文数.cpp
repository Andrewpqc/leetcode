class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x == 0) return true;
        long long x_bak = x;
        long long reversedResult = 0;
        while(x){
            int lastNumber= x%10;
            reversedResult = reversedResult*10 + lastNumber;
            x = x/10;
        }

        if(reversedResult==x_bak) return true;
        else return false;
        
    }
};