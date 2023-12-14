// #[derive(Debug, PartialEq, Eq)]
// pub enum NestedInteger {
//   Int(i32),
//   List(Vec<NestedInteger>)
// }
impl Solution {
    fn depth_sum_recur(nested_list: &[NestedInteger], depth: i32) -> i32 {
        nested_list.into_iter()
            .fold(0, |acc, elem| match elem {
                NestedInteger::Int(n) => acc + n * depth,
                NestedInteger::List(l) => acc + Solution::depth_sum_recur(&*l, depth + 1),
            })
    }

    pub fn depth_sum(nested_list: Vec<NestedInteger>) -> i32 {
        Solution::depth_sum_recur(&nested_list, 1)
    }
}