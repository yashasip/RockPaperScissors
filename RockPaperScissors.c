// ---------------- ROCK PAPER SCISSORS ------------------
// Game begins when player enters his name
// The Player then selects the move he wants to play

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// global variable declaration
char player_name[20];
int score1, score2, c, in, i;

void setup() // initial setup and player name data
{
    printf("Enter Player Name:\n");
    scanf("%s", player_name);
    score1 = 0;
    score2 = 0;
}
void input() // input of player & computer's play
{
    printf("\nPlayer Name: %s\n1. Rock\n2. Paper\n3. Scissors\nChoice Number: ", player_name);
    scanf("%d", &in);

    if (in > 3)
    {
        printf("Invalid Play!\n");
        input();
    }
    // decrement
    in -= 1;

    // random value generator
    srand(time(NULL));
    c = rand() % 3;
}

char *choice(char d) // player's choice
{
    switch (d)
    {
    case 0:
        return "Rock\n";
    case 1:
        return "Paper\n";
    case 2:
        return "Scissors\n";
    default:
        return "\0";
    }
}

void result(int res) // round result
{
    if (res == 1)
    {
        printf("%s wins the round\n", player_name);
        score1++;
    }
    else
    {
        printf("Computer wins the round\n");
        score2++;
    }
}

void logic() // game run logic
{
    if (in == c) // when both play same
    {
        printf("Round Tied\n");
    }
    else // when both plays are different
    {
        switch (in) // input switched
        {
        case 0: // when player plays rock
            if (c == 1)
                result(0); // if loses
            else
                result(1); // if wins
            break;

        case 1: // player plays paper
            if (c == 2)
                result(0);
            else
                result(1);
            break;

        case 2: // player plays scissors
            if (c == 0)
                result(0);
            else
                result(1);
            break;
        }
    }
}

void draw() // score,player's play display
{
    printf("%s Plays: %sComputer Plays: %s\n", player_name, choice(in), choice(c));
    logic();
    printf("%s Score: %d\nComputer Score: %d", player_name, score1, score2);
}

int main()
{
    setup();
    do
    {
        input();
        draw();
    } while (score2 != 3 && score1 != 3);

    if (score2 == 3) // display winner of game
    {
        printf("\nComputer wins the game\n");
    }
    else
    {
        printf("\n\n%s wins the game\n", player_name);
    }
    return 0;
}
