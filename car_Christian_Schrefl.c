#include "car_Christian_Schrefl.h"
#include <stdio.h>

#define TEST_THINGS

#ifdef TEST_THINGS


int fibonacci(TIMETABLE *current);
int fibonacci(TIMETABLE *current)     //An example function which is calculatin and printing out fibonacht funktions
{
    static unsigned int i = 0, d = 1,c = 0;
    int tmp = i+d;
    printf("Fibonacci nr:%d = %d\n",c++,i);
    i=d;
    d=tmp;
    if(tmp > 1000000000)
        return KILL;
    return KILL;
}
int fact(TIMETABLE *current);
int fact(TIMETABLE *current)
{
    static unsigned int i = 1, c = 1;
    printf("Factorial of %ld = %ld\n",c,i);
    i*=c;
    c++;
    if(i > 1000000000)
        return KILL;        //if the result gets to big the funktion call gets removed from the time table
    return KILL;
}
#endif


int showMenu(TIMETABLE *ins)
{
    char c;
    printf("Select one of the following functions: \n");
    //printf("0: \n");
    printf("1: Auto Hinzuf�gen(fib)\n");
    printf("2: Auto Bearbeiten(fact)\n");
    printf("3: Auto L�schen\n");

    ///Temp Bis Sync
    printf("4: Autos Speichern\n");
    printf("5: Autos Laden\n");
    ///End
    printf("6: Stop\n");

    c = getch();
    switch(c)
    {
    case '1':     ///Add
        insertInTimeTable(ins,fibonacci);
        break;
    case '2':     ///Edit
        insertInTimeTable(ins,fact);
        //insertInTimeTable(ins,);
        break;
    case '3':     ///Delete
        //insertInTimeTable(ins,);
        break;

    case '4':     ///Save
        //insertInTimeTable(ins,);
        break;
    case '5':     ///Load
        //insertInTimeTable(ins,);
        break;
    case '6':     ///Stop
        return KILL;
    default:
        printf("Fehleingabe Bitte Neu versuchen\n");
        showMenu(ins);
        break;
    }
    return KEEP;
}


TIMETABLE* initTimeTable(int (*funktion)(TIMETABLE *TT))
{
    TIMETABLE *TT;
    TT = malloc(sizeof(TIMETABLE));
    TT->funktion = funktion;
    TT->next=TT;
    return TT;
}
TIMETABLE* insertInTimeTable(TIMETABLE *ins, int (*funktion)(TIMETABLE *TT))
{
    TIMETABLE *tmp;
    tmp=ins->next;
    ins->next=malloc(sizeof(TIMETABLE));
    ins->next->funktion = funktion;
    ins->next->next = tmp;
    return ins->next;
}
void loopTimeTable(TIMETABLE *current)
{
    TIMETABLE *insert = current;
    ///Looping through the Time Table
    while(current!=NULL)
    {
        if(current->next->funktion(insert)==KILL) //Deleting the function from list
        {
            TIMETABLE *temp;
            temp=current->next;
            if(current==current->next)
            {
                current=NULL;
                free(temp);
                return;
            }
            else
            {
                current->next=current->next->next;
            }
            free(temp);
        }
        insert=current;
        current=current->next;
    }
}

int count(TIMETABLE *current)
{
    static unsigned int cnt = 0;
    printf("LOOP: %d\n", cnt++);
    return KEEP;
}


void Cryption(char *in, char key, int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        *in^=key;
    }
}
