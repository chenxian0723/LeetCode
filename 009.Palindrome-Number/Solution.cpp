class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int rev=0;
        int xx=x;
        while(x!=0){
            rev=rev*10+x%10;
            x=x/10;
        }
        return rev==xx;
    }
};
