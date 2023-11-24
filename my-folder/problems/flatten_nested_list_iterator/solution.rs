// #[derive(Debug, PartialEq, Eq)]
// pub enum NestedInteger {
//   Int(i32),
//   List(Vec<NestedInteger>)
// }
struct NestedIterator {
    flattened_list: Vec<i32>,
    index: usize,
}

pub fn flatten(nested_list: Vec<NestedInteger>) -> Vec<i32> {
    let mut flattened_list = Vec::new();
    for nested_integer in nested_list {
        match nested_integer {
            NestedInteger::Int(integer) => flattened_list.push(integer),
            NestedInteger::List(list) => {
                let mut flattened_slice = flatten(list);
                flattened_list.append(&mut flattened_slice);
            }
        }            
    }

    flattened_list
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NestedIterator {

    fn new(nestedList: Vec<NestedInteger>) -> Self {
        NestedIterator {
            flattened_list: flatten(nestedList),
            index: 0
        }
    }
    
    fn next(&mut self) -> i32 {
        let val = self.flattened_list[self.index];
        self.index += 1;
        val
    }
    
    fn has_next(&self) -> bool {
        self.index < self.flattened_list.len()
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * let obj = NestedIterator::new(nestedList);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */