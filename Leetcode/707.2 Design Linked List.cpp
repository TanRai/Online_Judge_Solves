
class MyLinkedList {
  public:
      ListNode* head = new ListNode(0);
      ListNode* tail = head;
      MyLinkedList() {
          
      }
      
      int get(int index) {
          ListNode* cur = head->next;
          while(index && cur)
          {
              cur = cur->next;
              index--;
          }
          if(index || !cur)
              return -1;
          return cur->val;
      }
      
      void addAtHead(int val) {
          ListNode *temp = new ListNode(val);
          temp->next = head->next;
          head->next = temp;
          if(head==tail)
              tail = tail->next;
      }
      
      void addAtTail(int val) {
          tail->next = new ListNode(val);
          tail = tail->next;
      }
      
      void addAtIndex(int index, int val) {
          ListNode* cur = head;
          while(index && cur)
          {
              cur = cur->next;
              index--;
          }
          if(index || !cur)
              return;
          ListNode* temp = cur->next;
          cur->next = new ListNode(val,temp);
          if(cur==tail)
              tail = tail->next;
      }
      
      void deleteAtIndex(int index) {
          ListNode* cur = head;
          while(index && cur)
          {
              cur = cur->next;
              index--;
          }
         if(index || !cur)
              return;
          if(cur->next == tail)
              tail = cur;
          cur->next = cur->next? cur->next->next:nullptr;
      }
  };
  
  /**
   * Your MyLinkedList object will be instantiated and called as such:
   * MyLinkedList* obj = new MyLinkedList();
   * int param_1 = obj->get(index);
   * obj->addAtHead(val);
   * obj->addAtTail(val);
   * obj->addAtIndex(index,val);
   * obj->deleteAtIndex(index);
   */