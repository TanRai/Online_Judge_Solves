struct Node{
  string url;
  Node *next;
  Node *prev;
  Node(): url(""),next(nullptr),prev(nullptr) {}
  Node(string url): url(url),next(nullptr),prev(nullptr) {}
};


class BrowserHistory {
  Node *head = new Node();
  Node *cur = head;
public:
  BrowserHistory(string homepage) {
      head->url = homepage;
  }
  
  void visit(string url) {
      Node* temp = new Node(url);
      cur->next = temp;
      temp->prev = cur;
      cur = cur->next;
  }
  
  string back(int steps) {
      while(steps)
      {
          steps--;
          if(cur==head)
              break;
          cur=cur->prev;
      }
      return cur->url;
  }
  
  string forward(int steps) {
      while(steps)
      {
          steps--;
          if(cur->next==nullptr)
              break;
          cur=cur->next;
      }
      return cur->url;
  }
};

/**
* Your BrowserHistory object will be instantiated and called as such:
* BrowserHistory* obj = new BrowserHistory(homepage);
* obj->visit(url);
* string param_2 = obj->back(steps);
* string param_3 = obj->forward(steps);
*/