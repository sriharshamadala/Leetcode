impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        let mut stack: Vec<char> = Vec::new();
        let mut result = String::new();

        for character in s.chars() {
            match character {
                '(' => {
                    stack.push(character);
                    result.push(character);
                },
                ')' => {
                    // stack should only contain opening paranthesis
                    if !stack.is_empty() {
                        stack.pop();
                        result.push(character);
                    }
                },
                'a'..='z' => result.push(character),
                _ => unreachable!()
            }
        }

        // After the loop, we could end up with non-empty stack, i.e. with one or more of '('
        // Remove them from the output
        let mut temp = String::new();
        while let Some(_) = stack.pop() {
            while let Some(character) = result.pop() {
                if character == '(' {
                    break;
                }
                else {
                    temp.push(character);
                }
            }
        }

        while let Some(character) = temp.pop() {
            result.push(character);
        }

        result
    }
}