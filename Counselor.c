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

    printf("\n\t🧑‍🏫 Welcome to your Digital School Counselor! 🏫\n");

    while (1) {
        printf("\nCan I help you? (y = Yes, n = No, q = Quit): ");
        scanf(" %c", &ans);
        getchar();  // Flush input buffer

        if (ans == 'q') {
            printf("\nGoodbye! Remember, I'm always here for questionable advice. 😎\n");
            break;
        } else if (ans == 'n') {
            printf("\nAlright! Keep struggling on your own. 🫠\n");
        } else if (ans == 'y') {
            printf("\nWhich category does your problem fall under?\n");
            printf("1️⃣ Academics\n2️⃣ Sports\n3️⃣ Social life & Relationships\n4️⃣ Family issues\n");
            printf("Enter your choice (1-4): ");
            scanf("%d", &category);
            getchar();

            switch (category) {
                case 1: academics(); break;
                case 2: sports(); break;
                case 3: social_life(); break;
                case 4: family_issues(); break;
                default: printf("\nInvalid choice! Try again. 🤨\n");
            }
        } else {
            printf("\nInvalid input! Try again. 🤦‍♂️\n");
        }
    }
    return 0;
}

void academics() {
    int choice;
    printf("\nWhat academic problem are you facing?\n");
    printf("1️⃣ Low academic performance\n2️⃣ Difficulties understanding concepts\n3️⃣ Distractions in class\n4️⃣ Time management issues\n5️⃣ Need help creating a timetable?\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1: printf("\nSolution: Just cheat! It's faster. 🤫\n"); break;
        case 2: printf("\nDon't understand? Just memorize random words and hope for the best! 😆\n"); break;
        case 3: printf("\nSit at the back and nap. No distractions if you're asleep! 😴\n"); break;
        case 4: printf("\nForget planning. Just wing it! 🚀\n"); break;
        case 5: TIMETABLE_CREATOR(); break;
        default: printf("\nInvalid choice! Maybe use a calculator next time? 😜\n");
    }
}

void sports() {
    printf("\nWhich sports-related issue do you have?\n");
    printf("1️⃣ Inconsistent practice\n2️⃣ Low team spirit\n3️⃣ Difficulty following coach's orders\n");
    printf("Enter your choice (1-3): ");
    int choice;
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1: printf("\nPractice is overrated. Just show up and hope for a miracle! 🤞\n"); break;
        case 2: printf("\nIf your team loses, blame everyone else. 😏\n"); break;
        case 3: printf("\nIgnore the coach. You obviously know better! 🙄\n"); break;
        default: printf("\nInvalid choice! Are you even reading the options? 🤔\n");
    }
}

void social_life() {
    printf("\nWhat's your social issue?\n");
    printf("1️⃣ Talking to your crush\n2️⃣ Making friends\n3️⃣ Maintaining friendships\n");
    printf("Enter your choice (1-3): ");
    int choice;
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1: printf("\nJust stare awkwardly until they notice you. 🫣\n"); break;
        case 2: printf("\nBribe people with food. Friendship is just a transaction! 🍕\n"); break;
        case 3: printf("\nIf they leave, they weren’t worth it! 🤷\n"); break;
        default: printf("\nInvalid choice! Maybe you're just socially doomed. 🫠\n");
    }
}

void family_issues() {
    printf("\nWhat family issue do you have?\n");
    printf("1️⃣ Balancing chores and school\n2️⃣ Improving relationships with family\n3️⃣ Resolving family conflicts\n");
    printf("Enter your choice (1-3): ");
    int choice;
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1: printf("\nIgnore chores. Someone else will do them. 🤡\n"); break;
        case 2: printf("\nBe as loud as possible so they won't ignore you! 🎤\n"); break;
        case 3: printf("\nPick a side and make things worse. Chaos is fun! 😈\n"); break;
        default: printf("\nInvalid choice! Just move out? 🏃💨\n");
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
