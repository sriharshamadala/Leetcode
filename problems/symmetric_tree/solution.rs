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

type Rn = Rc<RefCell<TreeNode>>;

impl Solution {
    
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        
        match(root) {
            Some(root) => Solution::recursive(root.borrow().left.as_ref(), root.borrow().right.as_ref()),
            None => true,
        }        
    }
    
    pub fn recursive(L:Option<&Rn>, R:Option<&Rn>) -> bool {

        match(L, R) {
            (Some(L), Some(R)) => (L.borrow().val == R.borrow().val)
                                   && Solution::recursive(L.borrow().left.as_ref(), R.borrow().right.as_ref())
                                   && Solution::recursive(L.borrow().right.as_ref(), R.borrow().left.as_ref()),
            (None, None) => true,
            _ => false,
        }
    }
}

/* Iterative Solution
use std::collections::VecDeque;
impl Solution {
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut curr_level:VecDeque<Option<Rc<RefCell<TreeNode>>>> = VecDeque::new();
        let mut next_level:VecDeque<Option<Rc<RefCell<TreeNode>>>> = VecDeque::new();
        //let mut next_level_vals:VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
        
        if let Some(boxed_root) = root {
            curr_level.push_back(Some(boxed_root.clone()));
        }
        else {
            return true;  // empty tree is symmetric
        }
        println!("{:?}", curr_level);
        
        loop {
        */
            /*
            if !Solution::is_symmetric_vec(curr_level) {
                return false;
            }
            */
/*
            for node in curr_level {
                if let Some(node) = node {
                    next_level.push_back(node.clone().borrow().left);
                    next_level.push_back(node.borrow().right);
                }
            }
            
            if !Solution::is_symmetric_vec(next_level) {
                return false;
            } else {
                curr_level = next_level;
            }
            return true;
        }
        
        return true;
    }
    
    pub fn is_symmetric_vec(level_ref: VecDeque<Option<Rc<RefCell<TreeNode>>>>) -> bool {
        let mut front: Option<i32>;
        let mut back: Option<i32>;
        let mut level = level_ref;
        
        loop {
            if level.is_empty() {
                println!("level is empty");
                return true;
            } else if (level.len() == 1) {
                println!("level has one node");
                return false;
            } else {
                if let Some(temp_front) = level.pop_front().unwrap() {
                    front = Some(temp_front.borrow().val);
                } else {
                    front = None;
                }

                if let Some(temp_back) = level.pop_back().unwrap() {
                    back = Some(temp_back.borrow().val);
                } else {
                    back = None;
                }

                match (&front, &back) {
                    (Some(front), Some(back)) => {
                        if (front == back) {continue;}
                        else {return false;}
                    },
                    (None, None) => continue,
                    _ => return false,
                }
            }
        }
    }
}
*/