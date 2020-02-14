#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        q.push({start[0], start[1]});
        int M = maze.size();
        int N = maze[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur.first == destination[0] && cur.first == destination[1]) {
                return true;
            }
            
            for (auto d : dirs) {
                int x = cur.first + d.first;
                int y = cur.second + d.second;
                while(x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 0) {
                    x += d.first;
                    y += d.second;
                }
                int px = x - d.first;
                int py = y - d.second;
                if(!visited[px][py]) {
                    visited[px][py] = true;
                    q.push({px, py});
                }
            }
        }
        return false;
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