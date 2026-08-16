class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool row[9][9] = {};
        bool col[9][9] = {};
        bool box[9][9] = {};


        for(int i = 0 ;  i< 9; ++i){
            for(int j = 0 ; j < 9 ; j++){
                
                if(board[i][j] == '.'){
                    continue;
                }

                int curr = board[i][j] - '1';

                int b = (i /3) * 3  + (j /3) ;

                if(row[i][curr] || col[j][curr] || box[b][curr]){
                    return false;
                }

                row[i][curr] = true;
                col[j][curr] = true;
                box[b][curr] = true;
            }
        }

        return true;

    }
};
