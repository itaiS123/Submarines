#include <stdio.h>

#define DIM1 25

#define ZERO 0
#define ONE 1
#define TWO 2
#define TEN 10

#define BOOL int
#define TRUE !ZERO
#define FALSE ZERO

// Input validation
{
	BOOL Is_row_or_col_good(int row, int col){
		return !(row >= DIM1 || row <= ZERO || col >= DIM1 || col <= ZERO);
	}		
	
	BOOL Is_input_diagnal(int mat[][],int row, int col){
		return !(mat[row][col] == mat[row -ONE][col +ONE] || mat[row][col] == mat[row +ONE][col -ONE])
	}
	
	
	
	BOOL Is_input_good(int row, int col){
		return ; // all validate functions
	}
}

// check
int Play_Row_Turn() {
    unsigned short row;
    printf("enter row: \n");
    scanf("%d", &row);  
	
	while(Is_row_or_col_good(row)){
		printf("enter row: \n");
		scanf("%d", &row);
	}
    return row;
}
int Play_Col_Turn() {
    unsigned short col;
    printf("enter col: \n");
    scanf("%d", &col);   
	while(Is_row_or_col_good(col)){
			printf("enter col: \n");
			scanf("%d", &col);
		}	
    return col;
}

// check
void Hit(int mat_opponent[DIM1][DIM1], int mat_guess[DIM1][DIM1], int row, int col) {
    BOOL flag = FALSE;
    mat_opponent[row][col] == ONE ? flag = TRUE : ZERO;
    mat_opponent[row][col] = !flag;
	
	mat_guess[row][col] = flag;
	
	flag ? printf("Hit !") : printf("No hit");
}
// kill not working good, need to fix
void Kill(int counter, int mat[][], int row, int col) {
    counter -= mat[row -ONE][col] == ZERO && mat[row +ONE][col] == ZERO && mat[row][col -ONE] == ZERO && mat[row][col +ONE];
}

void Game() {
	int mat_sub_player1[DIM1][DIM1];
	int mat_guess_player1[DIM1][DIM1];
	
	int mat_sub_player2[DIM1][DIM1];
	int mat_guess_player2[DIM1][DIM1];
	
	unsigned short row, col;    	
	unsigned short player_turn = ONE;
	unsigned short subs_count_player1 = TEN;
	unsigned short subs_count_player2 = TEN;
    
	// plyers will place their subs here...	
	// mat_sub_player1 and mat_sub_player2...
	
    
    while (ships_count_player1 > ZERO && ships_count_player2 > ZERO){
		// player turn
        printf("player %d, please enter your move \n", player_turn % TWO +ONE);		
		row = Play_Row_Turn();
		col = Play_Col_Turn;
		
		// checking hit and kill
		player_turn % TWO +ONE == ONE ? Hit(mat_sub_player2, mat_guess_player1, row, col), Kill(subs_count_player2, mat_sub_player2, row, col) : ZERO; 		
		player_turn % TWO +ONE == TWO ? Hit(mat_sub_player1, mat_guess_player2, row, col), Kill(subs_count_player1, mat_sub_player1, row, col) : ZERO; 
		
		counter++;
    }       
}

int main(void) {
    Game();
    return ZERO;
}
