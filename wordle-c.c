#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 5

typedef struct Guess{
    char letter[5];
    int result[5];
    // * 0 = not guessed, 1 = correct, 2 = incorrect. 3 = misplaced
}Guess;
void printEmpty(void); 
void printScreen(Guess* guesses);
void printGuess(char* letter,int* result, int try);
char* generateAnswer(void);
int CheckGuess(char result, char answer);

int main(void) {
  Guess guesses[5];
  char emptyGuess[] = "    ";
  char* answer = generateAnswer();
  int GameEnded = 0;
  strcpy(guesses[0].letter, emptyGuess);
  while(GameEnded != 1){
    printEmpty();
    printf("-----------wordle-clone---------\n");

  }
  
  
  
  
  return 0;
  
}

char* generateAnswer(void){
  char* words[MAX_WORDS] = {"AGENT","WORLD","ABOUT","HEART","WATER","SIXTY","BOARD","MONTH","MUSIC","PARTY","PIANO","MOUTH","WOMAN","SUGAR","AMBER","DREAM","LAUGH","TIGER","EARTH","MONEY","WORDS","SMILE","LEMON","SOUTH","AFTER","STONE","THING","LIGHT","STORY","POWER","TODAY","RANGE","PEARL","VENOM","PROXY","ROUND","HOVER","CANDY","ABOVE","PHONE","OTHER","SMART","BLACK","MAGIC","FRUIT","RADIO","ROYAL","HONEY","FLAKE","SOUND",};
  srand(time(NULL));
  int random = rand() % MAX_WORDS;
  return words[random];
}

void printEmpty(void) {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void printScreen(Guess* guesses){
  
  printf("|********Guess 1:*     *********|\n");
  printf("|********Guess 2:*     *********|\n");
  printf("|********Guess 3:*     *********|\n");
  printf("|********Guess 4:*     *********|\n");
  printf("|********Guess 5:*     *********|\n");
  
}

void printGuess(char* letter,int* result,int try){
  
    printf("|********Guess %d:*",try);
    for(int i = 0; i < 5; i++){
      
    }
    printf("*********|\n");
}