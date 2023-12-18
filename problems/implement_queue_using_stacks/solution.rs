struct MyQueue {
    primary: Vec<i32>,
    // We don't need this unless we want to minimize stack pop operations
    secondary: Vec<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {

    fn new() -> Self {
        MyQueue {
            primary: vec![],
            secondary: vec![]
        }
    }
    
    fn push(&mut self, x: i32) {
        self.primary.push(x);
    }
    
    fn pop(&mut self) -> i32 {
        if self.secondary.is_empty() {
            while !self.primary.is_empty() {
                self.secondary.push(self.primary.pop().unwrap());
            }
        }
        self.secondary.pop().unwrap()
    }
    
    fn peek(&self) -> i32 {
        if self.secondary.is_empty() {
            *self.primary.first().unwrap()
        }
        else {
            *self.secondary.last().unwrap()
        }
    }
    
    fn empty(&self) -> bool {
        self.primary.is_empty() && self.secondary.is_empty()
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */