#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length();
        int len_b = b.length();

        int a_b = len_a -len_b;
        int min_len=(a_b>0)?len_b:len_a;

        stack<char> stk;
        int flag = false;
        for(int i=1;i<=min_len;++i){
            int sum = (int)(a[len_a-i]-'0')+(int)(b[len_b-i]-'0');
            switch(sum){
                case 0:
                    if(flag){
                        stk.push('1');
                    }else{
                        stk.push('0');
                    }
                    flag=false;
                    break;
                case 1:
                    if(flag){
                        stk.push('0');
                        flag=true;
                    }else{
                        stk.push('1');
                        flag=false;
                    }
                    break;
                case 2:
                    if(flag){
                        stk.push('1');
                    }else{
                        stk.push('0');
                    }
                    flag=true;
                    break;
            }
        } 

        string longer_str =(a_b>0)?a:b;

        for(int i=a_b-1;i>=0;--i){
            if(flag){
                if(longer_str[i]=='0'){
                    stk.push('1');
                    flag=false;
                }else if(longer_str[i]=='1'){
                    stk.push('0');
                    flag=true;
                }
            }else{
                stk.push(longer_str[i]);
            }
        }

        string result="";
        while(!stk.empty()){
            result+=stk.top();
            stk.pop();
        }
        return result;
    }
};


int main(int argc, char** argv){
    Solution s;
    string result = s.addBinary("1101","110001");
    cout<<result<<endl;



    return 0;
}