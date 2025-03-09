class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int length=1;
        int count=0;
        int lastcol=colors[0];
        for(int i=1;i<n;i++){
            if(colors[i]==lastcol){
                length=1;
                lastcol=colors[i];
                continue;
            }
            length++;
            if(length>=k){
                count++;
            }
            lastcol=colors[i];
        }
        for(int i=0;i<k-1;i++){
            if(colors[i]==lastcol){
                length=1;
                lastcol=colors[i];
                continue;
            }
            length++;
            if(length>=k){
                count++;
            }
            lastcol=colors[i];
        }

        return count;
    }
};

// -----------------------------------------------------------------------------

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int N = n + (k - 1);
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        int i = 0;
        int j = 1;
        int count = 0;
        while (j < N) {
            if (colors[j] == colors[j - 1]) {
                i = j;
                j++;
                continue;
            }
            if (j - i + 1 == k) {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};
