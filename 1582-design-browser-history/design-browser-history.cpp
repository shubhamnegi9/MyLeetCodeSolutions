class Node {
    public:
    string url;
    Node* next;
    Node* prev;
    
    Node(string newUrl) {
        url = newUrl;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory {
public:
    Node* currPage;

    BrowserHistory(string homepage) {
        currPage = new Node(homepage);    
    }
    
    void visit(string url) {
        Node* newPage = new Node(url);
        currPage->next = newPage;
        newPage->prev = currPage;
        currPage = newPage;     // OR currPage = currPage->next;
    }
    
    string back(int steps) {
        while(steps) {
            if(currPage->prev != NULL)
                currPage = currPage->prev;
            else
                break;
            steps--;
        }
        return currPage->url;
    }
    
    string forward(int steps) {
        while(steps) {
            if(currPage->next != NULL)
                currPage = currPage->next;
            else
                break;
            steps--;
        }
        return currPage->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */