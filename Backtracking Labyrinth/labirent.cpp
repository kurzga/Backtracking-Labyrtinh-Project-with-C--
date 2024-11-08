#include "header.hpp"
#include <conio.h>
using namespace std;
int n = R;
int m = C;
int fx,fy;
int i,j;
bool visited[R][C];
node::node(int i, int j) {
    x = i;
    y = j;
    dir = 0;
}
bool isReachable(char maze[R][C], stack<node>& path) {
	memset(visited, true, sizeof(visited));
	FindStartAndFinishPositions(maze);
	SetStartingPosition(i,j);
    SetEndingPosition(fx,fy);
    stack<node> s;
    node temp(i, j);
    s.push(temp);

    while (!s.empty())
    {
        temp = s.top();
        int d = temp.dir;
        i = temp.x, j = temp.y;

        temp.dir++;
        s.pop();
        s.push(temp);

        if (i == fx and j == fy)
        {
            while (!s.empty())
            {
                path.push(s.top());
                s.pop();
            }
            return true;
        }

        if (d == 0)
        {
            if (i - 1 >= 0 and maze[i - 1][j] == ' ' and visited[i - 1][j])
            {
                node temp1(i - 1, j);
                visited[i - 1][j] = false;
                s.push(temp1);
            }
        }
        else if (d == 1)
        {
            if (j - 1 >= 0 and maze[i][j - 1] == ' ' and visited[i][j - 1])
            {
                node temp1(i, j - 1);
                visited[i][j - 1] = false;
                s.push(temp1);
            }
        }
        else if (d == 2)
        {
            if (i + 1 < n and maze[i + 1][j] == ' ' and visited[i + 1][j])
            {
                node temp1(i + 1, j);
                visited[i + 1][j] = false;
                s.push(temp1);
            }
        }
        else if (d == 3)
        {
            if (j + 1 < m and maze[i][j + 1] == ' ' and visited[i][j + 1])
            {
                node temp1(i, j + 1);
                visited[i][j + 1] = false;
                s.push(temp1);
            }
        }
        else
        {
            visited[temp.x][temp.y] = true;
            s.pop();
        }
    }

    return false;
}

