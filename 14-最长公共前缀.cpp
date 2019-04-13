class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int str_count = strs.size();
        if(str_count<=0) throw "invalid parameters";
        int min_str_len=strs[0].length();
        for(int i=1;i<str_count;++i){
            if(strs[i].length()<min_str_len)
                min_str_len=strs[i].length();
        }

        string result="";
        for(int i=0;i<min_str_len;++i){
            for(int j=0;j<str_count-1;++j){
                if(strs[j][i]!=strs[j+1][i])
                    return result;
            }           
            result+=strs[0][i];
        }
        return result;
    }
};