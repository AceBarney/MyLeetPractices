#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution {
    int M, N;
    bool dfs(vector<vector<int>>& maze, vector<vector<bool>>& visited,
        vector<int>& cur, vector<int>& dest)
    {
        if (visited[cur[0]][cur[1]]) {
            return false;
        }
        if ((cur[0] == dest[0]) && (cur[1] == dest[1])) {
            return true;
        }
        visited[cur[0]][cur[1]] = true;

        // right *
        int r = cur[1] + 1;
        while (r < N && maze[cur[0]][r] == 0) {
            r++;
        }
        vector<int> right = {cur[0], r - 1};
        if (dfs(maze, visited, right, dest)) {
            return true;
        }

        // left
        int l = cur[1] - 1;
        while (l >= 0 && maze[cur[0]][l] == 0) {
            l--;
        }
        vector<int> left = {cur[0], l + 1};
        if (dfs(maze, visited, left, dest)) {
            return true;
        }

        //up
        int u = cur[0] - 1;
        while (u >= 0 && maze[u][cur[1]] == 0) {
            u--;
        }
        vector<int> up = {u + 1, cur[1]};
        if (dfs(maze, visited, up, dest)) {
            return true;
        }

        // down
        int d = cur[0] + 1;
        while (d < M && maze[d][cur[1]] == 0) {
            d++;
        }
        vector<int> down = {d - 1, cur[1]};
        if (dfs(maze, visited, down, dest)) {
            return true;
        }
        return false;
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        M = maze.size();
        N = maze[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        return dfs(maze, visited, start, destination);
    }
};

int main()
{
    vector<vector<int>> maze1 =
    {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
    };
    vector<int> start1 = {0, 4};
    vector<int> destination1 = {4,4};

    vector<vector<int>> maze2 =
    {
        {0,0,1,0,0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
    };
    vector<int> start2 = {0, 4};
    vector<int> destination2 = {3, 2};


    vector<vector<int>> maze3 =
    {
        {0,0,0,0,1,0,0},
        {0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1},
        {0,1,0,0,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,1,0,0,0,1},
        {0,0,0,0,1,0,0},
    };
    vector<int> start3 = {0, 0};
    vector<int> destination3 = {8, 6};

    Solution s;
    cout<<s.hasPath(maze3, start3, destination3)<<endl;
    return 0;
}