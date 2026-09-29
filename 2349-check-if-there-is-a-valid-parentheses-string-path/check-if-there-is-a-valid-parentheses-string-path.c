#include <stdbool.h>
#include <string.h>

bool dfs(char** grid, int m, int n, int i, int j, int balance,
         bool visited[100][100][201]) {

    // Add current bracket to balance
    if (grid[i][j] == '(')
        balance++;
    else
        balance--;

    // Invalid if ')' appears without a matching '('
    if (balance < 0)
        return false;

    // If balance is too large, there aren't enough cells
    // remaining to close all the brackets
    if (balance > (m - i) + (n - j) - 1)
        return false;

    // Reached destination
    if (i == m - 1 && j == n - 1)
        return balance == 0;

    // Already visited this state
    if (visited[i][j][balance])
        return false;

    visited[i][j][balance] = true;

    // Move down
    if (i + 1 < m) {
        if (dfs(grid, m, n, i + 1, j, balance, visited))
            return true;
    }

    // Move right
    if (j + 1 < n) {
        if (dfs(grid, m, n, i, j + 1, balance, visited))
            return true;
    }

    return false;
}


bool hasValidPath(char** grid, int gridSize, int* gridColSize) {

    int m = gridSize;
    int n = gridColSize[0];

    // Total number of characters in every path
    int length = m + n - 1;

    // A valid parentheses string must have even length
    if (length % 2 != 0)
        return false;

    // First character must be '('
    if (grid[0][0] == ')')
        return false;

    // Last character must be ')'
    if (grid[m - 1][n - 1] == '(')
        return false;

    bool visited[100][100][201] = {false};

    return dfs(grid, m, n, 0, 0, 0, visited);
}