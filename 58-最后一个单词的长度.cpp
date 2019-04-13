#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        if(len==0) return 0;
        while(s[len-1]==' ') --len;
        int lastWordLngth =0;
        for(int i=len-1;i>=0;--i){
            if(s[i]==' ') return lastWordLngth;
            ++lastWordLngth;
        }

        return lastWordLngth;
    }
};


int main(int argc, char** argv){

    Solution s;
    cout<<s.lengthOfLastWord("hello world   ")<<endl;

    return 0;
}