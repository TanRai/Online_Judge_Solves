class MedianFinder {
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if((small.empty() && large.empty()) || num<=small.top())
            small.push(num);
        else
            large.push(num);
        
        if(small.size()>large.size()+1)
        {
            large.push(small.top());
            small.pop();
        }
        else if(large.size()>small.size()+1)
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if((small.size()+large.size())%2==1)
            return small.size()>large.size()?small.top():large.top();

        double n1 = small.top();
        double n2 = large.top();
        
        return (n1+n2)/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */