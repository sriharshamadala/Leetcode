#[derive(Copy, Clone)]
enum Direction {
    North,
    East,
    South,
    West
}

impl Solution {
    fn turn_clockwise (curr_direction: Direction) -> Direction {
        match curr_direction {
            Direction::North => Direction::East,
            Direction::East => Direction::South,
            Direction::South => Direction::West,
            Direction::West => Direction::North,
        }
    }

    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let nf_rows = matrix.len();
        let nf_cols = matrix[0].len();

        let mut is_visited = vec![vec![false; nf_cols]; nf_rows];
        let mut result = Vec::new();

        let mut row = 0;
        let mut col = 0;
        let mut curr_dir = Direction::East;

        loop {
            if Solution::is_out_of_range(row, col, nf_rows, nf_cols) || is_visited[row][col] {
                // Reached the end of our spiral
                break;
            }

            // Process curr step
            result.push(matrix[row][col]);
            is_visited[row][col] = true;

            // Calculate next step
            let (mut new_row, mut new_col) = Solution::next_step((row, col), curr_dir);
            if Solution::is_out_of_range(new_row, new_col, nf_rows, nf_cols) || is_visited[new_row][new_col] {
                // Change direction and re-calculate next step
                curr_dir = Solution::turn_clockwise(curr_dir);
                (new_row, new_col) = Solution::next_step((row, col), curr_dir);
            }

            (row, col) = (new_row, new_col);
        }

        result
    }

    fn is_out_of_range(row: usize, col: usize, nf_rows: usize, nf_cols: usize) -> bool {
        row < 0 || row >= nf_rows || col < 0 || col >= nf_cols
    }

    fn next_step(curr_step: (usize, usize), curr_dir: Direction) -> (usize, usize) {
        match curr_dir {
            Direction::East => (curr_step.0, curr_step.1 + 1),
            Direction::South => (curr_step.0 + 1, curr_step.1),
            Direction::West => (curr_step.0, curr_step.1 - 1),
            Direction::North => (curr_step.0 - 1, curr_step.1),
        }
    }
}