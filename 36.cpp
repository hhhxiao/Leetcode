#include <iostream>
#include <bitset>
#include "dbg.h"
#include <vector>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
    bitset<9> rows[9];
    bitset<9> cols [9];
    bitset<9> sqs[9];

    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            char c = board[i][j];
            if(c!= '.'){
                int number =  c - '0'-1;
                if(rows[i][number]){
                    return false;
                }else{
                 rows[i][number].flip();
                }

                if(cols[j][number]){
                    return false;
                }else{
                 cols[j][number].flip();
                }

                int sq_idx = (i / 3) * 3 + (j/3) * 3;
                if(sqs[sq_idx][number]){
                    return false;
                }else{
                    sqs[sq_idx][number].flip();
                }

            }
        }
    }

    return true;
}
 int main(int argc, char const *argv[])
 {
   
    return 0;
 }
 