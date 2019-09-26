class Solution {
public:
    
    bool helpfunc(vector<vector<char>>& board, int *posi, int *posj, int pos, string word){
        // if curr pos == word.size(), return true, we mapped all chars
        if(pos == word.size()) return true; 
        
        int i, j; 
        if(pos > 0){
            // try to map the "pos"-th char, around the pos-1
            // 1. it should be the "pos"-th char
            // 2. make sure it doesn't used before
            // then put into posi/posj, recursive call pos+1
            // if return true, return true
            int lasti, lastj, flag; 
            lasti = posi[pos-1]; 
            lastj = posj[pos-1]; 
            // candidate vector, fill if match condition 1, 2
            vector<int> pendi, pendj; 
            if(lasti > 0){ // go up
                if(board[lasti-1][lastj] == word[pos]){
                    flag = 1; 
                    for(i = 0; i < pos; i++)
                        if((posi[i] == (lasti-1)) && (posj[i] == lastj)){
                            flag = 0; 
                            break; 
                        }
                    if(flag){
                        pendi.push_back(lasti-1); 
                        pendj.push_back(lastj); 
                    }
                }
            }
            if(lasti < (board.size()-1)){ // go down
                if(board[lasti+1][lastj] == word[pos]){
                    flag = 1; 
                    for(i = 0; i < pos; i++)
                        if((posi[i] == (lasti+1)) && (posj[i] == lastj)){
                            flag = 0; 
                            break; 
                        }
                    if(flag){
                        pendi.push_back(lasti+1); 
                        pendj.push_back(lastj); 
                    }
                }
            }
            if(lastj > 0){ // go left
                if(board[lasti][lastj-1] == word[pos]){
                    flag = 1; 
                    for(i = 0; i < pos; i++)
                        if((posi[i] == lasti) && (posj[i] == (lastj-1))){
                            flag = 0; 
                            break; 
                        }
                    if(flag){
                        pendi.push_back(lasti); 
                        pendj.push_back(lastj-1); 
                    }
                }
            }
            if(lastj < (board[0].size()-1)){ // go right
                if(board[lasti][lastj+1] == word[pos]){
                    flag = 1; 
                    for(i = 0; i < pos; i++)
                        if((posi[i] == lasti) && (posj[i] == (lastj+1))){
                            flag = 0; 
                            break; 
                        }
                    if(flag){
                        pendi.push_back(lasti); 
                        pendj.push_back(lastj+1); 
                    }
                }
            }
            
            for(i = 0; i < pendi.size(); i++){
                posi[pos] = pendi[i]; 
                posj[pos] = pendj[i]; 
                if(helpfunc(board, posi, posj, pos+1, word)) return true; 
            }
        }
        else{
            // try to search the first char, put into posi/posj freely
            // recursive call pos+1
            // if ret true, ret true
            vector<int> pendi, pendj; 
            for(i = 0; i < board.size(); i++){
                for(j = 0; j < board[0].size(); j++){
                    if(board[i][j] == word[0]){
                        pendi.push_back(i); 
                        pendj.push_back(j); 
                    }
                }
            }
            for(i = 0; i < pendi.size(); i++){
                posi[0] = pendi[i]; 
                posj[0] = pendj[i]; 
                if(helpfunc(board, posi, posj, pos+1, word)) return true; 
            }
        }
        return false; 
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // a tree construction helper func
        
        int i, j; 
        /*
        vector<vector<int>> metflag; 
        for(i = 0; i < board.size(); i++){
            vector<int> temp; 
            for(j = 0; j < board[0].size(); j++){
                temp.push_back(0); 
            }
            metflag.push_back(temp); 
        }
        */
        
        int *posi = new int[word.size()]; 
        int *posj = new int[word.size()]; 
        for(i = 0; i < word.size(); i++){
            posi[i] = -1; posj[i] = -1; 
        }
        
        bool res = helpfunc(board, posi, posj, 0, word);
        
        delete[] posi, posj; 
        return res; 
    }
};
