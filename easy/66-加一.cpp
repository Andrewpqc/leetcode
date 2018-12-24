#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int seq_count_9 = 0;
        int len = digits.size();
        int high = len -1;
        vector<int> result;
        while(high>=0 && digits[high]==9) {
            ++seq_count_9; 
            --high;
        }

        if(seq_count_9==len){
            result.push_back(1);
            for(int i=0;i<len;++i){
                result.push_back(0);
            }
            return result;
        }else{
            ++digits[len-seq_count_9-1];
            for(int i=len-seq_count_9;i<len;++i){
                digits[i]=0;
            }
            return digits;
        }
    }
};


int main(int argc, char** argv){
    Solution s;

    vector<int> v1 {1,2,3};
    vector<int> v2 {1,2,9};
    vector<int> v3 {9,9,9};
    
    vector<int> va = s.plusOne(v1);
    for(auto item:va){
        cout<<item<<" ";
    }
    cout<<endl;

    vector<int> vb = s.plusOne(v2);
    for(auto item:vb){
        cout<<item<<" ";
    }
    cout<<endl;

    vector<int> vc = s.plusOne(v3);
    for(auto item:vc){
        cout<<item<<" ";
    }
    cout<<endl;


    return 0;
}