#include <stdio.h>
int array_size = 10;
int grid_size;
int bool_game = 1;
typedef struct cell
{
    char char1;
    char char2;
    char char3;
} cell;

cell cell_array[10][10];

void create_cell_array(int grid_size)
{
    for (int i = 0; i < grid_size; i++)
    {
        for (int k = 0; k < grid_size; k++)
        {
            cell_array[i][k].char1 = '|';
            cell_array[i][k].char2 = ' ';
            cell_array[i][k].char3 = '|';
        }
    }
}

void print_cell_line(int i)
{
    for (int k = 0; k < grid_size; k++)
    {
        printf("%c ", cell_array[i][k].char1);
        printf("%c", cell_array[i][k].char2);
        printf(" %c", cell_array[i][k].char3);
    }
    printf("\n");
}
void print_boarder_line()
{
    // +---++---++---+
    // | X ||   ||   |
    // +---++---++---+
    // |   ||   ||   |
    // +---++---++---+
    // |   ||   ||   |
    // +---++---++---+
    for (int i = 0; i < grid_size; i++)
    {
        printf("+---+");
    }
    printf("\n");
}
void print_cell_grid()
{
    print_boarder_line();
    for (int i = 0; i < grid_size; i++)
    {
        print_cell_line(i);
        print_boarder_line();
    }
}
void array_cell_change(int x, int y, char c)
{
    cell_array[x][y].char2 = c;
}
void player_turn(int player_num)
{
    char c;
    if (player_num == 0)
    {
        c = 'X';
    }
    else if (player_num == 1)
    {
        c = 'O';
    }

    int num1 = 0;
    int num2 = 0;
    printf("Enter the row and the column (# #)");
    scanf("%d %d", &num1, &num2);
    array_cell_change(num1, num2, c);

    print_cell_grid();
}

int main()
{
    scanf("%d", &grid_size);
    create_cell_array(grid_size);
    print_cell_grid();
    player_turn();
    return 0;
}