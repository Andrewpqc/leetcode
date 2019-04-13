#include <iostream>
using namespace std;

    class Solution {
    public:
        string getNextResult(string str){
            char current_num=str[0];
            int current_num_count = 1;
            string result ="";
            int len = str.length();
            if(len ==1){
                return "11";
            }
            int i=1;
            while(i<len+1){
                if(i==len){
                    result += (char)(current_num_count+'0');
                    result += current_num;   
                    return result;
                }
                if(str[i]==current_num){
                    ++current_num_count;
                }else{
                    result += (char)(current_num_count+'0');
                    result += current_num;
                    current_num=str[i];
                    current_num_count=1;
                }
                ++i;
            }

            return result;
        }
        string countAndSay(int n) {
            string result="1";
            for(int i=0;i<n-1;++i){
                result =getNextResult(result);
            }
            return result;
        }
    };


int main(int argc, char** argv){
    Solution s;
    string str = s.countAndSay(4);
    cout<<str<<endl;



    return 0;
}