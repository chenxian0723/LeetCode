class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n=s.length();
        bool flag[n+1];       //记录前n个字符是否可以break
        flag[0]=true;
        for(int i=0;i<n;i++){
            flag[i+1]=false;
            for(int j=0;j<=i;j++){
                if(flag[j]&&dict.find(s.substr(j,i-j+1))!=dict.end()){      //前n个字符可break，并且n后的子串恰好在字典中
                    flag[i+1]=true;
                    break;
                }
            }
        }
        return flag[n];
    }
};
