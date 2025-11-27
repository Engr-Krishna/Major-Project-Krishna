#ifndef UTILS_H
#define UTILS_H

#include "user.h"

// Function declarations
void signup();
int userexists(char name[], char contact[], struct User *u);
void saveuser(struct User u);
float calculateBMR(struct User u);
void mainmenu(struct User user);
void calories(float *calorieintake, float calorieNeed);
void steps(int *stepswalked, int goalSteps);
void weight(struct User *u);
void bmi(struct User u);
void suggestions(struct User u, float calorieNeed, float calorieintake, int stepswalked);

#endif
