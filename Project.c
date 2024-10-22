#include <stdio.h>

#define DIM1 25
#define DIM2 25

#define ZERO 0
#define ONE 1
#define TWO 2
#define TEN 10

#define BOOL int
#define TRUE !ZERO
#define FALSE ZERO

// Validation
{
	
	
	
}




// Check
int Play_Row_Turn() {
    unsigned short row;
    printf("enter row: \n");
    scanf("%d", &row);  
    // validate if the value entered is good.
    // if not ask again, else continue    
    return row;
}
int Play_Col_Turn() {
    unsigned short col;
    printf("enter col: \n");
    scanf("%d", &col);  
    // validate if the value entered is good.
    // if not ask again, else continue    
    return col;
}

void Kill(int counter, int mat[][], int row, int col) {
    counter -= mat[row - ONE][col] == ZERO && mat[row + ONE][col] == ZERO && mat[row][col - ONE] == ZERO && mat[row][col + ONE];
}

BOOL Hit(int mat[][], int row, int col) {
    BOOL flag = FALSE;
    mat[row][col] == ONE ? flag = TRUE : ZERO;
    mat[row][col] = !flag;
    return flag;
}

void Game() {
	int mat[DIM1][DIM2];
	
	int row, col;
	
    unsigned short players_turn = ONE;
	unsigned short ships_count_player1 = TEN;
	unsigned short ships_count_player2 = TEN;
	
    BOOL is_hit, is_someone_won = FALSE;
    
    while (!is_someone_won) {
        // do not forget to write what player play!
        printf("player %d, it's your turn \n", players_turn);
		
		row = Play_Row_Turn();
		col = Play_Col_Turn();
		
        is_hit = Hit(mat, row(), col());
		is_hit ? printf("hit !") : printf("no hit");
		
		// using the players turn we can know whom counter to change
		// check
		players_turn % TWO == ZERO ? Kill(ships_count_player1, mat, row, col);
		players_turn % TWO != ZERO ? Kill(ships_count_player2, mat, row, col);		
		
		// update which player now needs to play
		// check
		players_turn++;
		
		// update if anyone won
		is_someone_won = ships_count_player1 == ZERO || ships_count_player2 == ZERO;
    }       
}

int main(void) {
    Game();
    return ZERO;
}
