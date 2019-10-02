#include<stdio.h>

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
    int dimension = input[0]-48;
    int width = input[1]-48;
    int height = input[2]-48;
    printf("It will be done on: %i, %i, %i \n", dimension, width, height);
    if(*(*(*(tables_adr+dimension)+width)+height)!=0){
        printf("The Selected Point is occupied, u loss one turn\n");
    }
    if(player==0){
        *(*(*(tables_adr+dimension)+width)+height) = 1;
    }else{
        *(*(*(tables_adr+dimension)+width)+height) = 2;
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
