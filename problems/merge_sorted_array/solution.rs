impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        // Do everything with iters instead of indices, where we need to do bound-checking

        /* This won't work since we can't have mutable and immutable references to the vector at the same time.
        let mut nums1_rev_iter_outer = nums1.into_iter().rev();
        let mut nums1_rev_iter_inner = nums1.iter().rev().skip(n);
        */
        let (m, n) = (m as usize, n as usize);
        // Have to make an additional copy to avoid the above problem, but this is very inefficient. 
        let nums1_copy = nums1.clone();
        let mut nums1_rev_iter = nums1_copy.iter().rev().skip(n);
        let mut nums1_rev_iter_mut = nums1.iter_mut().rev();
        let mut nums2_rev_iter = nums2.iter().rev();

        let mut ref1 = nums1_rev_iter_mut.next();
        let mut val1 = nums1_rev_iter.next();
        let mut val2 = nums2_rev_iter.next();
        loop {
            match (val1, val2) {
                (Some(num1), Some(num2)) => {
                    if num2 >= &num1 {
                        // We don't have to worry about unwrap because
                        // we haven't reached the end yet.
                        *(ref1.unwrap()) = *num2;
                        ref1 = nums1_rev_iter_mut.next();
                        val2 = nums2_rev_iter.next();
                    }
                    else {
                        *(ref1.unwrap()) = *num1;
                        ref1 = nums1_rev_iter_mut.next();
                        val1 = nums1_rev_iter.next();
                    }
                },
                (Some(num1), None) => {
                    // If num2 array is fully iterated, nothing more to do.
                    break;
                },
                (None, Some(num2)) => {
                    *(ref1.unwrap()) = *num2;
                    ref1 = nums1_rev_iter_mut.next();
                    val2 = nums2_rev_iter.next();
                },
                (None, None) => break,
            }
        }   
    }
}