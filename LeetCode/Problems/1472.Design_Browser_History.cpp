class BrowserHistory {
public:
    struct node{
        string url;
        struct node* prev;
        struct node* next;
        node(string u):url(u),prev(NULL),next(NULL){}
    };
    struct node* current;

    BrowserHistory(string homepage) {
        current = new node(homepage);
    }

    void visit(string url) {
        node* tmp = current->next;
        current->next = new node(url);
        current->next->prev = current;
        current = current->next;
        while(tmp){
            node* t = tmp->next;
            tmp->prev = NULL;
            delete tmp;
            tmp = t;
        }
    }

    string back(int steps) {
        while(current->prev!=NULL&&steps--){
            current = current->prev;
        }
        return current->url;
    }

    string forward(int steps) {
        while(current->next!=NULL&&steps--){
            current = current->next;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

/*[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]*/
/*[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]*/
