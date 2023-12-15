impl Solution {
    pub fn calculate(mut s: String) -> i32 {
        let mut num: i32 = 0;
        let mut stack: Vec<i32> = Vec::new();
        // Append a useless operator in the end to handle the edge case
        s += "+";

        enum Operator {
            Add,
            Sub,
            Mul,
            Div,
            Nop
        }

        let mut op = Operator::Add;
        let mut s_iter = s.chars();
        while let Some(c) = s_iter.next() {
            match c {
                '0'..='9' => {
                    num = num * 10 + c.to_digit(10).unwrap() as i32;
                },
                '+' | '-' | '*' | '/' => {
                    match op {
                        Operator::Add => stack.push(num),
                        Operator::Sub => stack.push(-num),
                        Operator::Mul => {
                            let mut operand = stack.pop().unwrap();
                            stack.push(operand * num);
                        },
                        Operator::Div => {
                            let mut operand = stack.pop().unwrap();
                            stack.push(operand / num);
                        },
                        Operator::Nop => {}
                    }
                    //println!("{:?}", stack);                    
                    op = match c {
                        '+' => Operator::Add,
                        '-' => Operator::Sub,
                        '*' => Operator::Mul,
                        '/' => Operator::Div,
                        _ => Operator::Nop,
                    };                   
                    num = 0;  
                },
                _ => {},

            }
        }

        stack.iter().sum()
    }
}