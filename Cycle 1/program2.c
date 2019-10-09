// Rabi Roshan
// CSB S7
// 12170054

#include <stdio.h>

#define TOTAL_STATES 4

#define FINAL_STATES 4

#define ALPHABET_CHARACTERS 3

#define UNKNOWN_SYMBOL_ERR 0

#define UKNOWN_STATE 9

#define NOT_REACHED_FINAL_STATE 1

#define REACHED_FINAL_STATE 2

enum DFA_STATES
{
    q0,
    q1,
    q2,
    q3,
    q4
};
// q4 = unknown state

int Accepted_states[FINAL_STATES] = {q0, q1, q2, q3};

char alphabet[ALPHABET_CHARACTERS] = {'1', '2', '3'};

int Transition_Table[TOTAL_STATES][ALPHABET_CHARACTERS];

int Current_state = q0;

void DefineDFA()
{

    Transition_Table[q0][0] = q1;

    Transition_Table[q0][1] = q2;

    Transition_Table[q0][2] = q3;

    Transition_Table[q1][0] = q1;

    Transition_Table[q1][1] = q2;

    Transition_Table[q1][2] = q3;

    Transition_Table[q2][0] = q4;

    Transition_Table[q2][1] = q2;

    Transition_Table[q2][2] = q3;

    Transition_Table[q3][0] = q4;

    Transition_Table[q3][1] = q4;

    Transition_Table[q3][2] = q3;
}

int DFA(char current_symbol)
{
    int i, pos;

    for (pos = 0; pos < ALPHABET_CHARACTERS; pos++)
        if (current_symbol == alphabet[pos])
            break; //stops if any character other than 1 or 2 or 3

    if (pos == ALPHABET_CHARACTERS)
        return UNKNOWN_SYMBOL_ERR;

    for (i = 0; i < FINAL_STATES; i++)
    {
        Current_state = Transition_Table[Current_state][pos];
        if (Current_state == Accepted_states[i])
            return REACHED_FINAL_STATE;
        else if (Current_state == q4)
            return UKNOWN_STATE;
    }

    return NOT_REACHED_FINAL_STATE;
}

int main(void)
{
    char current_symbol;
    int result;

    DefineDFA(); //Fill transition table

    printf("Enter a string and press enter:");

    while ((current_symbol = getchar()) != '\n')
        if ((result = DFA(current_symbol)) == UNKNOWN_SYMBOL_ERR)
            break;
        else if (result == UKNOWN_STATE)
            break;

    switch (result)
    {
    case UNKNOWN_SYMBOL_ERR:
        printf("Unknown Symbol %c", current_symbol);
        break;
    case NOT_REACHED_FINAL_STATE:
        printf("Not accepted");
        break;
    case REACHED_FINAL_STATE:
        printf("Accepted");
        break;
    case UKNOWN_STATE:
        printf("Unknown State");
        break;
    default:
        printf("Unknown Error");
    }

    printf("\n\n\n");

    return 0;
}