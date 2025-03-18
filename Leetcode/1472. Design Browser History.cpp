struct Node{
  string url;
  Node *next;
  Node *prev;
  Node(): url(""),next(nullptr),prev(nullptr){}
  Node(string url):url(url),next(nullptr),prev(nullptr){}
  Node(string url,Node *next,Node *prev):url(url),next(next),prev(prev){}
};

class BrowserHistory {
  Node* head;
  Node* tail;
  Node* current;
public:
  BrowserHistory(string homepage) {
      head = current = tail = new Node(homepage);
  }

  void visit(string url) {
      Node *temp = new Node(url);
      temp->prev = current;
      current->next = temp;
      tail = temp;
      current = current->next;
  }
  
  string back(int steps) {
      while(steps-- && current!=head)
      {
          current = current->prev;
      }
      return current->url;
  }
  
  string forward(int steps) {
      while(steps-- && current != tail)
      {
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