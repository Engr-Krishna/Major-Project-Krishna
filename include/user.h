#ifndef USER_H
#define USER_H

struct User {
    char name[50];
    char contact[20];
    char gender[10];
    int age;
    float height;
    float weight;
    char goal[20];      // Gain / Maintain / Lose
    char activity[20];  // VeryLight / Light / Active
    int goalSteps;
    float goalWeight;
    float ratePerWeek;  // 0.25 or 0.5

    // Values updated daily
    float calorieintake;
    int stepswalked;
    float currentweight;
};

#endif
