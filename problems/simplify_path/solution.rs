impl Solution {
    pub fn simplify_path(mut path: String) -> String {
        
        let mut stack = Vec::new();
        let mut token = String::new();
        // Adding a trail slash to deal with edge cases
        path += "/";

        for c in path.chars() {
            match c {
                '/' => {
                    // Handles multiple slashes and starting edge case
                    if !token.is_empty() {
                        if token == ".." {
                            stack.pop();
                        }
                        else if token != "." {
                            stack.push(token);
                        }
                        token = String::new();                        
                    }
                },
                _ => token.push(c),                
            }
        }

        // Create path from stack
        let mut canonical_path = String::from("/");
        if stack.is_empty() {
            return canonical_path;
        }

        for file in stack {
            canonical_path.push_str(&file);
            canonical_path += "/";
        }
        // remove the final "/"
        canonical_path.pop();
        canonical_path
    }
}