class Solution {
public:
    int singleNumber(int A[], int n) {
        set<int> s;       //集合
        for(int i=0;i<n;i++){
            if(s.find(A[i])==s.end())
                s.insert(A[i]);       //第一次出现时加入集合
            else
                s.erase(A[i]);        //第二次出现时从集合删除
        }
        set<int>::iterator si=s.begin();      //集合只剩下一个值
        return *si;
    }
};
