#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <stack>
#include<unistd.h>
#include <conio.h>
#include <cstring>
#define R 100 //Satır
#define C 100 //Sütun

class node {
public:
    int x,y;
    int dir;

    node(int i, int j);
    node();
};
void SetStartingPosition(int &i,int &j);
void SetEndingPosition(int &fx,int &fy);
void readMaze(FILE* fp);
void writeMaze(FILE* fp);
void printMaze();
bool isReachable(char maze[R][C], std::stack<node>& path);
void printPath(std::stack<node> path, FILE* fp);
bool FindStartAndFinishPositions(char maze[R][C]);

extern int n, m, row;
extern char maze[R][C];
extern int i,j;
extern int fx, fy;
extern bool visited[R][C];
extern node S;
extern node F;
#endif
