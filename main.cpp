#include <iostream>
#include <cstdlib>

using namespace std;

bool gameOver = false;
int width=5,height=5;
int matrix[7][7] = { {1,1,1,1,1,1},
                     {1,0,0,0,0,1},
                     {1,0,0,0,0,1},
                     {1,0,0,0,0,1},
                     {1,0,0,0,0,1},
                     {1,1,1,1,1,1}};
char dir;

void giving2RandomValues();
void initMatrix();
void drawMatrix();
bool decideIfGameOver();
void move(char dir);
void spawnRandom2();

void setup() {
    giving2RandomValues();
    drawMatrix();

}

void draw() {
    drawMatrix();
    move(dir);
    spawnRandom2();
}













void move(char dir) {

    struct Direction {
        int x = 0,
            y = 0;
    } direction;

    if (dir == 'a') direction.y = -1;
    if (dir == 'd') direction.y = 1;
    if (dir == 'w') direction.x = -1;
    if (dir == 's') direction.x = 1;

    int i,j;
    for (int  iterrator = 0; iterrator < 4; iterrator ++){
    for (i = 1; i < width; i++) {
        for (j = 1; j < height; j++) {
            if (matrix[i][j] != 0) {
                    while (matrix[i + direction.x][j + direction.y] == 0) {
                        swap(matrix[i + direction.x][j + direction.y], matrix[i][j]);
                    }

                    if (matrix[i + direction.x][j + direction.y] == matrix[i][j]) {
                        matrix[i + direction.x][j + direction.y] = matrix[i + direction.x][j + direction.y]*2;
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
}


void spawnRandom2() {
    int randomX = rand() % width + 1;
    int randomY = rand() % width + 1;

    if (matrix[randomX][randomY] == 0) {
        matrix[randomX][randomY] = 2;
    }
}


bool decideIfGameOver() {
    bool stack = true;
    int i,j;
    for (i = 1; i < width; i++) {
        for (j = 1; j < height; j++) {
            if (matrix[i][j] != 0) {
                if (matrix[i][j] == matrix[i][j]) {
                    stack = false;
                }
            }
        }
    }
    return stack;
}





void drawMatrix() {
    system("clear");

    cout << "  +  -  +  -  +  -  +  -  +";
    cout << '\n';



    int i,j;
    for (i = 1; i < width; i++) {

        for (j = 1; j < height; j++) {

            cout << "  |  " << matrix[i][j];

        }

        cout << "  |  ";
        cout << '\n';
        cout << "  +  -  +  -  +  -  +  -  +";
        cout << '\n';
    }

}

void giving2RandomValues() {
    matrix[2][3] = 2;
    matrix[1][3] = 2;
}




int main() {

    setup();

    while (gameOver == false) {
        cin >> dir;
        draw();
        gameOver = decideIfGameOver();
    }

    return 0;
}
