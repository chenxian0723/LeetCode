class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if((s[i]=='(')||(s[i]=='[')||(s[i]=='{'))
                st.push(s[i]);
            else{
                if((!st.empty())&&(s[i]-st.top()<3))    //()[]{}之间相差1或者2
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())    //栈为空才能说明完全匹配
            return true;
        else
            return false;
    }
};
