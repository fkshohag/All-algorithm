#include <bits/stdc++.h>
using namespace std;

class TrieNode {
  private:
    bool endMark;
    TrieNode* next[29];
    
  public:
    bool isLetterExist(char letter) {
        int id = letter - 'a';
        return next[id] != NULL;
    }
    
    void insert(char letter, TrieNode* node) {
        int id = letter - 'a';
        if (next[id] == NULL) {
            next[id] = node;
        }
    }
    
    TrieNode* getNode(char letter) {
        int id = letter - 'a';
        return next[id];
    }
    
    void setEndMark(bool flag) {
        endMark = flag;
    }
    
    bool getEndMark() {
        return endMark;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->isLetterExist(word[i])) {
                curr->insert(word[i], new TrieNode());
            }
            curr = curr->getNode(word[i]);
        }
        curr->setEndMark(true);
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->isLetterExist(word[i])) {
                return false;
            }
            curr = curr->getNode(word[i]);
        }
        return curr->getEndMark();
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!curr->isLetterExist(prefix[i])) {
                return false;
            }
            curr = curr->getNode(prefix[i]);
        }
        return true;
    }
};

Trie* obj = new Trie();
string word = "love";
string prefix = "lov";
obj->insert(word);
bool param_2 = obj->search(word);
bool param_3 = obj->startsWith(prefix);