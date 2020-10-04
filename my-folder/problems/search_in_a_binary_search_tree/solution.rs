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
    pub fn search_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(root_node) = root {
            let root_node_val = root_node.borrow().val;
            if val == root_node_val {
                return Some(root_node);
            } else if val > root_node_val {
                return Self::search_bst(root_node.borrow().right.clone(), val);
            } else {
                return Self::search_bst(root_node.borrow().left.clone(), val);
            }            
        } else {
            return None;
        }
    }
}