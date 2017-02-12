#include <queue>

class MedianFinder {
public:
    
    priority_queue<int , vector< int >,  std::greater<int> > min_heap;
    
    priority_queue<int , vector< int > > max_heap;
    

    // Adds a number into the data structure.
    void addNum(int num) {
        if(!max_heap.empty() and max_heap.top()>num){
            max_heap.push(num);
        }else {
            min_heap.push(num);
        }
        if( min_heap.size()>max_heap.size()  ){
            max_heap.push( min_heap.top() );
            min_heap.pop();
        }
        else if( max_heap.size()-min_heap.size()>1  ){
            min_heap.push( max_heap.top() );
            max_heap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(max_heap.size() and max_heap.size()==min_heap.size())return 0.5*(max_heap.top()+min_heap.top());
        else return max_heap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();