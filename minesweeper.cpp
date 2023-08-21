#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        const pair<int, int> dirs[] = {{0, 1},  {0, -1}, {1, 0}, {-1, 0},
                                       {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
        int x = click[0], y = click[1];

        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        } else if (board[x][y] == 'E') {
            int rows = board.size(), cols = board[0].size();
            stack<pair<int, int>> st;

            int bombs, r, c;

            st.emplace(x, y);

            while (!st.empty()) {
                tie(x, y) = st.top();
                st.pop();

                bombs = 0;

                for (auto d : dirs) {
                    r = x + d.first, c = y + d.second;
                    if (r >= 0 && c >= 0 && r < rows && c < cols && board[r][c] == 'M') {
                        ++bombs;
                    }
                }

                if (bombs == 0) {
                    for (auto d : dirs) {
                        r = x + d.first, c = y + d.second;
                        if (r >= 0 && c >= 0 && r < rows && c < cols && board[r][c] == 'E') {
                            st.emplace(r, c);
                        }
                    }
                    board[x][y] = 'B';
                } else {
                    board[x][y] = '0' + bombs;
                }
            }
        }
        return board;
    }
};
