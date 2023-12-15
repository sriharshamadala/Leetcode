impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut count = 0;
        let mut stack = Vec::new();

        for c in s.chars() {
            match c {
                '(' => stack.push('('),
                ')' => {
                    if stack.len() == 0 {
                        // No opening paranthesis to balance out
                        count += 1;
                    }
                    else {
                        stack.pop();
                    }
                },
                _ => unreachable!()
            }
        }

        count += stack.len();
        count as i32
    }
}