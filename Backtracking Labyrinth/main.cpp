#include "header.hpp"
using namespace std;
int row = 0;
char maze[R][C];
void readMaze(FILE* fp) {
    if (fp == NULL)
    {
        cout << "Dosya açma hatasi" << endl;
        getch();
        exit(1);
    }

   
    while (fgets(maze[row], C, fp) != NULL)
    {
        row++;
    }
}

void writeMaze(FILE* fp) {
    if (fp == NULL)
    {
        cout << "Dosya açma hatasi" << endl;
        getch();
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);

    for (int a = 0; a < row; a++)
    {
        fputs(maze[a], fp);
    }
}

void printMaze() {
    system("cls");
    for (int b = 0; b < row; b++)
    {
        cout << maze[b];
    }
    cout << endl
         << endl;
}
void printPath(stack<node> path, FILE* fp) {
    while (!path.empty()) {
        node current = path.top();
        char pathSymbol = ' ';

        if (current.dir == 4) {
            pathSymbol = '>';
        } else if (current.dir == 1) {
            pathSymbol = '^';
        } else if (current.dir == 2) {
            pathSymbol = '<';
        } else if (current.dir == 3) {
            pathSymbol = 'v';
        }

        maze[current.x][current.y] = pathSymbol;
        writeMaze(fp);
        printMaze();
        sleep(1);

        
        maze[current.x][current.y] = ' ';

        path.pop();
    }
}

int main()
{   
    stack<node> path;
    FILE* fp = fopen("Harita.txt", "r+");
    readMaze(fp);
    if (isReachable(maze, path))
    {
        printPath(path,fp);
    }
    else
    {
        cout << "Cikis bulunamadi." <<endl;
    }

    fclose(fp);
    getch();
    return 0;
}
