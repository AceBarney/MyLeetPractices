#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;


class Solution {
    int M, N, ret;
    struct cell {
        int x;
        int y;
        int len;
    };
    void prt(string info, vector<vector<int>>& data)
    {
        cout<<info<<endl;
        for(int i = 0;i < data.size();i++) {
            for(int j = 0;j<data[0].size();j++) {
                cout<<data[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        M = grid.size();
        if(M == 0) {
            return -1;
        }
        N = grid[0].size();
        ret = 0xFFFF;
        vector<vector<int>> dist(M, vector<int>(N, 0));
        queue<cell> q;
        vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        int lv = 0;
        for(int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if(grid[i][j] != 1) {
                    continue;
                }
                // cout<<" found one place: " <<i <<", "<<j <<endl;
                q.push({i, j, 0});
                bool haveAccess = false;
                while(!q.empty()) {
                    cell cur = q.front();
                    q.pop();
                    for (auto d:dirs) {
                        cell nb = {cur.x + d.first, cur.y + d.second, cur.len + 1};
                        if (nb.x >= 0 && nb.x < M && nb.y >= 0 && nb.y < N &&
                            grid[nb.x][nb.y] == lv) {
                            dist[nb.x][nb.y] += nb.len;
                            grid[nb.x][nb.y] -= 1;
                            q.push(nb);
                            haveAccess = true;
                        }
                    }
                }
                if(!haveAccess) {
                    ret = -1;
                    break;
                }
                lv--;
            }
        }
        if (lv == 0) {
            return -1;
        }
        for(int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if(dist[i][j] < ret && dist[i][j] > 0) {
                    ret = dist[i][j];
                }
            }
        }
        if(ret == 0xffff) {
            ret = -1;
        }
        return ret;
    }
};

int main()
{
    // vector<vector<int>> test = {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    vector<vector<int>> test = {{1,1},{0,1}};
    Solution s;
    cout<<s.shortestDistance(test)<<endl;
    return 0;
}










