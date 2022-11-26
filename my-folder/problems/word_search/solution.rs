use std::collections::HashMap;

impl Solution {
    // Searches in adjacent positions from the given anchor point
    pub fn does_word_exist(board: &Vec<Vec<char>>, word: &str, 
                            anchor: (usize, usize), 
                            mut grid_visited: Vec<Vec<bool>>) -> bool {
        //println!("{}", word);
        //println!("{:?}", anchor);
        //println!("{:?}", grid_visited);
        if board[anchor.0][anchor.1] != word.chars().nth(0).unwrap() {
            return false;
        }
        grid_visited[anchor.0][anchor.1] = true;
        
        // Termination condition
        if (word.len() == 1) {
            return true;
        }

        // Do a diamond search
        // Look left
        if (anchor.1 > 0) && !(grid_visited[anchor.0][anchor.1 - 1]) {
            if Solution::does_word_exist(board, &word[1..], (anchor.0, anchor.1 - 1), grid_visited.clone()) {
                return true;
            }
        }
        // Look up
        if (anchor.0 > 0) && !(grid_visited[anchor.0 - 1][anchor.1]) {
            if Solution::does_word_exist(board, &word[1..], (anchor.0 - 1, anchor.1), grid_visited.clone()) {
                return true;
            }
        }
        // Look right
        if (anchor.1 < (board[0].len() - 1)) && !(grid_visited[anchor.0][anchor.1 + 1]) {
            if Solution::does_word_exist(board, &word[1..], (anchor.0, anchor.1 + 1), grid_visited.clone()) {
                return true;
            }
        }
        // Look down
        if (anchor.0 < (board.len() - 1)) && !(grid_visited[anchor.0 + 1][anchor.1]) {
            if Solution::does_word_exist(board, &word[1..], (anchor.0 + 1, anchor.1), grid_visited.clone()) {
                return true;
            }
        }
        return false;
    }

    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        let nf_rows = board.len();
        let nf_cols = board[0].len();
        let mut search_word = word;
        let word_len = search_word.len();
        let grid_visited = vec![vec![false; nf_cols]; nf_rows];

        // Hashmap to rule out easily :
        // If we don't have the required chars and count in the grid, no point looking
        let mut word_hash = HashMap::new();
        for letter in search_word.chars() {
            // Insert the key if it doesn't exist and set count to 1.
            // If if it does exist, inc count by 1.
            let count = word_hash.entry(letter).or_insert(1);
            *count += 1;
        }
        let mut grid_hash = HashMap::new();
        for row in 0..nf_rows {
            for col in 0..nf_cols {            
                let count = grid_hash.entry(board[row][col]).or_insert(1);
                *count += 1;
            }
        }

        //println!("{:?}", word_hash);
        //println!("{:?}", grid_hash);
        for letter in word_hash.keys() {
            match grid_hash.get(letter) {
                // Found the letter in grid.
                Some(count) => {
                    if (count < word_hash.get(letter).unwrap()) {
                        // But the count is less than the count in word. No point in searching.
                        return false;
                    }
                },
                // Did not find the letter in grid. No point searching.
                None => {return false;}
            }
        }

        // Reverse and search the word if the count of first letter > count of last letter
        // This reduces the number of branches, improving the run time.
        if word_hash.get(&search_word.chars().nth(0).unwrap()) > word_hash.get(&search_word.chars().nth(word_len-1).unwrap()) {
            search_word = search_word.chars().rev().collect::<String>();
        }

        for row in 0..nf_rows {
            for col in 0..nf_cols {
                if Solution::does_word_exist(&board, &search_word, (row, col), grid_visited.clone()) {
                    return true;
                }
            }
        }
        return false;
    }
}