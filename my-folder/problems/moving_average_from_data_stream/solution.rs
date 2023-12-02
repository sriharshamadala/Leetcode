use std::collections::VecDeque;

struct MovingAverage {
    window: VecDeque<i32>,
    window_size: i32,
    moving_avg: f64
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MovingAverage {

    fn new(size: i32) -> Self {
        MovingAverage {
            window: VecDeque::with_capacity(size as usize),
            window_size: size,
            moving_avg: 0.0
        }
    }
    
    fn next(&mut self, val: i32) -> f64 {
        // Edge condition
        if self.window_size == 0 {
            return 0.0;
        }

        if self.window.len() >= self.window_size as usize {
            let popped_num = self.window.pop_front().unwrap();
            // push new element
            self.window.push_back(val);
            self.moving_avg += ((val - popped_num) as f64 / self.window_size as f64);
        }
        else {
            self.moving_avg = (self.moving_avg * self.window.len() as f64 + val as f64) / (self.window.len() + 1) as f64;
            self.window.push_back(val);
        }

        self.moving_avg
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * let obj = MovingAverage::new(size);
 * let ret_1: f64 = obj.next(val);
 */