use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn min_meeting_rooms(mut intervals: Vec<Vec<i32>>) -> i32 {
        /*
        Min-Heap solution
        */

        // Sort intervals based on start times
        intervals.sort_by_key(|v| v[0]);

        // In Rust default is Max-Heap; Hence we need to reverse the elements we are pushing
        let mut end_times_heap: BinaryHeap<Reverse<i32>> = BinaryHeap::new();
        for interval in intervals {
            if let Some(end_time) = end_times_heap.peek() {                
                if interval[0] >= (*end_time).0 {
                    // pop and insert the new end_time
                    end_times_heap.pop();
                }
            }
            end_times_heap.push(Reverse(interval[1]));
        }

        end_times_heap.len() as i32

        /*
        Chronological solution

        // Store start and end times seperately
        let mut start_times = Vec::new();
        let mut end_times = Vec::new();
        let nf_intervals = intervals.len();
        for interval in intervals {
            start_times.push(interval[0]);
            end_times.push(interval[1]);
        }

        // Sort both start and end times
        start_times.sort();
        end_times.sort();

        // Use the two pointer trick        
        let mut start_index = 0;
        let mut end_index = 0;
        let mut result = 0;
        while  (start_index < nf_intervals) && (end_index < nf_intervals) {
            if start_times[start_index] < end_times[end_index] {
                result += 1;
                start_index += 1;
            }
            else {
                end_index += 1;
                start_index += 1;
            }
        }

        result
        */


    }
}