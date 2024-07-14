class Solution {
public:
    vector<vector<char>> b;
    int rows, cols;
    vector<vector<bool>> visited;

    bool dfs(int r, int c, string& word, int index) {
        if (index == word.size()) return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols || b[r][c] != word[index] || visited[r][c]) return false;

        visited[r][c] = true;

        bool found = dfs(r + 1, c, word, index + 1) ||
                     dfs(r - 1, c, word, index + 1) ||
                     dfs(r, c + 1, word, index + 1) ||
                     dfs(r, c - 1, word, index + 1);

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
                if (dfs(r, c, word, 0)) return true;
            }
        }
        return false;
    }
};
