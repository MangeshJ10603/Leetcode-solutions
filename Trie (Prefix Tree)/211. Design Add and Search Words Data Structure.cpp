class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool solve(string& word, int index, TrieNode* node) {
        if (!node) return false;
        if (index == word.size()) return node->isEnd;

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && solve(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = ch - 'a';
            return solve(word, index + 1, node->children[idx]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return solve(word, 0, raoot);
    }
};
