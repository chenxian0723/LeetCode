class Solution {
public:
    string longestCommonPrefix2(string s1,string s2){
        int length=min(s1.length(),s2.length());
        int i;
        for(i=0;i<length;i++)
            if(s1[i]!=s2[i])
                break;
        if(i==0)
            return "";
        else
            return s1.substr(0,i);
    }

    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0)
            return "";
        if(strs.size()==1)
            return strs[0];
        for(int i=1;i<strs.size();i++)
            strs[0]=longestCommonPrefix2(strs[0],strs[i]);    //逐个求最长前缀
        return strs[0];
    }
};
