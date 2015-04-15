class Solution {
public:
    int findMin(vector<int> &num) {
        int size=num.size();
        if(size==1)
            return num[0];
        if(num[0]<num[size-1])      //是不是在最左边
            return num[0];
        if(num[size-1]<num[size-2]) //是不是在最右边
            return num[size-1];
        int low=0;
        int high=size-1;
        while(low<high){        //二分的方法
            int mid=(high+low)/2;
            if((num[mid]<num[mid+1])&&(num[mid]<num[mid-1]))        //比左右两边都小，说明就是最小值      
                return num[mid];
            if(num[mid]>num[0])
                low=mid;
            else
                high=mid;
        }
    }
};
