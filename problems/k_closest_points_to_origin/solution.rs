use std::collections::BinaryHeap;
use std::cmp::Ordering;

// Feeding both location and euclidean distance to our Max-Heap
struct MyPoint {
    loc: Vec<i32>,
    distance: f64
}

// BinaryHeap needs Ord trait implemented for our custom struct
impl Ord for MyPoint {
    fn cmp(&self, other: &Self) -> Ordering {
        self.distance.partial_cmp(&other.distance).unwrap()
    }
}

impl PartialOrd for MyPoint {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

// Since the distance is a float, we have to define our own Eq trait
// We can unwrap on partial_cmp since we know there are no NaNs in our case.
impl PartialEq for MyPoint {
    fn eq (&self, other: &Self) -> bool {
        match self.distance.partial_cmp(&other.distance).unwrap() {
            Ordering::Less | Ordering::Greater => false,
            Ordering::Equal => true
        }
    }
}

impl Eq for MyPoint {}

impl Solution {
    pub fn k_closest(mut points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        /*
            Brute force way is to sort the points by distance to origin and
            return first k elements

        let distance = |v: &Vec<i32>| -> f64 {
            ( (v[0].pow(2) + v[1].pow(2)) as f64 ).sqrt()
        };
        points.sort_unstable_by( |v1, v2| distance(&v1).partial_cmp(&distance(&v2)).unwrap() );
        points.drain(k as usize..);
        points
        */

        let mut heap = BinaryHeap::with_capacity(k as usize);
        let distance = |v: &Vec<i32>| -> f64 {
            ( (v[0].pow(2) + v[1].pow(2)) as f64 ).sqrt()
        };

        for point in points {
            let my_point = MyPoint {
                distance: distance(&point),
                loc: point,
            };
            
            heap.push(my_point);
            if (heap.len() as i32) > k {
                heap.pop();
            }
        }
        
        heap.into_iter().map(|my_point| my_point.loc).collect()
    }
}