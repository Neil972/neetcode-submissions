class MinStack {
 private:
  stack<int> actStack;
  stack<int> minStack;

 public:
  MinStack() {}

  void push(int val) {
    if (minStack.empty()) {
      minStack.push(val);
    } 
    else if (
      val < minStack.top()
    ) {
      minStack.push(val);
    }
    else if(
      val>=minStack.top()
    ){
      minStack.push(
        minStack.top()
      );
    }
    actStack.push(val);
  }

  void pop() {
    int popedVal 
    = actStack.top();
    minStack.pop();
    actStack.pop();
  }

  int top() { 
    return actStack.top();
  }

  int getMin() { 
    return minStack.top(); 
  }
};
