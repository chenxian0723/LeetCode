class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> digits;      //后缀表达式，用栈储存元素
        int a,b;
        for(int i=0;i<tokens.size();i++){
            string temp=tokens[i];
            if((temp=="+")||(temp=="-")||(temp=="*")||(temp=="/")){     //二元操作符弹出2个数，计算后压入结果
                a=digits.top();
                digits.pop();
                b=digits.top();
                digits.pop();
                if(temp=="+")
                    digits.push(a+b);
                else if(temp=="-")
                    digits.push(b-a);
                else if(temp=="*")
                    digits.push(a*b);
                else
                    digits.push(b/a);
            }
            else    
                digits.push(atoi(tokens[i].c_str()));       //调用atoi方法，注意将string转换为c_str()
        }
        return digits.top();
    }
};
