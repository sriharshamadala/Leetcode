// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, l: i32, r: i32) -> i32 {
        // Terminal condition
        if let Some(node) = root {
            let mut sum: i32 = 0;
            let node_val: i32 = node.borrow().val;
            
            // Traversal logic
            if node_val > l {
                sum += Self::range_sum_bst(node.borrow().left.clone(), l, r);
            } 
            
            if node_val < r {
                sum += Self::range_sum_bst(node.borrow().right.clone(), l, r);
            }
            
            // Include the node_val in the sum.            
            if (node_val >= l) && (node_val <= r) {
                sum += node_val;
            }
            
            return sum;
        } else {
            // Terminal condition
            return 0;
        }
    }
}