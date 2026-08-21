class Solution {
private:
    bool legal(vector<vector<char>>& board,vector<int> dir,int row,int col,int color){
        int rrow=row+dir[0];
        int ccol=col+dir[1];
        int r=board.size();
        int c=board[0].size();
        int length=1;
        while(rrow<r && rrow>=0 && ccol>=0 && ccol<c){
            if(board[rrow][ccol]=='.')return false;
            length++;
            if(board[rrow][ccol]==color){
                return length>=3;
            }
            rrow+=dir[0];
            ccol+=dir[1];
        }
        return false;
    }
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<int>> direction = {
            {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}
        };
        board[rMove][cMove]=color;
        for(auto d:direction){
            if(legal(board,d,rMove,cMove,color)){
                return true;
            }
        }
        return false;
    }
};