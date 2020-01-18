#include <string>
#include <limits.h>
class Solution {
public:
    struct trieNode{
      int count;
        trieNode* child[26];
        bool is_End;
        int heap_index;
    };
    struct heapNode{
        int frequency = 0;
        //char* word;
        string word;
        struct trieNode* tnode = NULL;
        struct trieNode* endRef = NULL;
    };
    struct trieNode* getTrieNode(){
        struct trieNode* tmp = new trieNode;
        tmp->is_End = false;
        tmp->heap_index = -1;
        tmp->count = 0;
        for(int i=0;i<26;i++){
            tmp->child[i] = NULL;
        }
        return tmp;
    }
    bool isEmpty(int *psize,int k){
        if(*psize>=k){
            return false;
        }
        return true;
    }
    void copyNode(struct heapNode *a,struct heapNode *b){
        a->frequency = b->frequency;
        a->word = b->word;
        a->tnode = b->tnode;
        a->endRef = b->endRef;
        return;
    }
    int restoreup(struct heapNode heap[],int size){
        struct heapNode k;
        copyNode(&k,&heap[size]);
        int i = size;
        int par = i/2;
        while(k.frequency<heap[par].frequency){
            copyNode(&heap[i],&heap[par]);
            i = par;
            par = i/2;
        }
        copyNode(&heap[i],&k);
        return i;
    }
    int insertHeap(struct heapNode heap[],int frequency,int *psize,string word){
        *psize = *psize+1;
        heap[*psize].frequency = frequency;
        heap[*psize].word = word;
        int index = restoreup(heap,*psize);
        return index;
    }
    void restoredown(struct heapNode heap[],int size){
        struct heapNode k;
        int i = 1;
        copyNode(&k,&heap[i]);
        int left = 2*i;
        int right = 2*i+1;
        while(right<=size){
            if(k.frequency<=heap[left].frequency&&k.frequency<=heap[right].frequency){
                copyNode(&heap[i],&k);
                return;
            }else if(heap[left].frequency<heap[right].frequency){
                copyNode(&heap[i],&heap[left]);
                i = left;
            }else{
                copyNode(&heap[i],&heap[right]);
                i = right;
            }
            left = 2*i;
            right = 2*i+1;
        }
        if(left==size&&heap[left].frequency<k.frequency){
            copyNode(&heap[i],&heap[left]);
            i = left;
        }
        copyNode(&heap[i],&k);
        return;
    }
    struct heapNode deleteHeap(struct heapNode heap[],int *psize){
        struct heapNode result;
        copyNode(&result,&heap[1]);
        copyNode(&heap[1],&heap[*psize]);
        *psize = *psize-1;
        restoredown(heap,*psize);
        return result;
    }
    void insertTrie(string word,struct trieNode* root,struct trieNode **tStart,struct trieNode **tEnd){
        struct trieNode* pcrawl = root;
        for(int i=0;i<word.length();i++){
            int index = (int)word[i]-97;
            if(pcrawl->child[index]==NULL){
                pcrawl->child[index] = getTrieNode();
            }
            if(*tStart==NULL){
                *tStart = pcrawl->child[index];
            }
            pcrawl->child[index]->count+=1;
            pcrawl = pcrawl->child[index];
        }
        pcrawl->is_End = true;
        *tEnd = pcrawl;
        //*heapIndex = pcrawl->heapIndex;
        //*tFrequency = pcrawl->count;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int heapsize = 0;
        struct heapNode heap[k+1];
        heap[heapsize].frequency = INT_MIN;
        heap[heapsize].word = "-1";
        heap[heapsize].tnode = NULL;
        heap[heapsize].endRef = NULL;
        //int heapIndex = -1;
        struct trieNode *tNodeRef = NULL;
        struct trieNode *tNodeEndref = NULL;
        struct trieNode *root = getTrieNode();
        //int tFrequency
        for(int i=0;i<words.size();i++){
            tNodeRef = NULL;
            //heapIndex = -1;
            //tFrequency = 0;
            insertTrie(words[i],root,&tNodeRef,&tNodeEndref);
            if(tNodeEndref->heap_index==-1){
                int frequency = tNodeEndref->count;
                if(heapsize!=0){
                    if(isEmpty(&heapsize,k)){
                        int index = insertHeap(heap,frequency,&heapsize,words[i]);
                        tNodeEndref->heap_index = index;
                        heap[index].tnode = tNodeRef;
                        heap[index].endRef = tNodeEndref;
                    }else{
                        int minFrequency = heap[1].frequency;
                        if(frequency>minFrequency){
                            struct heapNode deleted_node = deleteHeap(heap,&heapsize);
                            deleted_node.endRef->heap_index = -1;
                            int index = insertHeap(heap,frequency,&heapsize,words[i]);
                            heap[index].tnode = tNodeRef;
                            heap[index].endRef = tNodeEndref;
                            tNodeEndref->heap_index = index;
                        }
                    }
                }
            }
        }
        vector<string> result;
        for(int i=0;i<k&&heapsize>0;i++){
            struct heapNode dNode = deleteHeap(heap,&heapsize);
            result.push_back(dNode.word);
        }
        return result;
    }
};
