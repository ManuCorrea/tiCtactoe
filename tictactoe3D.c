#include<stdio.h>
#include<math.h>

#define W 3
#define H 3
#define D 3

void print_table(int (*tables_adr)[H][W]){
    for(int i=0; i<D; i++){
        for(int j=0; j<H; j++){
            printf("| ");
            for(int k=0; k<W; k++){
                //printf("i: %i, j: %i, k: %i --->", i, j, k);
                printf("%i ", *(*(*(tables_adr +i) + j) +k));
            }
            puts("|");
        }
        printf("---------\n");
    }
}

void user_input(int player, int (*tables_adr)[H][W]){
    char input[10];
    scanf("%s", input);
    printf("la entrada: ");
    printf(input);
    printf("\n");
    int z = input[0]-48;
    int x = input[1]-48;
    int y = input[2]-48;
    printf("It will be done on: %i, %i, %i \n", z, x, y);
    if(*(*(*(tables_adr+z)+x)+y)!=0){
        printf("The Selected Point is occupied, u loss one turn\n");
    }
    if(player==0){
        *(*(*(tables_adr+z)+x)+y) = 1;
    }else{
        *(*(*(tables_adr+z)+x)+y) = 2;
    }
}

int check(int player, int (*tables_adr)[H][W], int z, int x, int y){
    // *(*(*(tables_adr +i) + j) +k)
    for(int z_idx=0; z<D; z_idx++){
        for(int x_idx=0; x_idx<W; x_idx++){
            if (*(*(*(tables_adr + z_idx) + x_idx) + y) != player)
            {
                break;
            }
            if (x == W-1)
            {
                /* point! */
            }
            
        }
        for(int y_idx=0; y_idx<W; y_idx++){
            if (*(*(*(tables_adr + z_idx) + x) + y_idx) != player)
            {
                break;
            }
            if(y == W-1){
                /* point! */
            }
        }
    }

    int middle = (int) ceil((double) W/(double) H);
    if(*(*(*(tables_adr + middle) + middle ) + middle) != player){ // if not equal don't check diagonals
        
    }
    for(int idx_x_y = 0; idx_x_y < W; idx_x_y++){ // Just valid with squared boards
        for (int z_idx = 0; z<D; z_idx++){
            if( *(*(*(tables_adr + z_idx) + idx_x_y) + idx_x_y) != player){
                break;
            }
            if (z_idx == D-1)
            {
                // point!
            }
            
        }
    }
}

int main(){
    int tables[D][W][H] = {0};
    int (*tables_pointer)[W][H];
    tables_pointer = tables;
    while (1){
        print_table(tables_pointer);
        user_input(0, tables_pointer);
        print_table(tables_pointer);
        user_input(1, tables_pointer);
    }
       
    return 1;
}
