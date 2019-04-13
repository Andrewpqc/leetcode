// I             1    -
// V             5 
// X             10   -
// L             50
// C             100  -
// D             500
// M             1000

// IV            4
// IX            9
// XL            40
// XC            90
// CD            400
// CM            900


class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int result =0;
        for(int i=0;i<len;++i){
            switch(s[i]){
                case 'I' :
                    if(i+1!=len){
                        if(s[i+1]=='V') {result +=4;++i;continue;}
                        if(s[i+1]=='X') {result+=9;++i;continue;}
                    }
                    result +=1;
                        break;       
                case 'V' : 
                    result +=5;
                        break;
                case 'X' : 
                if(i+1!=len){
                        if(s[i+1]=='L') {result +=40;++i;continue;}
                        if(s[i+1]=='C') {result+=90;++i;continue;}
                    }result +=10; 
                        break;       
                case 'L' : 
                    result+=50;
                        break;
                case 'C' :  
                if(i+1!=len){
                        if(s[i+1]=='D') {result +=400;++i;continue;}
                        if(s[i+1]=='M') {result+=900;++i;continue;}
                    }  result +=100;
                        break;       
                case 'D' : 
                    result+=500;
                        break;
                case 'M' :  
                    result += 1000;
                        break;       
            }
        }
        return result;
    }

};