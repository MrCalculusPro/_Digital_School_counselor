#include <stdio.h>

void academics();
void sports();
void social_life();
void family_issues();

int main() {
    char ans;
    int category;

    printf("Good day! Welcome! I'm your digital school counselor.\n");

    while (1) {
        printf("\nIs there a problem I can help you with? (Enter 'y' for yes, 'n' for no, 'q' to quit): ");
        scanf(" %c", &ans);

        if (ans == 'q') {
            printf("Goodbye! Remember, you can always come back for more questionable advice!\n");
            break;
        } else if (ans == 'n') {
            printf("Alright! Keep struggling on your own then.\n");
        } else if (ans == 'y') {
            printf("\nWhich category does your problem fall under?\n");
            printf("1: Academics\n2: Sports\n3: Social life and Relationships\n4: Family issues\n");
            printf("Enter your choice (1-4): ");
            scanf("%d", &category);

            switch (category) {
                case 1:
                    academics();
                    break;
                case 2:
                    sports();
                    break;
                case 3:
                    social_life();
                    break;
                case 4:
                    family_issues();
                    break;
                default:
                    printf("Invalid choice. Even I can't help with that!\n");
            }
        } else {
            printf("Invalid input. Try again, but with some common sense this time.\n");
        }
    }

    return 0;
}

void academics() {
    int choice;
    printf("\nWhich of the following best describes your problem?\n");
    printf("1: Low academic performance\n2: Difficulties in understanding concepts\n");
    printf("3: Distractions in class\n4: Time management issues\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Simple solution: Just cheat! It's faster and less stressful.\n");
            break;
        case 2:
            printf("Don't worry about understanding. Just memorize random words and hope for the best!\n");
            break;
        case 3:
            printf("Sit in the back of the class and take a nap. No distractions if you're asleep!\n");
            break;
        case 4:
            printf("Forget planning. Just wing it. Deadlines are just suggestions!\n");
            break;
        default:
            printf("Invalid choice! Try again, maybe use a calculator next time.\n");
    }
}

void sports() {
    int choice;
    printf("\nWhich of the following best describes your problem?\n");
    printf("1: Inconsistency in practice\n2: Low team spirit\n3: Difficulty taking orders from the coach\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Practice is overrated. Just show up for the matches and hope for a miracle.\n");
            break;
        case 2:
            printf("If your team loses, just blame everyone else. That always works!\n");
            break;
        case 3:
            printf("Coaches? Ignore them. You know better than they do anyway.\n");
            break;
        default:
            printf("Invalid choice! Are you even reading the options?\n");
    }
}

void social_life() {
    int choice;
    printf("\nWhich of the following best describes your problem?\n");
    printf("1: Talking to my crush\n2: Making good friends\n3: Maintaining friendships\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Just stare at them awkwardly until they notice you. Works every time!\n");
            break;
        case 2:
            printf("Bribe people with food. Friendship is just a transaction anyway.\n");
            break;
        case 3:
            printf("Forget maintaining friendships. If they leave, they weren’t worth it!\n");
            break;
        default:
            printf("Invalid choice! Maybe you're just socially doomed.\n");
    }
}

void family_issues() {
    int choice;
    printf("\nWhich of the following best describes your problem?\n");
    printf("1: Balancing chores and school\n2: Improving relationships with family\n3: Resolving family conflicts\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Just ignore the chores. Eventually, someone else will do them!\n");
            break;
        case 2:
            printf("Be as loud as possible. That way, they won’t ignore you!\n");
            break;
        case 3:
            printf("If there’s a fight, just take sides and make it worse. Chaos is fun!\n");
            break;
        default:
            printf("Invalid choice! Maybe just move out and start over?\n");
    }
}