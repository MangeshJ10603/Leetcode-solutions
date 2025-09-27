class TrieNode{
public:
    string word;
    TrieNode* children[26];
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        word="";
    }
};
class Solution {
private:
    TrieNode* root;
    void insert(string& word){
        TrieNode* node=root;
        for(char ch:word){
            int idx=ch-'a';
            if(!node->children[idx]){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
        }
        node->word=word;
    }

    void dfs(int i, int j,vector<vector<char>>& board, TrieNode* node, vector<string>& result ){
        char ch=board[i][j];
        if(ch=='#'|| !node->children[ch-'a']) return;
        node=node->children[ch-'a'];
        if(!node->word.empty()){
            result.push_back(node->word);
            node->word="";
        }
        board[i][j]='#';
        if(i>0) dfs(i-1,j,board,node,result);
        if(j>0) dfs(i,j-1,board,node,result);
        if(i+1<board.size()) dfs(i+1,j,board,node,result);
        if(j+1<board[0].size()) dfs(i,j+1,board,node,result);
        board[i][j]=ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new TrieNode();
        for(string word:words){
            insert(word);
        }
        vector<string> result;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(i,j,board,root,result);
            }
        }
        return result;
    }
};
