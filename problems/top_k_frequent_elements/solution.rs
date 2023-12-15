use std::collections::HashMap;
use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut num_freq: HashMap<i32, i32> = HashMap::new();
        let mut min_heap: BinaryHeap<(Reverse<i32>, i32)> = BinaryHeap::with_capacity(k as usize);

        for num in nums {
            num_freq.entry(num).and_modify(|count| *count += 1).or_insert(1);
        }

        for (num, freq) in num_freq {
            min_heap.push((Reverse(freq), num));
            if min_heap.len() > k as usize {
                min_heap.pop();
            }
        }

        min_heap.into_iter().map(|(_, num)| num).collect()
    }
}