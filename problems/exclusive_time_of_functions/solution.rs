impl Solution {
    pub fn exclusive_time(n: i32, logs: Vec<String>) -> Vec<i32> {
        // Store the exclusive times
        let mut result = vec![0; n as usize];
        let mut stack = Vec::new();

        for log in logs {
            let parts: Vec<&str> = log.split(":").collect();
            let fid: i32 = parts[0].parse().unwrap();
            let time: i32 = parts[2].parse().unwrap();
            //println!("{:?}", result);
            //println!("stack {:?}", stack);

            match parts[1] {
                "start" => {                    
                    // calc prev func's execution time and store in the result
                    if let Some((last_fid, start_time)) = stack.last() {
                        result[*last_fid as usize] += time - start_time;
                    }
                    stack.push((fid, time))
                },
                "end" => {
                    let (last_fid, start_time) = stack.pop().unwrap();
                    result[last_fid as usize] += time - start_time + 1;
                    // After popping last func, start timer for the prev func
                    if let Some((_, start_time)) = stack.last_mut() {
                        *start_time = time + 1;
                    }
                },
                _ => unreachable!()
            }
        }
        
        result
    }
}