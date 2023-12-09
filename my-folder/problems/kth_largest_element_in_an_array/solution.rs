use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn find_kth_largest(mut nums: Vec<i32>, k: i32) -> i32 {
        /* solution 1
        // O(N*logN); O(logN)
        nums.sort();
        *nums.iter().rev().nth((k-1) as usize).unwrap()
        */

        /* Solution 2 surprisingly is slower than solution 1
        // Sorting in descending order
        nums.sort_by(|a, b| b.cmp(a));
        nums[(k - 1) as usize]
        */

        /* solution 3 is count sort
        // O(M+N); O(M)
        */

        /* Sol 3 - Min-Heap
        Heap sort
        // O(NlogK); O(K)
        // Min-Heap of K elements keeps the K large elements, while always discarding the smaller elements
        // How is this slower than solution 1?
    
        let mut heap = BinaryHeap::with_capacity((k + 1) as usize);
        for num in nums {
            heap.push(Reverse(num));
            if heap.len() > k as usize{
                heap.pop();
            }
        }
        
        heap.peek().unwrap().0
        */

        /* Sol 4 - Max-Heap
        */
        let mut heap = BinaryHeap::with_capacity(nums.len());
        for num in nums {
            heap.push(num);
        }
        for _ in 0..k-1 {
            heap.pop();
        }
        *heap.peek().unwrap()
    }
}