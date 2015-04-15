class Solution {
public:
    int hasPeakElement(const vector<int> &num,int begin,int end){
        if(begin>=end)
            return -1;
        int mid=(begin+end)/2;
        if(num[mid]>num[mid+1]){
            if(num[mid]>num[mid-1])
                return mid;
        }
        else{
            if(num[mid+1]>num[mid+2])
                return mid+1;
        }
        int pos=hasPeakElement(num,begin,mid);      //递归查找左边
        if(pos>=0)
            return pos;
        else
            return hasPeakElement(num,mid+1,end);   //递归查找右边
    }
    
    int findPeakElement(const vector<int> &num) {
        int size=num.size();
        if(size==1)
            return 0;
        if(size==2)
            return num[0]>num[1]?0:1;
        if(num[0]>num[1])
            return 0;
        if(num[size-1]>num[size-2])
            return size-1;
        return hasPeakElement(num,0,size-1);
    }
};
