#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void clearInputBuffer(){
  while(getchar() != '\n');
}
bool checkIfIntegerInRange(int* n){
 if (scanf("%d", n) == 1){
      if (*n >=1 && *n <=5){
        return true;
      } else{
        printf("The number is not in range.Try again\n");
        clearInputBuffer();
        return false;
    }
    } else{
      printf("Please enter a valid number\n");
      // Clearing the input buffer
      clearInputBuffer();
      return false;

    }
}


bool playGame(int number){
    //Genereate random number between 1 and 5
    int random_number = (rand() % 5) + 1;
    if(random_number == number){
      printf("You guess it correct\n");
      return true;
    } else{
      printf("oops! the number was %d\n", random_number);
      return false;
    }
}

void updateScoreAndLives(bool* correctGuess, int* score, int* lives){
  if(*correctGuess== true){
      *score += 1;
      // If the user has less than 5 lives only increase the live
      if(*lives < 5){
        *lives += 1;
      }
    } else{
      *score -= 1;
      *lives -= 1;
    }
}

bool hasRemainingLives(int lives){
  if (lives <= 0){
    printf("Game Over !!! You have no lives left.\n");
    return false;
  }
  return true;
}

int main(){
  srand(time(NULL));
  int guess;
  int score = 0;
  int lives = 5;
  bool correctGuess, continuePlaying;

  printf("Welcome to the Guess the Number Game!\n");
  printf("Guess a number between 1 and 5. Each correct guess earns you a point.\n");
  printf("Wrong guesses deduct a point and lose a life. Start with 5 lives.\n");

  do{
    printf("Guess the number between 1 and 5\n");
    if(!checkIfIntegerInRange(&guess)){
      continue;
    }
    correctGuess = playGame(guess);
    updateScoreAndLives(&correctGuess, &score, &lives);

    printf("\nCurrent Score: %d | Lives Remaining: %d\n", score, lives);

    if (!hasRemainingLives(lives)) break;
    
    printf("Play again?(y/n)\n");
    char choice;
    scanf("%c", &choice);
    clearInputBuffer();
    continuePlaying = (choice == 'y');
    } while(continuePlaying);
    printf("Thanks for playing! Your final score is %d.\n", score);
    return 0;

  }
  
  