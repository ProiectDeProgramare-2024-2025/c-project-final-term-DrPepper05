#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 15

// ANSI color codes
#define RESET "\033[0m"
#define DARKGRAY "\033[90m"
#define LIGHTBLUE "\033[94m"
#define GREEN "\033[32m"
#define RED "\033[31m"

// struct for quiz
typedef struct
{
    char question[256];
    char choices[4][256];
    int correctAnswer; // index (0-3) of the correct answer
} Question;

Question questions[MAX_QUESTIONS];

typedef struct
{
    char name[100];
    float score;
} Record;

void initQuestions();
void playGame();
void viewLeaderboard();
void viewGameHistory();

void initQuestions()
{
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].choices[0], "Berlin");
    strcpy(questions[0].choices[1], "London");
    strcpy(questions[0].choices[2], "Paris");
    strcpy(questions[0].choices[3], "Madrid");
    questions[0].correctAnswer = 2;

    strcpy(questions[1].question, "What is 2 + 2?");
    strcpy(questions[1].choices[0], "3");
    strcpy(questions[1].choices[1], "4");
    strcpy(questions[1].choices[2], "5");
    strcpy(questions[1].choices[3], "6");
    questions[1].correctAnswer = 1;

    strcpy(questions[2].question, "Which planet is known as the Red Planet?");
    strcpy(questions[2].choices[0], "Earth");
    strcpy(questions[2].choices[1], "Mars");
    strcpy(questions[2].choices[2], "Jupiter");
    strcpy(questions[2].choices[3], "Saturn");
    questions[2].correctAnswer = 1;

    strcpy(questions[3].question, "Who wrote 'Romeo and Juliet'?");
    strcpy(questions[3].choices[0], "Charles Dickens");
    strcpy(questions[3].choices[1], "William Shakespeare");
    strcpy(questions[3].choices[2], "Mark Twain");
    strcpy(questions[3].choices[3], "Leo Tolstoy");
    questions[3].correctAnswer = 1;

    strcpy(questions[4].question, "What is the boiling point of water at sea level?");
    strcpy(questions[4].choices[0], "90°C");
    strcpy(questions[4].choices[1], "100°C");
    strcpy(questions[4].choices[2], "110°C");
    strcpy(questions[4].choices[3], "120°C");
    questions[4].correctAnswer = 1;

    strcpy(questions[5].question, "What is the largest ocean on Earth?");
    strcpy(questions[5].choices[0], "Atlantic Ocean");
    strcpy(questions[5].choices[1], "Indian Ocean");
    strcpy(questions[5].choices[2], "Arctic Ocean");
    strcpy(questions[5].choices[3], "Pacific Ocean");
    questions[5].correctAnswer = 3;

    strcpy(questions[6].question, "Which country hosted the 2016 Summer Olympics?");
    strcpy(questions[6].choices[0], "China");
    strcpy(questions[6].choices[1], "Brazil");
    strcpy(questions[6].choices[2], "UK");
    strcpy(questions[6].choices[3], "Russia");
    questions[6].correctAnswer = 1;

    strcpy(questions[7].question, "What is the chemical symbol for Gold?");
    strcpy(questions[7].choices[0], "Au");
    strcpy(questions[7].choices[1], "Ag");
    strcpy(questions[7].choices[2], "Gd");
    strcpy(questions[7].choices[3], "Go");
    questions[7].correctAnswer = 0;

    strcpy(questions[8].question, "What is the square root of 64?");
    strcpy(questions[8].choices[0], "6");
    strcpy(questions[8].choices[1], "7");
    strcpy(questions[8].choices[2], "8");
    strcpy(questions[8].choices[3], "9");
    questions[8].correctAnswer = 2;

    strcpy(questions[9].question, "Which animal is known as the 'King of the Jungle'?");
    strcpy(questions[9].choices[0], "Elephant");
    strcpy(questions[9].choices[1], "Lion");
    strcpy(questions[9].choices[2], "Tiger");
    strcpy(questions[9].choices[3], "Giraffe");
    questions[9].correctAnswer = 1;

    strcpy(questions[10].question, "What gas do plants absorb from the atmosphere?");
    strcpy(questions[10].choices[0], "Oxygen");
    strcpy(questions[10].choices[1], "Hydrogen");
    strcpy(questions[10].choices[2], "Carbon Dioxide");
    strcpy(questions[10].choices[3], "Nitrogen");
    questions[10].correctAnswer = 2;

    strcpy(questions[11].question, "What is the hardest natural substance on Earth?");
    strcpy(questions[11].choices[0], "Gold");
    strcpy(questions[11].choices[1], "Diamond");
    strcpy(questions[11].choices[2], "Iron");
    strcpy(questions[11].choices[3], "Platinum");
    questions[11].correctAnswer = 1;

    strcpy(questions[12].question, "Which continent is the Sahara Desert located on?");
    strcpy(questions[12].choices[0], "Asia");
    strcpy(questions[12].choices[1], "Africa");
    strcpy(questions[12].choices[2], "Australia");
    strcpy(questions[12].choices[3], "South America");
    questions[12].correctAnswer = 1;

    strcpy(questions[13].question, "How many sides does a hexagon have?");
    strcpy(questions[13].choices[0], "5");
    strcpy(questions[13].choices[1], "6");
    strcpy(questions[13].choices[2], "7");
    strcpy(questions[13].choices[3], "8");
    questions[13].correctAnswer = 1;

    strcpy(questions[14].question, "Which instrument has keys, pedals, and strings?");
    strcpy(questions[14].choices[0], "Guitar");
    strcpy(questions[14].choices[1], "Piano");
    strcpy(questions[14].choices[2], "Violin");
    strcpy(questions[14].choices[3], "Drum");
    questions[14].correctAnswer = 1;
}

void playGame()
{
    float totalScore = 0.0f;
    char answer[10];
    int lifelineUsed;

    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        system("clear");
        lifelineUsed = 0;
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        printf("A. %s\n", questions[i].choices[0]);
        printf("B. %s\n", questions[i].choices[1]);
        printf("C. %s\n", questions[i].choices[2]);
        printf("D. %s\n", questions[i].choices[3]);

        printf("Enter your answer (A, B, C, D) or type '50' for 50/50 lifeline: ");
        scanf("%s", answer);

        if (strcmp(answer, "50") == 0)
        {
            lifelineUsed = 1;
            int incorrectOptions[3], idx = 0;
            for (int j = 0; j < 4; j++)
                if (j != questions[i].correctAnswer)
                    incorrectOptions[idx++] = j;
            int kept = incorrectOptions[rand() % 3];

            printf("\n50/50 Lifeline used. Remaining options:\n");
            char let;
            switch (questions[i].correctAnswer)
            {
            case 0:
                let = 'A';
                break;
            case 1:
                let = 'B';
                break;
            case 2:
                let = 'C';
                break;
            case 3:
                let = 'D';
                break;
            }
            printf("%c. %s\n", let, questions[i].choices[questions[i].correctAnswer]);

            switch (kept)
            {
            case 0:
                let = 'A';
                break;
            case 1:
                let = 'B';
                break;
            case 2:
                let = 'C';
                break;
            case 3:
                let = 'D';
                break;
            }
            printf("%c. %s\n", let, questions[i].choices[kept]);

            printf("Enter your answer (letter corresponding to the remaining options): ");
            scanf("%s", answer);
        }

        int answerIndex = -1;
        if (answer[0] == 'A' || answer[0] == 'a')
            answerIndex = 0;
        else if (answer[0] == 'B' || answer[0] == 'b')
            answerIndex = 1;
        else if (answer[0] == 'C' || answer[0] == 'c')
            answerIndex = 2;
        else if (answer[0] == 'D' || answer[0] == 'd')
            answerIndex = 3;

        if (answerIndex < 0)
        {
            printf("Invalid input. Game over.\n");
            break;
        }

        if (answerIndex == questions[i].correctAnswer)
        {
            totalScore += lifelineUsed ? 0.5f : 1.0f;
            printf(GREEN "Correct!\n" RESET);
        }
        else
        {
            char let;
            switch (questions[i].correctAnswer)
            {
            case 0:
                let = 'A';
                break;
            case 1:
                let = 'B';
                break;
            case 2:
                let = 'C';
                break;
            case 3:
                let = 'D';
                break;
            }
            printf(RED "Incorrect. The correct answer was %c. %s\n" RESET,
                   let, questions[i].choices[questions[i].correctAnswer]);
            break;
        }

        getchar(); // consume newline
        printf("Press Enter to continue...");
        getchar();
    }

    system("clear");
    printf("\nGame over! Your total score: %.1f out of %d\n",
           totalScore, MAX_QUESTIONS);

    Record rec;
    printf("Enter your name: ");
    scanf("%s", rec.name);
    rec.score = totalScore;

    FILE *fp = fopen("game_history.txt", "a");
    if (fp)
    {
        fprintf(fp, "%s %.1f\n", rec.name, rec.score);
        fclose(fp);
    }
    else
    {
        printf("Error saving game history.\n");
    }
}

int compareRecords(const void *a, const void *b)
{
    const Record *r1 = a;
    const Record *r2 = b;
    if (r2->score > r1->score)
        return 1;
    if (r2->score < r1->score)
        return -1;
    return 0;
}

void viewLeaderboard()
{
    getchar();
    FILE *fp = fopen("game_history.txt", "r");
    if (!fp)
    {
        printf("\nNo game history found.\n");
        return;
    }

    Record records[1000];
    int count = 0;
    while (count < 1000 &&
           fscanf(fp, "%s %f", records[count].name, &records[count].score) == 2)
    {
        count++;
    }
    fclose(fp);

    if (count == 0)
    {
        printf("\nNo records to display.\n");
        return;
    }

    qsort(records, count, sizeof(Record), compareRecords);

    printf("\nLeaderboard:\n");
    printf("%-20s %s\n", "Name", "Score");
    for (int i = 0; i < count; i++)
    {
        printf("%-20s %.1f\n", records[i].name, records[i].score);
    }

    printf("\nPress Enter to return to menu...");
    getchar();
}

void viewGameHistory()
{
    getchar();
    char searchName[100];
    printf("\nEnter the name to view game history: ");
    scanf("%s", searchName);

    system("clear");
    FILE *fp = fopen("game_history.txt", "r");
    if (!fp)
    {
        printf("No game history found.\n");
        return;
    }

    int found = 0;
    printf("\nGame history for %s:\n", searchName);
    while (1)
    {
        char name[100];
        float score;
        if (fscanf(fp, "%s %f", name, &score) != 2)
            break;
        if (strcmp(name, searchName) == 0)
        {
            printf("Score: %.1f\n", score);
            found = 1;
        }
    }
    fclose(fp);

    if (!found)
    {
        printf("No records found for %s.\n", searchName);
    }

    printf("\nPress Enter to return to menu...");
    getchar();
    getchar();
}

int main()
{
    srand((unsigned)time(NULL));
    initQuestions();

    int choice;
    do
    {
        system("clear");
        // Menu header in dark gray
        printf(DARKGRAY "\n--- Quiz Game Menu ---\n" RESET);
        // Options: label in dark gray, text in light blue
        printf(DARKGRAY "1. " LIGHTBLUE "Play Game\n" RESET);
        printf(DARKGRAY "2. " LIGHTBLUE "View Leaderboard\n" RESET);
        printf(DARKGRAY "3. " LIGHTBLUE "View Game History\n" RESET);
        printf(DARKGRAY "4. " LIGHTBLUE "Exit\n" RESET);
        // Prompt: static in dark gray, keyword in light blue
        printf(DARKGRAY "Enter your " LIGHTBLUE "choice" DARKGRAY ": " RESET);

        if (scanf("%d", &choice) != 1)
        {
            choice = 0;
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        switch (choice)
        {
        case 1:
            system("clear");
            playGame();
            break;
        case 2:
            system("clear");
            viewLeaderboard();
            break;
        case 3:
            system("clear");
            viewGameHistory();
            break;
        case 4:
            system("clear");
            printf("Exiting the game. Goodbye!\n");
            break;
        default:
            system("clear");
            printf("Invalid choice. Please try again.\n");
            printf("Press Enter to continue...");
            getchar();
            getchar();
        }
    } while (choice != 4);

    return 0;
}
