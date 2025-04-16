class MyQueue {
    stack<int> s ;   
    stack<int> t ;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x) ;
    }
    
    int pop() {
        
        while(!s.empty()){
            int val = s.top() ;
            s.pop() ;
            t.push(val) ;
        }

        int ans = t.top() ;
        t.pop() ;

        while(!t.empty()){
            int val = t.top() ;
            t.pop() ;
            s.push(val) ;
        }

        return ans; 
    }
    
    int peek() {

        while(!s.empty()){
            int val = s.top() ;
            s.pop() ;
            t.push(val) ;
        }

        int ans = t.top() ;

        while(!t.empty()){
            int val = t.top() ;
            t.pop() ;
            s.push(val) ;
        }

        return ans ;

    }
    
    bool empty() {
        return s.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */