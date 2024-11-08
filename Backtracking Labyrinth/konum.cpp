#include "header.hpp"
using namespace std;
node S;
node F;
int i_start = S.x;
int j_start = S.y;
int fx_end = F.x;
int fy_end = F.y;
node::node(){
    x = 0;
    y = 0;
    dir = 0;
}
void SetStartingPosition(int& i, int& j) {
    i = S.x;
    j = S.y;
}

void SetEndingPosition(int& fx, int& fy) {
    fx = F.x;
    fy = F.y;
}
bool FindStartAndFinishPositions(char maze[R][C]) {
    bool foundStart = false;
    bool foundFinish = false;

    for (int t = 0; t < n; t++) {
        for (int y = 0; y < m; y++) {
            if (maze[t][y] == 'S') {
                S.x = t;
                S.y = y;
                maze[t][y]=' ';
                foundStart = true;
        	}
            if (maze[t][y] == 'F') {
                F.x = t;
                F.y = y;
                maze[t][y]=' ';
                foundFinish = true;
            }

            if (foundStart == true && foundFinish == true) {
                return true;
            }
     	
       }
    }

    cout << "Hata: 'S' veya 'F' karakterleri bulunamadi." << endl;
    exit(1);
}