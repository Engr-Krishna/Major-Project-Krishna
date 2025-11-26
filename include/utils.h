#ifndef UTILS_H
#define UTILS_H

struct User {
    char name[50];
    char contact[20];
    char gender[10];
    int age;
    float height;
    float weight;
    char goal[20];
    char activity[20];
    int goalSteps;
    float goalWeight;
    float ratePerWeek;

    float caloriesTaken;
    int stepsToday;
    float currentWeight;
};

void signupOrLogin();
int userExists(char name[], char contact[], struct User *u);
void saveUser(struct User u);
float calculateBMR(struct User u);
void mainMenu(struct User user);
void calorieSection(float *caloriesTaken, float calorieNeed);
void stepsSection(int *stepsToday, int goalSteps);
void weightSection(struct User *u);
void bmiSection(struct User u);
void suggestionSection(struct User u, float calorieNeed, float caloriesTaken, int stepsToday);

#endif
