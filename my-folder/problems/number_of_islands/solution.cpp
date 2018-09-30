#include <iostream>
#include <vector>
#include <map>

using namespace std;

class DisjointSet {
  private:
    vector<int> parents_;
    vector<int> rank_;
    int nf_disjoint_sets_ = 0;

    void updateParent (int element, int parent_to_be) {
      parents_[element] = parent_to_be;
    }

  public:
    DisjointSet (int arr_size) {
      for (int ii = 0; ii < arr_size; ++ii) {
        parents_.push_back(ii);
        rank_.push_back(0);
      }
      nf_disjoint_sets_ = arr_size;
    }

    DisjointSet () {
      nf_disjoint_sets_ = 0;
    }

    /*
     * Insert a new element as a disjoint set.
     */
    void insert (int element) {
      parents_.push_back(element);
      rank_.push_back(0);
      nf_disjoint_sets_++;
    }

    void Union (int element1, int element2) {
      int parent1 = find(element1);
      int parent2 = find(element2);
      if (parent1 != parent2) {
        // Both the elements belong to different sets.
        int rank1 = rank_[parent1];
        int rank2 = rank_[parent2];
        if (rank1 < rank2) {
          updateParent(parent1, parent2);
        } else if (rank1 > rank2) {
          updateParent(parent2, parent1);
        } else {
          updateParent(parent1, parent2);
          rank_[parent2]++;
        }
        nf_disjoint_sets_--;
      }
    }

    /*
     * Return the root of the set this element belongs to.
     */
    int find (int element) {
      int parent = element;
      int temp_element;
      int count = 0;
      do {
        temp_element = parent;
        parent = parents_[temp_element];
        count++;
      } while (parent != temp_element);

      // Path compression.
      updateParent(element, parent);
      int rank_e = rank_[element];
      int rank_p = rank_[parent];
      if (count - 1 + rank_e == rank_p) {
        // we are path compressing the deepest path. update rank.
        rank_[element] = ((count - 1) < (rank_e + 1)) ? rank_e + 1 : count - 1;
      }

      return parent;
    }

    int numberOfDisjointSets () {
      return nf_disjoint_sets_;
    }
};

inline int index (int row, int col, int N) {
    return (row * N + col);
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int grid_rows = grid.size();
        if (grid_rows == 0) return 0;
        int grid_cols = grid[0].size();
        DisjointSet disjoint_set(grid_rows * grid_cols);
        int zero_count = 0;

        // Linear scan
        for (int ii = 0; ii < grid_rows; ++ii) {
            for (int jj = 0; jj < grid_cols; ++jj) {
                if (grid[ii][jj] == '1') {
                    // Look to the right.
                    if ((jj + 1 < grid_cols) && (grid[ii][jj + 1] == '1')) {
                        disjoint_set.Union(index(ii, jj, grid_cols), index(ii, jj + 1, grid_cols));                        
                    }
                    // Look down.
                    if ((ii + 1 < grid_rows) && (grid[ii + 1][jj] == '1')) {
                        disjoint_set.Union(index(ii, jj, grid_cols), index(ii + 1, jj, grid_cols));                        
                    }
                } else {
                    zero_count++;
                }
            }
        }
        return (disjoint_set.numberOfDisjointSets() - zero_count);
    }
};