class Solution {
private:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool asd(vector<vector<char>>& board,int i,int j, string& word, int index){
        if(index==word.size()){
            return true;
        }
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='$'){
            return false;
        }
        if(board[i][j]!=word[index] )return false;
        char temp = board[i][j];
        board[i][j]='$';
        for(auto &dir:direction){
            int _x = i+dir[0];
            int _y = j+dir[1];
            if(asd(board,_x,_y,word,index+1))return true;
        }
        board[i][j]=temp;

        return false;
    }
public:
    int n,m;
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && asd(board,i,j,word,0))return true;
            }
        }
        return false;
    }
};