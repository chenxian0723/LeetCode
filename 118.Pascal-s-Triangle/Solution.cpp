class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        vector<int> newline={1};  //其中的一行
        if(numRows<=0)
            return pt;
        pt.push_back(newline);
        for(int i=1;i<numRows;i++){
            pt.push_back(newline);
            for(int j=1;j<i;j++){
                pt[i].push_back(pt[i-1][j-1]+pt[i-1][j]);   //也可以先添加在newline里面，然后push_back到pt
            }
            pt[i].push_back(1);
        }
        return pt;
    }
};
