class Solution {
public:
    bool contain(string haystack,string needle, int index,int needle_len, int haystack_len){
        for(int i=0;i<needle_len;++i){
            if(i+index>=haystack_len || haystack[i+index]!=needle[i]) return false;
        }

        return true;
    }
    int strStr(string haystack, string needle) {
        int haystack_len = haystack.length();
        int needle_len = needle.length();
        if(haystack_len<needle_len) return -1;
        if(needle_len==0) return 0;
        for(int i=0;i<haystack_len;++i){
            if(haystack[i]==needle[0]){
                if(contain(haystack, needle, i,needle_len, haystack_len)){
                    return i;
                }
            }
        }
        return -1;
    }
};