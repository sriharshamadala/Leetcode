impl Solution {
    pub fn interpret(command: String) -> String {
        let mut interpretation = String::new();
        let mut temp = String::new();

        for letter in command.chars() {
            match (letter) {
                'G' => interpretation.push('G'),
                '(' => { }
                'a' => temp.push('a'),
                'l' => temp.push('l'),
                ')' => { 
                    if (temp.is_empty()) {
                        interpretation.push('o');
                    } else {
                        interpretation.push_str(&temp);
                    }
                    temp = String::new();
                },
                _ => unreachable!(),
            }
        }

        return interpretation;
    }
}