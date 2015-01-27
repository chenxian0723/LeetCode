class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        set<char> s;
        
        for(int i=0;i<9;i++){   //按行判断
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(s.find(board[i][j])!=s.end())
                        return false;
                    else
                        s.insert(board[i][j]);
                }
            }
            s.clear();
        }
        
        for(int i=0;i<9;i++){   //按列判断
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(s.find(board[j][i])!=s.end())
                        return false;
                    else
                        s.insert(board[j][i]);
                }
            }
            s.clear();
        }
        
        int m=0,n=0;
        while(n<3){     //按九宫格判断
            for(int i=0+3*m;i<3+3*m;i++){
                for(int j=0+3*n;j<3+3*n;j++){
                    if(board[i][j]!='.'){
                        if(s.find(board[i][j])!=s.end())
                            return false;
                        else
                            s.insert(board[i][j]);
                    }
                }
            }
            s.clear();
            if(m<2)
                m++;
            else{
                n++;
                m=0;
            }
        }
        
        return true;
    }
};
