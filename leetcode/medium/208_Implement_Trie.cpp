#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#define ALPHABET 26
using namespace std;

class Node {
public:
    Node* next_words[ALPHABET] = {NULL};
    bool isEnd;
    Node(): isEnd(0){}
};

class Trie {
public:
    /** Initialize your data structure here. */
    
    Node *root;
    
    Trie() {
        root = (Node*)malloc(sizeof(Node));
        memset(root->next_words, NULL, sizeof(root->next_words));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        //prefix 가 이미 있는 경우,
        Node* tmp = root;
        for(int i = 0; i < word.length(); i++){
            if(tmp->next_words[word[i]-'a'] != NULL){
                tmp = tmp->next_words[word[i]-'a'];
            }
            else{
                tmp->next_words[word[i]-'a'] = new Node;
                tmp = tmp->next_words[word[i]-'a'];
            }
        }
        tmp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* tmp = root;
        int word_len = int(word.length());
        for(int i = 0; i < word_len; i++){
            if(tmp->next_words[word[i]-'a'] == NULL){
                return false;
            }
            tmp = tmp->next_words[word[i]-'a'];
        }
        if(tmp->isEnd) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* tmp = root;
        int prefix_len = int(prefix.length());
        for(int i = 0; i < prefix_len; i++){
            if(tmp->next_words[prefix[i]-'a'] == NULL){
                return false;
            }
            tmp = tmp->next_words[prefix[i]-'a'];
        }
        return true;
    }
};

int main (){
    Trie t;
    t.insert("abc");
    cout<<t.search("bc")<<endl;;
    cout<<t.startsWith("ab")<<endl;;
    return 0;
}