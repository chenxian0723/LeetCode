class Solution {
public:
    int singleNumber(int A[], int n) {
        set<int> s1;      //定义2个集合
        set<int> s2;
        for(int i=0;i<n;i++){
            if(s1.find(A[i])==s1.end())       //第一次出现时放入集合1
                s1.insert(A[i]);
            else if(s2.find(A[i])==s2.end())  //第二次出现时放入集合2
                s2.insert(A[i]);              
            else                              //第三次出现时从集合1删除
                s1.erase(A[i]);
        }
        set<int>::iterator si=s1.begin();     //没出现3次的元素还留在集合1
        return *si;
    }
};
