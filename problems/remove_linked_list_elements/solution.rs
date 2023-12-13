// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn remove_elements(mut head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut curr_node = &mut head;

        loop {
            match curr_node {
                None => break,
                Some(node) if node.val == val => {
                    *curr_node = node.next.take()
                },
                Some(node) => {
                    curr_node = &mut node.next;
                },
            }
        }

        head
    }
}