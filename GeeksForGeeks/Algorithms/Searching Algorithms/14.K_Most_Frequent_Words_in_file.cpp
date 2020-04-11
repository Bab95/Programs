#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#define MAX_CHARS 26
struct trieNode{
    struct trieNode *child[MAX_CHARS];
    bool isend;
    int heapIndex;
    int freq;
    trieNode(){
       for(int i=0;i<MAX_CHARS;i++){
           child[i] = NULL;
       } 
       isend = false;
       heapIndex = -1;
       freq = 0;
    }
};
struct heapNode{
    int freq;
    trieNode *link;
    string word;
    heapNode(string w){
        freq = 0;
        link = NULL;
        word = w;
    }
};
int insertTrie(trieNode *root,string word){
    int index = 0;
    trieNode *pcrawl = root;
    for(int i=0;i<word.lenght();++i){
        index = (int)(word[i]-'0');
        if(pcrawl->child[index]==NULL){
            pcrawl->child[index] = new trieNode;
            pcrawl->child[index]->freq = 1;
        }else{
            pcrawl->child[index]->freq += 1;
        }
        pcrawl = pcrawl->child[index];
    }
    pcrawl->isend = true;
    return pcrawl->heapIndex;
}
void restoreUp(vector<heapNode*>& heap,int i,int *updatedIndex){
    int par = i/2;
    heapNode* tmpNode = heap[i];
    while(heap[par]->freq>tmpNode->freq){
        heap[i] = heap[par];
        i = par;
        par = i/2;
    }
    heap[i] = tmpNode;
    *updatedIndex = i;
}
void insertHeap(vector<heapNode*>& heap,int *heapsize,string word,trieNode *root){
    //heapNode node;
    if(insertTrie(root,word)==-1){
        //this is a new word...
        heapNode* node = new heapNode(word);
        heap.push_back(node);
        *heapsize = heap.size();
        int indexInHeap = -1;
        restoreUp(heap,*heapsize-1,&indexInHeap);
        
    }

}
using namespace std;
int main(){
    
}