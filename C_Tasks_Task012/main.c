/**
*   Task 012
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char counter = 1;
char option1[8] = "New";
char option2[8] = "Display";
char option3[8] = "Exit";
char underScore = '_';
char *current = option1;

typedef enum{
    up = 0 ,
    down,
    first,
    last
}direction;

void counterControl(direction d);
void printMenu(void);

int main()
{
    char userInput;

    printMenu();

    while(1)
    {
        userInput = getch();
        switch(userInput)
        {
            case 27:
                //printf("escape pressed\n");
                return 0;
            case 72:
                //printf("up arrow pressed\n");
                counterControl(up);
                break;
            case 80:
                //printf("down arrow pressed\n");
                counterControl(down);
                break;
            case 71:
                //printf("Home pressed\n");
                counterControl(first);
                break;
            case 79:
                //printf("End pressed\n");
                counterControl(last);
                break;
            case 13:
                //printf("Enter pressed\n");
                if(current == option3)
                    return 0;
                system("cls");
                printf("%s",current);
                userInput = getch();
                return 0;
        }

        printMenu();

    }
    return 0;
}
void counterControl(direction d){
    switch(d)
    {
        case up:
            if(counter == 1)
                counter = 3;
            else
                counter--;
            break;

        case down:
            if(counter == 3)
                counter = 1;
            else
                counter++;
            break;

        case first:
            counter = 1;
            current = option1;
            break;

        case last:
            counter = 3;
            current = option3;
            break;

        default:
            counter = 1;
    }
}

void printMenu(void){
    system("cls");
    switch(counter)
    {
    case 1:
        current = option1;
        printf("%s%c\n",option1,underScore);
        printf("%s\n"  ,option2);
        printf("%s\n"  ,option3);
        break;
    case 2:
        current = option2;
        printf("%s\n"  ,option1);
        printf("%s%c\n",option2,underScore);
        printf("%s\n"  ,option3);
        break;
    case 3:
        current = option3;
        printf("%s\n"  ,option1);
        printf("%s\n"  ,option2);
        printf("%s%c\n",option3,underScore);
        break;
    default:
        printf("error\n");
    }
}
