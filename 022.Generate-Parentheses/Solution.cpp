class Solution {
public:
    void generate(int left,int right,string s,vector<string> &res){     //res引用作为返回结果
        if((left==0)&&(right==0)){
            res.push_back(s);
            return;
        }
        if(left==right)         //保证在任意位置，左括号大于右括号
            generate(left-1,right,s+'(',res);
        else{
            if(left>0)          //还能继续往左走
                generate(left-1,right,s+'(',res);
            generate(left,right-1,s+')',res);     //往右走
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n-1,n,"(",res);    //第一个一定为"("
        return res;
    }
};
