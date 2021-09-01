#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printBoard(char (*chessBoard)[16]){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 16; j++){

            if(j == 0)
                printf("   %d   ",8-i);

            printf("%c", *(*(chessBoard + i) + j));

            if(j%2==1)
                printf("  ");
        }
        printf("\n\n");
    }
    printf("\tA  B   C   D   E   F   G   H\n\n");
}

void knight(char (*chessBoard)[16], char pieceColor, int rows, int cols,char (*moves)[2]){
    char letters[16] = {"AABBCCDDEEFFGGHH"};
    int counter = 0;
    if(rows-2 > -1){
        if(cols-2 > -1){
            if(chessBoard[rows-2][cols-2] != pieceColor){
                moves[counter][0] = letters[cols-2];
                moves[counter][1] = (8-rows+2) + '0';
                counter++;
            }
        }
        if(cols+2 < 16){
            if(chessBoard[rows-2][cols+2] != pieceColor){
                moves[counter][0] = letters[cols+2];
                moves[counter][1] = (8-rows+2) + '0';
                counter++;
            }
        }
    };
    if(rows-1 > -1){
        if(cols-4 > -1){
            if(chessBoard[rows-1][cols-4] != pieceColor){
                moves[counter][0] = letters[cols-4];
                moves[counter][1] = (8-rows+1)  + '0';
                counter++;
            }
        }
        if(cols+4 < 16){
            if(chessBoard[rows-1][cols+4] != pieceColor){
                moves[counter][0] = letters[cols+4];
                moves[counter][1] = (8-rows+1)  + '0';
                counter++;
            }
        }
    }
    if(rows+2 < 8){
        if(cols-2 > -1){
            if(chessBoard[rows+2][cols-2] != pieceColor){
                moves[counter][0] = letters[cols-2];
                moves[counter][1] = (8-rows-2)  + '0';
                counter++;
            }
        }
        if(cols+2 < 16){
            if(chessBoard[rows+2][cols+2] != pieceColor){
                moves[counter][0] = letters[cols+2];
                moves[counter][1] = (8-rows-2)  + '0';
                counter++;
            }
        }
    };
    if(rows+1 < 8){
        if(cols-4 > -1){
            if(chessBoard[rows+1][cols-4] != pieceColor){
                moves[counter][0] = letters[cols-4];
                moves[counter][1] = (8-rows-1) + '0';
                counter++;
            }
        }
        if(cols+4 < 16){
            if(chessBoard[rows+1][cols+4] != pieceColor){
                moves[counter][0] = letters[cols+4];
                moves[counter][1] = (8-rows-1) + '0';
                counter++;
            }
        }
    }
}
void king(char (*chessBoard)[16], char pieceColor, int rows, int cols,char (*moves)[2]){
    char letters[16] = {"AABBCCDDEEFFGGHH"};
    int counter = 0;
    if(cols != 14){
        if(chessBoard[rows][cols+2] != pieceColor){      ///right move
            moves[counter][0] = letters[cols+2];
            moves[counter][1] = (8-rows) + '0';
            counter++;
        }

        if(rows != 7 && rows != 0){
            if(chessBoard[rows+1][cols+2] != pieceColor){      ///lower right move
                moves[counter][0] = letters[cols+2];
                moves[counter][1] = (8-rows-1) + '0';
                counter++;
            }
            if(chessBoard[rows-1][cols+2] != pieceColor){      ///upper right move
                moves[counter][0] = letters[cols+2];
                moves[counter][1] = (8-rows+1) + '0';
                counter++;
            }
        }
    }

    if(cols != 0){
        if(chessBoard[rows][cols-2] != pieceColor){      ///left move
            moves[counter][0] = letters[cols-2];
            moves[counter][1] = (8-rows) + '0';
            counter++;
        }

        if(rows != 7 && rows != 0){
            if(chessBoard[rows+1][cols-2] != pieceColor){      ///lower left move
                moves[counter][0] = letters[cols-2];
                moves[counter][1] = (8-rows-1) + '0';
                counter++;
            }
            if(chessBoard[rows-1][cols-2] != pieceColor){      ///upper left move
                moves[counter][0] = letters[cols-2];
                moves[counter][1] = (8-rows+1) + '0';
                counter++;

            }
        }
    }

    if(rows != 0 && rows != 7){
        if(chessBoard[rows-1][cols] != pieceColor){      ///up move
            moves[counter][0] = letters[cols];
            moves[counter][1] = (8-rows+1) + '0';
            counter++;
        }
        if(chessBoard[rows+1][cols] != pieceColor){      ///down move
            moves[counter][0] = letters[cols];
            moves[counter][1] = (8-rows-1) + '0';
            counter++;

        }
    }

}
void pawn(char (*chessBoard)[16], char pieceColor, int rows, int cols,char (*moves)[2]){
    char letters[16] = {"AABBCCDDEEFFGGHH"};
    int counter = 0;

    int firstMove;

    if(pieceColor == 'W'){
        if(rows == 6){
            firstMove = 1;
        }else
            firstMove = 0;
        if(firstMove){
            if(chessBoard[rows-2][cols] == '0'){
                moves[counter][0] = letters[cols];
                moves[counter][1] = (8-rows+2) + '0';
                counter++;
            }

        }
        if(rows != 0){
            if(chessBoard[rows-1][cols] == '0'){
                moves[counter][0] = letters[cols];
                moves[counter][1] = (8-rows+1) + '0';
                counter++;
            }

            if(cols != 14){
                if(chessBoard[rows-1][cols+2] == 'B'){
                    moves[counter][0] = letters[cols+2];
                    moves[counter][1] = (8-rows+1) + '0';
                    counter++;

                }
            }
            if(chessBoard[rows-1][cols-2] == 'B'){
                moves[counter][0] = letters[cols-2];
                moves[counter][1] = (8-rows+1) + '0';
                counter++;
            }
        }
    }
    else if(pieceColor == 'B'){
        if(rows == 1){
            firstMove = 1;
        }else
            firstMove = 0;
        if(firstMove){
            if(chessBoard[rows+2][cols] == '0'){
                moves[counter][0] = letters[cols];
                moves[counter][1] = (8-rows-2) + '0';
                counter++;
            }

        }
        if(rows != 0){
            if(chessBoard[rows+1][cols] == '0'){
                moves[counter][0] = letters[cols];
                moves[counter][1] = (8-rows-1) + '0';
                counter++;
            }



            if(cols != 14){
                if(chessBoard[rows+1][cols+2] == 'W'){
                    moves[counter][0] = letters[cols+2];
                    moves[counter][1] = (8-rows-1) + '0';
                    counter++;
                }
            }
            if(chessBoard[rows+1][cols-2] == 'W'){
                moves[counter][0] = letters[cols-2];
                moves[counter][1] = (8-rows-1) + '0';
                counter++;
            }
        }
    }
}
void rock(char (*chessBoard)[16], char pieceColor, int rows, int cols,char (*moves)[2]){
    char letters[16] = {"AABBCCDDEEFFGGHH"};
    int counter = 0;
    for(int i = cols+2;i <= 14; i+=2){     //right
        if(chessBoard[rows][i] != pieceColor){
            if(chessBoard[rows][i] != pieceColor && chessBoard[rows][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-rows) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-rows) + '0';
            counter++;
        }else{
            break;
        }
    }

    for(int i = cols-2;i >= 0; i-=2){     //left
        if(chessBoard[rows][i] != pieceColor){
            if(chessBoard[rows][i] != pieceColor && chessBoard[rows][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-rows) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-rows) + '0';
            counter++;
        }else{
            break;
        }
    }
    for(int i = rows+1;i <= 7; i++){     //down
        if(chessBoard[i][cols] != pieceColor){
            if(chessBoard[i][cols] != pieceColor && chessBoard[i][cols] != '0'){
                printf("5-  %c%d\n",letters[cols],8-i);
                moves[counter][0] = letters[cols];
                moves[counter][1] = (8-i) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[cols];
            moves[counter][1] = (8-i) + '0';
            counter++;
        }else{
            break;
        }
    }

    for(int i = rows-1;i >= 0; i--){     //up
        if(chessBoard[i][cols] != pieceColor){
            if(chessBoard[i][cols] != pieceColor && chessBoard[i][cols] != '0'){
                moves[counter][0] = letters[cols];
                moves[counter][1] = (8-i) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[cols];
            moves[counter][1] = (8-i) + '0';
            counter++;
        }else{
            break;
        }
    }
}
void bishop(char (*chessBoard)[16], char pieceColor, int rows, int cols,char (*moves)[2]){
    char letters[16] = {"AABBCCDDEEFFGGHH"};
    int counter = 0;
    for(int i = cols+2,j = rows-1;i <= 14 && j >= 0; i+=2,j--){              //upper right
        if(chessBoard[j][i] != pieceColor){
            if(chessBoard[j][i] != pieceColor && chessBoard[j][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-j) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-j) + '0';
            counter++;
        }else{
            break;
        }
    }
    for(int i = cols-2,j = rows-1;i >= 0 && j >= 0; i-=2,j--){              //upper left
        if(chessBoard[j][i] != pieceColor){
            if(chessBoard[j][i] != pieceColor && chessBoard[j][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-j) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-j) + '0';
            counter++;
        }else{
            break;
        }
    }
    for(int i = cols+2,j = rows+1;i <= 14 && j <= 7; i+=2,j++){              //lower right
        if(chessBoard[j][i] != pieceColor){
            if(chessBoard[j][i] != pieceColor && chessBoard[j][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-j) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-j) + '0';
            counter++;
        }else{
            break;
        }
    }
    for(int i = cols-2,j = rows+1;i >= 0 && j <= 7; i-=2,j++){              //lower left
        if(chessBoard[j][i] != pieceColor){
            if(chessBoard[j][i] != pieceColor && chessBoard[j][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-j) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-j) + '0';
            counter++;
        }else{
            break;
        }
    }
}
void queen(char (*chessBoard)[16], char pieceColor, int rows, int cols,char (*moves)[2]){
    char letters[16] = {"AABBCCDDEEFFGGHH"};
    int counter = 0;
    for(int i = cols+2;i <= 14; i+=2){     //right
        if(chessBoard[rows][i] != pieceColor){
            if(chessBoard[rows][i] != pieceColor && chessBoard[rows][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-rows) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-rows) + '0';
            counter++;
        }else{
            break;
        }
    }

    for(int i = cols-2;i >= 0; i-=2){     //left
        if(chessBoard[rows][i] != pieceColor){
            if(chessBoard[rows][i] != pieceColor && chessBoard[rows][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-rows) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-rows) + '0';
            counter++;
        }else{
            break;
        }
    }
    for(int i = rows+1;i <= 7; i++){     //down
        if(chessBoard[i][cols] != pieceColor){
            if(chessBoard[i][cols] != pieceColor && chessBoard[i][cols] != '0'){
                printf("5-  %c%d\n",letters[cols],8-i);
                moves[counter][0] = letters[cols];
                moves[counter][1] = (8-i) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[cols];
            moves[counter][1] = (8-i) + '0';
            counter++;
        }else{
            break;
        }
    }

    for(int i = rows-1;i >= 0; i--){     //up
        if(chessBoard[i][cols] != pieceColor){
            if(chessBoard[i][cols] != pieceColor && chessBoard[i][cols] != '0'){
                moves[counter][0] = letters[cols];
                moves[counter][1] = (8-i) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[cols];
            moves[counter][1] = (8-i) + '0';
            counter++;
        }else{
            break;
        }
    }

    for(int i = cols+2,j = rows-1;i <= 14 && j >= 0; i+=2,j--){              //upper right
        if(chessBoard[j][i] != pieceColor){
            if(chessBoard[j][i] != pieceColor && chessBoard[j][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-j) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-j) + '0';
            counter++;
        }else{
            break;
        }
    }
    for(int i = cols-2,j = rows-1;i >= 0 && j >= 0; i-=2,j--){              //upper left
        if(chessBoard[j][i] != pieceColor){
            if(chessBoard[j][i] != pieceColor && chessBoard[j][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-j) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-j) + '0';
            counter++;
        }else{
            break;
        }
    }
    for(int i = cols+2,j = rows+1;i <= 14 && j <= 7; i+=2,j++){              //lower right
        if(chessBoard[j][i] != pieceColor){
            if(chessBoard[j][i] != pieceColor && chessBoard[j][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-j) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-j) + '0';
            counter++;
        }else{
            break;
        }
    }
    for(int i = cols-2,j = rows+1;i >= 0 && j <= 7; i-=2,j++){              //lower left
        if(chessBoard[j][i] != pieceColor){
            if(chessBoard[j][i] != pieceColor && chessBoard[j][i] != '0'){
                moves[counter][0] = letters[i];
                moves[counter][1] = (8-j) + '0';
                counter++;
                break;
            }
            moves[counter][0] = letters[i];
            moves[counter][1] = (8-j) + '0';
            counter++;
        }else{
            break;
        }
    }

}

int knowPiece(char (*array)[16],char letter, int number,char whiteOrBlack,char (*moves)[2]){

    char letterList[8] = {"ABCDEFGH"};
    letter = toupper(letter);

    int rows = 8-number;
    int columns = 0;

    for(int i=0;i<8;i++){
        if(letter == letterList[i]){
            columns=i*2;
            break;
        }
        if(i == 7){
            printf("Error!(Wrong choice)\n");
            return 0;
        }
    }

    char stoneColor = array[rows][columns];

    if(stoneColor != 'W' && stoneColor != 'B'){
        printf("Error (StoneColor)!\n");
        return 0;
    }

    if (stoneColor != whiteOrBlack){
        printf("Error! (WhiteOrBlack)\n");
        return 0;
    }

    char stoneType = array[rows][columns+1];
    if (stoneType == 'R'){
        rock(array,stoneColor,rows,columns,moves);
    }
    else if (stoneType == 'K'){
        knight(array,stoneColor,rows,columns,moves);
    }
    else if (stoneType == 'B'){
        bishop(array,stoneColor,rows,columns,moves);
    }
    else if (stoneType == 'Q'){
        queen(array,stoneColor,rows,columns,moves);
    }
    else if (stoneType == 'G'){
        king(array,stoneColor,rows,columns,moves);
    }
    else if (stoneType == 'P'){
        pawn(array,stoneColor,rows,columns,moves);
    }
    return 1;
}

void stoneMove(char (*chessBoard)[16], char letter, int number, char newLetter, int newNumber,char whiteOrBlack){
    char letterList[8] = {"ABCDEFGH"};
    letter = toupper(letter);
    newLetter = toupper(newLetter);

    int oldRows = 8-number;
    int oldColumns = 0;

    int newRows = 8-newNumber;
    int newColumns = 0;

    for(int i=0;i<8;i++){
        if(letter == letterList[i]){
            oldColumns=i*2;
        }
        if(newLetter == letterList[i]){
            newColumns=i*2;
        }
    }
    system("cls");
    if (chessBoard[newRows][newColumns]== '0' && chessBoard[newRows][newColumns+1]=='0'){
        chessBoard[newRows][newColumns]=chessBoard[oldRows][oldColumns];
        chessBoard[newRows][newColumns+1] = chessBoard[oldRows][oldColumns+1];
        chessBoard[oldRows][oldColumns] = '0';
        chessBoard[oldRows][oldColumns+1] =  '0';

    }
    else{
        //eliminate
        capturing(chessBoard, oldRows,oldColumns,newRows,newColumns,whiteOrBlack,letter,number);
        chessBoard[newRows][newColumns]=chessBoard[oldRows][oldColumns];
        chessBoard[newRows][newColumns+1] = chessBoard[oldRows][oldColumns+1];
        chessBoard[oldRows][oldColumns] = '0';
        chessBoard[oldRows][oldColumns+1] =  '0';

    }
}

void capturing(char (*chessBoard)[16], int oldRow, int oldCol, int newRow, int newCol, char whiteOrBlack,char letter, int number){
    char pieceColor = chessBoard[oldRow][oldCol];
    char stoneType = chessBoard[oldRow][oldCol+1];
    char pieceColor2 = chessBoard[newRow][newCol];
    char stoneType2 =chessBoard[newRow][newCol+1];
    char newColLetter;
    int newRowNum = 8-newRow;
    printf("\n\n%d\n\n",newCol);
    char letterList[8] = {"ABCDEFGH"};
    for (int i=0;i<8;i++){
        if (i == newCol/2){
            newColLetter = letterList[i];
        }
    }
    system("cls");
    printf("\n\nElimination: %c%d %c%c --> %c%d %c%c\n\n\n\a", letter,number, pieceColor,stoneType,newColLetter, newRowNum, pieceColor2,stoneType2);
}

void fillByX(char (*moves)[2]){
    for (int i=0;i<30;i++){
        moves[i][0] = 'X';
        moves[i][1] = 'X';
    }
}

int main(){
    int count=0;
    char chessBoard[8][16] =     {"BRBKBBBQBGBBBKBR",
                                  "BPBPBPBPBPBPBPBP",
                                  "0000000000000000",
                                  "0000000000000000",
                                  "0000000000000000",
                                  "0000000000000000",
                                  "WPWPWPWPWPWPWPWP",
                                  "WRWKWBWQWGWBWKWR"};
    while(1){
        char whiteOrBlack;
        char fullWB[6] = "black";
        if(count %2==0){
            whiteOrBlack ='W';
            strcpy(fullWB, "white");
        }
        else{
            whiteOrBlack ='B';
        }

        printBoard(chessBoard);

        char letter;
        int number;
        char emt;
        char (*moves)[2] = malloc(30 * 2 * sizeof(char));

        fillByX(moves);
        select:

            printf("Timer: %d\n",count/2);
            printf("Select a square for %s : ",fullWB);
            scanf("%c%d",&letter,&number);
            letter = toupper(letter);
            int possibleMoves =0;

            if(!knowPiece(chessBoard,letter,number,whiteOrBlack,moves)){
                scanf("%c",&emt);
                goto select;
            }

            for (int i=0;i<=30;i++){
                if (moves[i][0]=='X' || moves[i][1] =='X'){
                    break;
                }
                printf("%d) %c%c \n",i+1,moves[i][0],moves[i][1]);
                possibleMoves++;
            }
            if(possibleMoves==0){
                scanf("%c",&emt);
                printf("Error! (No possible moves)\n");
                fillByX(moves);
                goto select;
            }
            printf("\n");

            int selection;
            printf("Select a move for %s : ",fullWB);
            scanf("%d",&selection);
            if (selection > possibleMoves){
                scanf("%c",&emt);
                printf("Error! (Wrong choice)\n");
                fillByX(moves);
                goto select;
            }
            char charNewMoves = moves[selection-1][1];
            printf("%c%c\n",moves[selection-1][0],charNewMoves);
            int newMoves = charNewMoves - '0';

            stoneMove(chessBoard,letter,number,moves[selection-1][0],newMoves,whiteOrBlack);
            fillByX(moves);

        count++;
        scanf("%c",&emt);
    }
    return 0;
}
