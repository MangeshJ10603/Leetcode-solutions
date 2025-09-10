class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(256,0);
        vector<int> visited(256,0);
        string stack;
        for(char ch:s) freq[ch]++;
        for(char ch:s){
            freq[ch]--;
            if(visited[ch]) continue;
            while(!stack.empty() and stack.back()>ch and freq[stack.back()]>0){
                visited[stack.back()]=false;
                stack.pop_back();
            }
            stack.push_back(ch);
            visited[ch]=true;
        }
        return stack;
    }
};
