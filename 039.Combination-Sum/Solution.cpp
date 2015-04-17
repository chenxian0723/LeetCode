class Solution {
public:
    vector<vector<int>> res;
    
    void combinationSum2(vector<int> &solution, vector<int> &candidates, int target,vector<int>::iterator ii){  
        for(auto i=ii;i!=candidates.end();i++){
            if(*i>target)
                continue;
            else if(*i==target){
                solution.push_back(*i);
                res.push_back(solution);
                solution.pop_back();            //引用为参数时，push后，等需要回溯时一定要有一个pop操作
                return;
            }
            else{
                solution.push_back(*i);
                combinationSum2(solution,candidates,target-(*i),i);     //传入参数i为了避免前面的元素重复计算
                solution.pop_back();            //引用为参数时，push后，等需要回溯时一定要有一个pop操作
            }
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> solution;
        sort(candidates.begin(),candidates.end());      //排序
        combinationSum2(solution,candidates,target,candidates.begin());
        return res;
    }
};
