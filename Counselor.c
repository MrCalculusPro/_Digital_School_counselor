#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>  // for sleep()

#define MAX_STUDY_HOUR 6
#define MAX_NUMBER_DAYS 7
#define MAX_SUBJECT_LENGTH 50

typedef struct TimeTable {
    char subject[MAX_NUMBER_DAYS][MAX_STUDY_HOUR][MAX_SUBJECT_LENGTH];
} TimeTable;

// Days of the week
char days[MAX_NUMBER_DAYS][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

// Fake activities for the messed-up timetable
char fake[MAX_STUDY_HOUR][MAX_SUBJECT_LENGTH] = {"Hangout", "Discuss with crush", "Smoke weed", "Play video games", "Action movies", "Sleep"};

void academics();
void sports();
void social_life();
void family_issues();
void CreateTimetable(TimeTable *timetable);
void displayTimetable(TimeTable timetable);
void InitializeTimetable(TimeTable *timetable);
void RandomizeTimetable(TimeTable *timetable);
void TIMETABLE_CREATOR();

int main() {
    char ans;
    int category;

    printf("\n\t\t 🧑‍🏫 Welcome to your Digital School Counselor! 🏫\n");

    while (1) {
        printf("\n\tCan I help you? (y = Yes, n = No, q = Quit): ");
        scanf(" %c", &ans);
        getchar();  // Flush input buffer

        if (ans == 'q') {
            printf("\n\tGoodbye! Remember, I'm always here for questionable advice.  😎\n");
            break;
        } else if (ans == 'n') {
            printf("\n\tAlright! Keep struggling on your own. 🫠\n");
        } else if (ans == 'y') {
            printf("\n\tWhich category does your problem fall under?\n");
            printf("\t1️⃣ - Academics\n\t 2️⃣ - Sports\n\t 3️⃣ - Social life & Relationships\n\t 4️⃣ - Family issues\n\n");
            printf("\tEnter your choice (1-4): ");
            scanf("%d", &category);
            getchar();

            switch (category) {
                case 1: academics(); break;
                case 2: sports(); break;
                case 3: social_life(); break;
                case 4: family_issues(); break;
                default: printf("\n\tInvalid choice! Try again. 🤨\n");
            }
        } else {
            printf("\n\t\tInvalid input! Try again. 🤦‍♂️\n");
        }
    }
    return 0;
}

void academics() {
    int choice;
    printf("\n\tWhat academic problem are you facing?\n");
    printf("\t\t1️⃣ - Low academic performance\n\t\t2️⃣ - Difficulties understanding concepts\n\t\t3️⃣ - Distractions in class\n\t\t4️⃣ - Time management issues\n\t\t5️⃣ - Need help creating a timetable?\n");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1: printf("\n\t\tSolution: Just cheat! It's faster. 🤫\n"); break;
        case 2: printf("\n\t\tDon't understand? Just memorize random words and hope for the best! 😆\n"); break;
        case 3: printf("\n\t\tSit at the back and nap. No distractions if you're asleep! 😴\n"); break;
        case 4: printf("\n\t\tForget planning. Just wing it! 🚀\n"); break;
        case 5: TIMETABLE_CREATOR(); break;
        default: printf("\n\t\tInvalid choice! Maybe use a calculator next time? 😜\n");
    }
}

void sports() {
    printf("\n\t\tWhich sports-related issue do you have?\n");
    printf("\t\t1️⃣- Inconsistent practice\n\t\t2️⃣ - Low team spirit\n\t\t3️⃣ - Difficulty following coach's orders\n");
    printf("Enter your choice (1-3): ");
    int choice;
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1: printf("\n\t\tPractice is overrated. Just show up and hope for a miracle! 🤞\n"); break;
        case 2: printf("\n\t\tIf your team loses, blame everyone else. 😏\n"); break;
        case 3: printf("\n\t\tIgnore the coach. You obviously know better! 🙄\n"); break;
        default: printf("\n\t\tInvalid choice! Are you even reading the options? 🤔\n");
    }
}

void social_life() {
    printf("\nWhat's your social issue?\n");
    printf("\t\t1️⃣ - Talking to your crush\n\t\t2️⃣ - Making friends\n\t\t3️⃣ - Maintaining friendships\n");
    printf("\nEnter your choice (1-3): ");
    int choice;
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1: printf("\n\t\tJust stare awkwardly until they notice you. 🫣\n"); break;
        case 2: printf("\n\t\tBribe people with food. Friendship is just a transaction! 🍕\n"); break;
        case 3: printf("\n\t\tIf they leave, they weren’t worth it! 🤷\n"); break;
        default: printf("\n\t\tInvalid choice! Maybe you're just socially doomed. 🫠\n");
    }
}

void family_issues() {
    printf("\n\t\tWhat family issue do you have?\n");
    printf("\t\t1️⃣ - Balancing chores and school\n\t\t2️⃣ - Improving relationships with family\n\t\t3️⃣ - Resolving family conflicts\n");
    printf("\nEnter your choice (1-3): ");
    int choice;
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1: printf("\n\t\tIgnore chores. Someone else will do them. 🤡\n"); break;
        case 2: printf("\n\t\tBe as loud as possible so they won't ignore you! 🎤\n"); break;
        case 3: printf("\n\t\tPick a side and make things worse. Chaos is fun! 😈\n"); break;
        default: printf("\n\t\tInvalid choice! Just move out? 🏃💨\n");
    }
}

/* TIMETABLE FUNCTIONS */
void CreateTimetable(TimeTable *timetable) {
    char input[MAX_SUBJECT_LENGTH];
    printf("\n📅 Time Table Creation\n");

    for (int i = 0; i < MAX_NUMBER_DAYS; i++) {
        printf("\n🗓️ Enter subjects for %s (Max %d hours per day)- [ENTER \"done\" if you are satisfied with the subjects  inputed]:\n", days[i], MAX_STUDY_HOUR);
        for (int j = 0; j < MAX_STUDY_HOUR; j++) {
            printf("⏳ Hour %d: ", j + 1);
            fgets(input, MAX_SUBJECT_LENGTH, stdin);
            input[strcspn(input, "\n")] = 0;
            if (strcmp(input, "done") == 0) break;
            strcpy(timetable->subject[i][j], input);
        }
    }
}
void InitializeTimetable(TimeTable *timetable) {
    for (int i = 0; i < MAX_NUMBER_DAYS; i++) {
        for (int j = 0; j < MAX_STUDY_HOUR; j++) {
            strcpy(timetable->subject[i][j], "");
        }
    }
}
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

void RandomizeTimetable(TimeTable *timetable) {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUMBER_DAYS; i++)
        for (int j = 0; j < MAX_STUDY_HOUR; j++)
            strcpy(timetable->subject[i][j], fake[rand() % 6]);
}

void TIMETABLE_CREATOR() {
    TimeTable timetable;
    InitializeTimetable(&timetable);
    CreateTimetable(&timetable);
    displayTimetable(timetable);

    printf("\n⌛ AI Enhancing Timetable... \n");
    sleep(5);
    RandomizeTimetable(&timetable);
    system("clear");
    printf("\n Here's your AI-improved timetable:\n");
    displayTimetable(timetable);
}
