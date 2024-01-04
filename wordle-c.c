#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_WORDS 50
#define MAX_LETTERS 5
#define MAX_GUESS 5
typedef struct Guess
{
  // Use MAX_WORDS to avoid potential buffer overflow(as long as user doesn't
  // input more than 50 letters)
  char letter[MAX_WORDS];
  int result[MAX_WORDS];
  // * 0 = not guessed, 1 = correct, 2 = incorrect. 3 = misplaced
} Guess;
void printEmpty(void);
void printGuess(char *letter, int *result);
char *generateAnswer(void);
char* CheckGuess(char* guess, char *answer);
char *toUpper(char *letter, int length);
void green();
void red();
void yellow();
void reset();

int main(void)
{
  Guess guesses[MAX_LETTERS];
  // For Debug/Init Use
  char emptyGuess[] = "     ";
  int emptyResult[] = {0, 0, 0, 0, 0};

  // Generate answer
  char *answer = generateAnswer();

  // Initialize guesses
  for (int i = 0; i < MAX_GUESS; i++)
  {
    strcpy(guesses[i].letter, emptyGuess);
    memcpy(guesses[i].result, emptyResult, sizeof(emptyResult));
  }

  int globalIterate = 0;
  int didGameWon = 0;
  while (globalIterate != MAX_GUESS)
  {
    char currentGuess[5];
    printEmpty();
    printf("----------------------wordle-clone--------------------\n");
    printf("|Red = \033[1;31mIncorrect\033[1;0m Green = "
           "\033[1;32mCorrect\033[1;0m Yellow = \033[1;33mMisplaced\033[1;0m  "
           "|\n");
    for (int i = 0; i < MAX_GUESS; i++)
    {
      // Debug Purpose Pls Ignore
      // int debugResult[] = {3, 1, 1, 3, 1};
      // printGuess(guesses[i].letter, debugResult);
      // End of Debug

      printGuess(guesses[i].letter, guesses[i].result);
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


    memcpy(guesses[globalIterate].result, CheckGuess(capGuess, answer), MAX_LETTERS * sizeof(int));


    // printf("%s",pushArray);
    strcpy(guesses[globalIterate].letter, capGuess);
    int isCorrect = 1;
    for (int i = 0; i < MAX_LETTERS; i++)
    {
      if (capGuess[i] != answer[i])
      {
        isCorrect = 0;
        break;
      }
    }
    if (isCorrect)
    {
      didGameWon = 1;
      break;
    }
    // Handle early win and exit

    globalIterate++;
  }
  // Print again for the fifth time (due to the way the loop is structured)
  printEmpty();
  printf("----------------------wordle-clone--------------------\n");
  printf(
      "|Red = \033[1;31mIncorrect\033[1;0m Green = \033[1;32mCorrect\033[1;0m "
      "Yellow = \033[1;33mMisplaced\033[1;0m  |\n");
  for (int i = 0; i < MAX_GUESS; i++)
  {
    printGuess(guesses[i].letter, guesses[i].result);
  }
  printf("------------------------------------------------------\n");
  // Handle win lose condition
  // If win print congratulation and exit
  // If lost print answer and exit
  if (didGameWon)
  {
    printf("Congrats u won the game ( ˶ˆᗜˆ˵ )\n");
  }
  else
  {
    printf("Sorry you can't guess the letter is it too hard? ˙◠˙ the answer was: %s\n", answer);
  }

  return 0;
}

char* CheckGuess(char* guess, char *answer)
// * return 0 = not guessed, 1 = correct, 2 = incorrect. 3 = misplaced
{
  int* result = malloc(sizeof(int) * MAX_LETTERS);
  int* answerGuessed = malloc(sizeof(int) * MAX_LETTERS);
  for(int i = 0; i < MAX_LETTERS; i++){
    answerGuessed[i] = 0;
  }
  for (int i = 0; i < MAX_LETTERS; i++)
  {
    if (guess[i] == answer[i] && answerGuessed[i] == 0)
    {
      result[i] = 1;
      answerGuessed[i] = 1;
    }
    else {
      result[i] = 2;
    }
  }
  for (int i = 0; i < MAX_LETTERS; i++)
  {
    if (guess[i] != answer[i])
    {
      for (int j = 0; j < MAX_LETTERS; j++)
      {
        if (guess[i] == answer[j] && answerGuessed[j] == 0)
        {
          result[i] = 3;
          answerGuessed[j] = 1;
          break;
        }
        else
        {
          result[i] = 2;
        }
      }
    }
  }

  return result; // incorrect
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
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
         "\n\n\n\n\n\n\n\n\n\n\n\n");
}

void printGuess(char *letter, int *result)
{

  printf("|                       ");
  for (int i = 0; i < MAX_LETTERS; i++)
  {

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
  printf("                        |\n");
}
void red() { printf("\033[1;31m"); }

void green() { printf("\033[1;32m"); }

void yellow() { printf("\033[1;33m"); }

void reset() { printf("\033[0m"); }