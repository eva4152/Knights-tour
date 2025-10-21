#include <stdio.h>
#define MOVE_COUNT 8
#define SIZE 9
#define minimum 0
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};
int numberOrder = 0;

int board[SIZE][SIZE] = {0};

int first_move(int x, int y) {
  int i;
  for (i = 0; i < MOVE_COUNT; i++) {
    int newX = MOVES_X[i] + x;
    int newY = MOVES_Y[i] + y;
    if (newX < SIZE && newX >= minimum && newY < SIZE && newY >= minimum &&
        board[newX][newY] == 0) {
      return i;
    }
  }
  return -1;
}

void generate_board(int x_start, int y_start) {
  for (int row = 1; row < SIZE; ++row) {
    for (int col = 1; col < SIZE; ++col) {
      if (row == x_start && col == y_start) {
        printf("xx ");
      }

      else if (board[row][col] != 0) {
        printf("%2d ", board[row][col]);
      }

      else {
        printf("-- ");
      }
    }
    puts(" ");
  }
  puts(" ");
}

void make_a_move(int x_start, int y_start) {
  int x = x_start;
  int y = y_start;
  generate_board(x_start, y_start);

  while (first_move(x, y) != -1) {
    int number = first_move(x, y);
    int x_new = x + MOVES_X[number];
    int y_new = y + MOVES_Y[number];
    x = x_new;
    y = y_new;
    board[x][y] = ++numberOrder;
    generate_board(x_start, y_start);
  }
}

int main() {
  printf("Hvor vil du starte?\nx:(1-8): ");
  int start_x;
  int start_y;
  scanf("%d", &start_x);
  printf("Hvad er din y:(1-8): ");
  scanf("%d", &start_y);
  make_a_move(start_x, start_y);
}