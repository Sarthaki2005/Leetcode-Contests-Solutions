class MinStack {
public:
long long arr[100005];
int t;
long long min;
    MinStack() {
        t=-1;
        min=INT_MAX;
    }
    
    void push(int value) {
       
        if(value<min){
            long long newVal=2*(long long)value-min;
            arr[++t]=newVal;
            min=value;
        }
        else{
            arr[++t]=value;
        }
    }
    
    void pop() {
        if(t==-1) return;
        if(arr[t]<min){
            min=2*min-arr[t];
            
        }
        t--;
        if(t==-1){
            min=INT_MAX;
        }
    }
    
    int top() {
        if(t==-1) return -1;
        if(arr[t]<min){
           return (int)min;
            
        }
       else  return (int)arr[t];
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->t();
 * int param_4 = obj->getMin();
 */