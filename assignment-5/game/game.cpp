#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Globals
int score;
int action[21];
char in[20];

int user(void)
{
    int i = 0;
    while (i != 1 && i != 2)
    {
        printf("We are at %-2d, add 1 or 2 ? ", score);
        fgets(in, 10, stdin);
        i = atoi(in);
    };
    return (i);
}

void dynamic_programming(void)
{
    double gamma = 0.9;

    double value[21];
    value[20] = -10;
    value[19] = 10;
    value[18] = 10;

    action[20] = 0;
    action[19] = 1;
    action[18] = 2;

    for (int i = 17; i >= 0; i--)
    {
        double add_one = fmin(value[i + 2], value[i + 3]);
        double add_two = fmin(value[i + 3], value[i + 4]);

        value[i] = gamma * fmax(add_one, add_two);
        action[i] = add_one > add_two ? 1 : 2;
    }

    printf("%-5s | %-10s | %s\n", "Score", "Value", "Action");
    for (int i = 0; i <= 20; i++)
    {
        printf("%-5d | %-10f | %d\n", i, value[i], action[i]);
    }
}

int computer(void)
{
    printf("We are at %-2d Computer adds %d \n", score, action[score]);
    return action[score];
}

int computer2(void)
{
    if (score % 3 == 1)
        return (1);
    if (score % 3 == 0)
        return (2);
    else
        return (rand() % 2 + 1);
}

int main(void)
{

    dynamic_programming();

    srand(time(NULL));
    int i;
    printf(" Who says first 20 \n \n");
    score = 0;
    i = 0;
    while (i != 1 && i != 2)
    {
        printf("Who goes first: you=1 computer=2 ? ");
        fgets(in, 10, stdin);
        i = atoi(in);
    };
    if (i == 2)
        score = computer();
    while (score <= 20)
    {
        score = score + user();
        if (score >= 20)
        {
            printf(" YOU WIN !!\n ");
            break;
        };
        score = score + computer();
        if (score >= 20)
        {
            printf(" I WIN !! \n ");
            break;
        };
    };
    return (0);
};
