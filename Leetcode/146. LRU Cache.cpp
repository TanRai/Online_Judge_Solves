struct Node{
  int key;
  int val;
  Node* next;
  Node* prev;
  Node(int key) : key(key),val(0),next(nullptr),prev(nullptr) {}
  Node(int key,int val) : key(key),val(val),next(nullptr),prev(nullptr) {}
};


class LRUCache {
  unordered_map<int,Node*> hashMap;
  Node* left = new Node(0);
  Node* right = new Node(0);
  int capacity;
  int size =0;
public:
  LRUCache(int capacity) {
      this->capacity = capacity;
      left->next = right;
      right->prev = left;
  }
  
  int get(int key) {
      if(hashMap.count(key))
      {
          Node* node = hashMap[key];
          //Disconnect node from current position
          node->prev->next = node->next;
          node->next->prev = node->prev;
          //Insert Node to just before right
          node->next = right;
          node->prev = right->prev;
          right->prev->next = node;
          right->prev = node;
          return node->val;
      }
      return -1;
  }
  
  void put(int key, int value) {
      if(hashMap.count(key))
      {
          Node* node = hashMap[key];
          node->val = value;
          //Disconnect node from current position
          node->prev->next = node->next;
          node->next->prev = node->prev;
          //Insert Node to just before right
          node->next = right;
          node->prev = right->prev;
          right->prev->next = node;
          right->prev = node;
          return;
      }
      if(size >= capacity && size)
      {
          Node* node = left->next;
          node->prev->next = node->next;
          node->next->prev = node->prev;
          hashMap.erase(node->key);
      }
      else
          size++;
      Node* node = new Node(key,value);
      node->next = right;
      node->prev = right->prev;
      right->prev->next = node;
      right->prev = node;
      hashMap[key] = node;
  }
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/