#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        bool terminal;
        unordered_map<char,Node*> children;

        Node(char d){
            data = d;
            terminal = false;
        }
};

class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node('\0');
    }

    void insert(char *w){
        Node* temp = root;
        for(int i=0; w[i]!='\0'; i++){
            if(temp->children[w[i]]!=NULL){
                temp = temp->children[w[i]];
            }else{
                temp->children[w[i]] = new Node(w[i]);
                temp = temp->children[w[i]];
            }
        }
        // at last node
        temp->terminal = true;
    }

    bool search(char *s){
        Node* temp = root;
        for(int i=0;s[i]!='\0';i++){
            if(temp->children[s[i]]!=NULL){
                temp = temp->children[s[i]];
            }else{
                return false;
            }
        }
        // at last node
        return temp->terminal;
    }
};

int main(){
    Trie t;
    char words[][10] = {"a","hello","not","news","apple"};
    char w[10];
    cin>>w;
    for(int i=0;i<5;i++){
        t.insert(words[i]);
    }
    t.search(w) ? cout<<"Present\n" : cout<<"Absent";
    return 0;
}