#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//
#define MAX_STUDY_HOUR 6
#define MAX_NUMBER_DAYS 7
#define MAX_SUJECT_LENGTH 50
#define MAX_SUBJECT 10
// TIMETABLE structure should display the timetable with subject studied per day on rows and time reflected per column

typedef struct TimeTable
{
    char subject[MAX_NUMBER_DAYS][MAX_STUDY_HOUR][MAX_SUJECT_LENGTH];

} TimeTable;
// for the days (row)
char days[MAX_NUMBER_DAYS][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

char fake[MAX_STUDY_HOUR][MAX_SUJECT_LENGTH]  = {"Hangout", "Discuss with crush", "Smoke weed", "Play video games", "Action_movies", "Sleep"};

/*CREATING THE TIME TABLE AND FILLING IT WITH VALUES */
void CreateTimetable(TimeTable *timetable)
{
    char input[MAX_SUJECT_LENGTH];
    printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    for (int i = 0; i < MAX_NUMBER_DAYS; i++)
    {

        printf("Allocated the number of hours for the subjects you want to study on %s (you have %d hours of reading per day): \n\n", days[i], MAX_STUDY_HOUR);
        for (int j = 0; j < MAX_STUDY_HOUR; j++)
        {

            printf("Enter subject for hour %d - (Enter \"done\"  if you have no subjects to study for this day): ", j + 1);
            scanf("%s", input);
            if (strcmp("done", input) == 0)
            {
                break;
            }
            // copy to the array
            strcpy(timetable->subject[i][j], input);
        }
    }
}


/*lOGIC TO DISPLAY TIMETABLE*/

void displayTimetable(TimeTable timetable)
{
    printf("=============================================================== Time Table ===============================================================\n");
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|DAY/TIME   |%-17s %-17s %-17s %-17s %-17s %-17s\n", "\tHour 1", "\tHour 2", "\tHour 3", "Hour 4", "\tHour 5", "  Hour 6");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < MAX_NUMBER_DAYS; i++)
    {
        printf("|%-10s: ", days[i]);
        for (int j = 0; j < MAX_STUDY_HOUR; j++)
        {
            printf(" %-18s |", timetable.subject[i][j]);
        }
        printf("\n--------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}
// Intialise the timetable to be N/A in all fields




void InitialiseTimetable(TimeTable *timetable)
{
    for (int i = 0; i < MAX_NUMBER_DAYS; i++)
    {
        for (int j = 0; j < MAX_STUDY_HOUR; j++)
        {
            strcpy(timetable->subject[i][j], "N/A");
        }
    }
}


/*LOGIC TO SPOIL TIME TABLE*/

void RandomizeTimetable(TimeTable *timetable)
{
    srand(time(NULL));

    for (int i = 0; i < MAX_NUMBER_DAYS; i++)
    {

        for (int j = 0; j < MAX_STUDY_HOUR; j++)
        {

            //logic to randomise            
                strcpy(timetable->subject[i][j], fake[rand()%7]);



                 
        }

    }
}



void TIMETABLE_CREATOR()
{
    int choice;
    TimeTable TimeTable;
    printf("\t===============================================Time table Creator ===================================================\n\n");
    printf("\tWelcome to the time table creator assistant, Here to help you create a suitable timetable to sky rocket your performances mate, \n\t\t\tLets start creating your Super timetable: \n\n -(Press ENTER to continue)");
    getchar();
    InitialiseTimetable(&TimeTable);
    CreateTimetable(&TimeTable);
    printf("display time table\n\t [1 for Yes *** 2 for No]: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        displayTimetable(TimeTable);
// create a timer for 3 seconds
// clears the screen and then messes up with the timetable and display trash
        printf("\nI PRESENT THE FULL POWERED BY AI ASSITANT TIMETABLE TO BE THE BEST OF THE BEST ):\n");
        getchar();
        // show some loading option
        RandomizeTimetable(&TimeTable);
        printf("I've ameliorated your timetable to meet your required expectations, hope you like it \n\t\t [PRESS \"ENTER TO CONTINUE\"]\n\n");
        getchar();

        displayTimetable(TimeTable);
    }
    else
    {
        printf("Better off helping yourself\n");
        getchar();
    }



 }

// int num = rand()% (max-min-1) + min;
//srand(time(NULL))

