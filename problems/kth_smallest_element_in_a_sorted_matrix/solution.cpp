struct Node {
  int val;
  int row_index;
  int col_index;
};

class MyCompare {
  public:
    bool operator()(Node *node_l, Node *node_r) {
      return (node_l->val >= node_r->val); 
    }
};

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<Node*, vector<Node*>, MyCompare> pq;
    int N = matrix.size();
    bool is_col_active[N];
    for (int ii = 0; ii < N; ++ii) {
      is_col_active[ii] = false;
    }
    int count = 0;
    int min;
    
    // Create first node
    Node * temp = new Node;
    temp->val = matrix[0][0];
    temp->row_index = 0;
    temp->col_index = 0;
    pq.push(temp);
    is_col_active[0] = true;
    
    while (count < k) {
      count++;
      Node * min_node = pq.top();
      pq.pop();
      min = min_node->val;
      //cout << min << " ";
      
      // Create the nodes to be pushed.
      int curr_row_index = min_node->row_index;
      int curr_col_index = min_node->col_index;
      if (curr_row_index < N - 1) {
        // Have atleast one node below to be pushed.
        Node * down = new Node;
        down->val = matrix[curr_row_index + 1][curr_col_index];
        //cout << down->val << " ";
        down->row_index = curr_row_index + 1;
        down->col_index = curr_col_index;
        pq.push(down);
      }
      if ((curr_col_index < N - 1) && (!is_col_active[curr_col_index + 1])) {
        // The column on the right hasn't been added yet.
        Node * right = new Node;
        right->val = matrix[0][curr_col_index + 1];
        //cout << right->val << " ";
        right->row_index = 0;
        right->col_index = curr_col_index + 1;
        is_col_active[curr_col_index + 1] = true;
        pq.push(right);
      }
      
      delete min_node;
      //cout << endl;
    }
    return min;
  }
};

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();