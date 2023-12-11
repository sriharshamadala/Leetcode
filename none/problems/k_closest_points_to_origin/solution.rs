use std::collections::BinaryHeap;
use std::collections::HashMap;

impl Solution {
    pub fn k_closest(mut points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        // Brute force way is to sort the points by distance to origin and
        // return first k elements
        //f64::sqrt(((v[0].pow(2) + v[1].pow(2))) as f64)
        points.sort_by(|v1, v2| ((v1[0].pow(2) + v1[1].pow(2)) as f64).sqrt().partial_cmp(&( ( v2[0].pow(2) + v2[1].pow(2) ) as f64).sqrt()).unwrap());
        points.drain(k as usize..);
        points

        /* 
        let mut heap = BinaryHeap::new();
        let mut map = HashMap::new();
        for point in points {
            let distance = f64::sqrt((point[0].pow(2) + point[1].pow(2)) as f64);
            map.insert(distance, point);
            heap.push(distance);
            if (heap.len() as i32) > k {
                heap.pop();
            }
        }
        */
    }
}