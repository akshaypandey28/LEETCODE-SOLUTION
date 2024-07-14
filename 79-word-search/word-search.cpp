class Solution {
public:
    vector<vector<char>> b;
    int rows, cols;
    vector<vector<bool>> visited;

    bool f(int r, int c, string word, int i) {
        if (i == word.size()) return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols || b[r][c] != word[i] || visited[r][c]) return false;

        visited[r][c] = true;

        // Perform the DFS calls in a single line
        bool found = f(r + 1, c, word, i + 1) || f(r - 1, c, word, i + 1) ||
                     f(r, c + 1, word, i + 1) || f(r, c - 1, word, i + 1);

        visited[r][c] = false; // backtracking
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        rows = board.size();
        cols = board[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (f(r, c, word, 0)) return true;
            }
        }
        return false;
    }
};
