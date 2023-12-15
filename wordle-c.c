#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_WORDS 50
#define MAX_LETTERS 5
#define MAX_GUESS 5
typedef struct Guess
{
  // Use MAX_WORDS to avoid potential buffer overflow(as long as user doesn't input more than 50 letters)
  char letter[MAX_WORDS];
  int result[MAX_WORDS];
  // * 0 = not guessed, 1 = correct, 2 = incorrect. 3 = misplaced
} Guess;
void printEmpty(void);
void printGuess(char *letter, int *result, int try);
char *generateAnswer(void);
int CheckGuess(char guess, char *answer);
char *toUpper(char *letter, int length);
void green();
void red();
void yellow();
void reset();

int main(void)
{
  Guess guesses[MAX_LETTERS];
  // For Debug/Init Use
  char emptyGuess[] = "A    ";
  int emptyResult[] = {0, 0, 0, 0, 0};
  int debugResult[] = {3, 1, 1, 3, 1};
  strcpy(guesses[0].letter, "hello");

  // Generate answer
  char *answer = generateAnswer();

  // Initialize guesses
  for (int i = 0; i < MAX_GUESS; i++)
  {
    strcpy(guesses[i].letter, emptyGuess);
    memcpy(guesses[i].result, emptyResult, sizeof(emptyResult));
  }

  int globalIterate = 0;
  while (globalIterate != MAX_GUESS)
  {
    char currentGuess[5];
    printEmpty();
    printf("%s\n",answer);
    printf("----------------------wordle-clone--------------------\n");
    printf("|Red = \033[1;31mIncorrect\033[1;0m Green = \033[1;32mCorrect\033[1;0m Yellow = \033[1;33mMisplaced\033[1;0m  |\n");
    for (int i = 0; i < MAX_GUESS; i++)
    {
      printGuess(guesses[i].letter, debugResult, i + 1);
    }
    printf("------------------------------------------------------\n");
    printf("Guess a 5 letter word: ");
    scanf("%s", currentGuess);
    char capGuess[MAX_WORDS];
    // Capitalize All Letters
    for (int i = 0; i < MAX_LETTERS; i++)
    {
      if (currentGuess[i] >= 'a' && currentGuess[i] <= 'z')
      {
        // 32 is the difference between upper and lower case on ASCII table
        capGuess[i] = currentGuess[i] - 32;
      }
      else
      {
        capGuess[i] = currentGuess[i];
      }
    }
    // for (int i = 0; i < MAX_LETTERS; i++)
    // {
    //   guesses[globalIterate].result[i] = CheckGuess(capGuess[i], answer);
    // }
    strcpy(guesses[globalIterate].letter, capGuess);
    // Handle early win and exit

    globalIterate++;
  }
  // Print again for the fifth time (due to the way the loop is structured)
  printEmpty();
  printf("----------------------wordle-clone--------------------\n");
  printf("|Red = \033[1;31mIncorrect\033[1;0m Green = \033[1;32mCorrect\033[1;0m Yellow = \033[1;33mMisplaced\033[1;0m  |\n");
  for (int i = 0; i < MAX_GUESS; i++)
  {
    printGuess(guesses[i].letter, guesses[i].result, i + 1);
  }
  printf("------------------------------------------------------\n");
  // Handle win lose condition
  // If win print congratulation and exit
  // If lost print answer and exit

  return 0;
}

int CheckGuess(char guess, char *answer)
{
  // * return 0 = not guessed, 1 = correct, 2 = incorrect. 3 = misplaced
  return 0;
}

char *generateAnswer(void)
{
  char *words[MAX_WORDS] = {
      "AGENT",
      "WORLD",
      "ABOUT",
      "HEART",
      "WATER",
      "SIXTY",
      "BOARD",
      "MONTH",
      "MUSIC",
      "PARTY",
      "PIANO",
      "MOUTH",
      "WOMAN",
      "SUGAR",
      "AMBER",
      "DREAM",
      "LAUGH",
      "TIGER",
      "EARTH",
      "MONEY",
      "WORDS",
      "SMILE",
      "LEMON",
      "SOUTH",
      "AFTER",
      "STONE",
      "THING",
      "LIGHT",
      "STORY",
      "POWER",
      "TODAY",
      "RANGE",
      "PEARL",
      "VENOM",
      "PROXY",
      "ROUND",
      "HOVER",
      "CANDY",
      "ABOVE",
      "PHONE",
      "OTHER",
      "SMART",
      "BLACK",
      "MAGIC",
      "FRUIT",
      "RADIO",
      "ROYAL",
      "HONEY",
      "FLAKE",
      "SOUND",
  };
  srand(time(NULL));
  int random = rand() % MAX_WORDS;
  return words[random];
}

void printEmpty(void)
{
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void printGuess(char *letter, int *result, int try)
{

  printf("|                     ");
  for (int i = 1; i < MAX_LETTERS; i++)
  {
    
    // printf("%d",result[i]);
    if (result[i] == 1)
    { // Correct (Green)
      green();
      printf("%c", letter[i]);
      reset();
    }
    else if (result[i] == 2)
    { // Incorrect (Red)
      red();
      printf("%c", letter[i]);
      reset();
    }
    else if (result[i] == 3)
    { // Misplaced (Yellow)
      yellow();
      printf("%c", letter[i]);
      reset();
    }
    else
    {
      printf("%c", letter[i]);
    }
  }
  printf("                   |\n");
}
void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}