class Solution {
public:
    int findNext(vector<int> &height,int pos,bool left){    //寻找下一个更短的
        int cur=height[pos];
        if(left)
            pos++;
        else
            pos--;
        while(cur>height[pos]){
            if(left)
                pos++;
            else
                pos--;
            if(pos<0)
                return -1;
            else if(pos>=height.size())
                return height.size();
        }
        return pos;
    }

    int maxArea(vector<int> &height) {
        int left=0,right=height.size()-1;
        int water=min(height[left],height[right])*(right-left);
        while(left<right){
            if(height[left]<height[right])
                left=findNext(height,left,true);
            else
                right=findNext(height,right,false);
            water=max(water,min(height[left],height[right])*(right-left));
        }
        return water;
    }
};
