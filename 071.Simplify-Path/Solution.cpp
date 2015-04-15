class Solution {
public:
    string simplifyPath(string path) {
        stack<string> spath;
        int pos=0,pos2=0;                     //第一个'/'位置为0
        while(pos<path.length()-1){
            pos2=path.find('/',pos+1);        //找到下一个'/'
            if(pos2==-1)                      //没有下一个'/'了，就把末尾当成最后一个'/'
                pos2=path.length();       
            string temp=path.substr(pos+1,pos2-pos-1);      //获取两'/'之间的子串
            pos=pos2;
            if((temp==".")||(temp==""))       //'.'和''的话，不做操作
                continue;
            else if(temp==".."){              //'..'的话要弹出一级路径，当然要在前面有路径的情况下
                if(spath.empty())
                    continue;
                else
                    spath.pop();
            }
            else
                spath.push(temp);
        }
        string res;
        while(!spath.empty()){                //把剩下的路径倒序输出，中间用'/'连接
            res='/'+spath.top()+res;
            spath.pop();
        }
        if(res=="")
            return "/";
        else
            return res;
    }
};
