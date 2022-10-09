/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/word-search-ii/
 * Time Complexity: O(mn)
 * Space Complexity:O((word_length)^2)
 */


class TrieNode {
    private:
        bool endMark;
        int id;
        TrieNode* next[26];
    
    public:
        bool isContain(char ch) {
            int key = ch - 'a';
            return next[key] != NULL;
        }

        void insert(char ch, TrieNode* node) {
            int key = ch - 'a';
            if (next[key] == NULL) {
                next[key] = node;
            }
        }
      
        TrieNode* getNode(char ch) {
            int key = ch - 'a';
            return next[key];
        }

        int getId() {
            return id;
        }
    
        void setId(int index) {
            id = index;
        }
    
        int getEndMark(char ch) {
            return endMark;
        }
    
        void setEndMark(bool flag) {
            endMark = flag;
        }
};

class Solution {
private:
    TrieNode* root = new TrieNode();
    int row, col;
    vector<string>ans;
    
    void addNode(string word, int index) {
        TrieNode* curr = root; 
        for (int i = 0; i < word.size(); i++) {
            if (!curr->isContain(word[i])) {
                curr->insert(word[i], new TrieNode());
            }
            curr = curr->getNode(word[i]);
        }
        curr->setEndMark(true);
        curr->setId(index);
    }
    
    void find(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& words) {
        if (i < 0 || j < 0 || i >= row || j >= col) return;
        if (board[i][j] == '0') return;
        
        char ch = board[i][j];
        board[i][j] = '0';
        node = node->getNode(ch); 
        
        if (node == NULL) {
            board[i][j] = ch;
            return;
        }
        if (node->getEndMark(ch)) {
            ans.push_back(words[node->getId()]);
            node->setEndMark(false);
        }
        
        find(board, i+1, j, node, words);
        find(board, i-1, j, node, words);
        find(board, i, j+1, node, words);
        find(board, i, j-1, node, words);
        
        board[i][j] = ch;
    } 
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.size() < 1) return {};
        
        for (int i = 0; i < words.size(); i++) {
            addNode(words[i], i);
        }
        row = board.size();
        col = board[0].size();
        TrieNode *curr = root;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
               find(board, i, j, curr, words);
            }
        }
        return ans;
    }
};