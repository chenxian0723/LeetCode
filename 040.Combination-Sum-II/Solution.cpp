class Solution {
public:
    vector<vector<int>> res;
    
    void combinationSum(vector<int> &solution, vector<int> &candidates, int target,vector<int>::iterator ii){  
        for(auto i=ii;i!=candidates.end();i++){
            if(*i>target)
                continue;
            else if(*i==target){
                solution.push_back(*i);
                if(find(res.begin(),res.end(),solution)==res.end())       //保证解的唯一性
                    res.push_back(solution);
                solution.pop_back();            //引用为参数时，push后，等需要回溯时一定要有一个pop操作
                return;
            }
            else{
                solution.push_back(*i);
                combinationSum(solution,candidates,target-(*i),i+1);     //传入参数i为了避免前面的元素重复计算
                solution.pop_back();            //引用为参数时，push后，等需要回溯时一定要有一个pop操作
            }
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<int> solution;
        sort(candidates.begin(),candidates.end());      //排序
        combinationSum(solution,candidates,target,candidates.begin());
        return res;
    }
};
