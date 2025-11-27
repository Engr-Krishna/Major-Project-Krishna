#include <stdio.h>
#include "utils.h"
#include "user.h"

// ======================= CALCULATE BMR =======================
float calculateBMR(struct User u) {
    float bmr;

    if (strcmp(u.gender, "Male") == 0)
        bmr = 10 * u.currentweight + 6.25 * u.height - 5 * u.age + 5;
    else
        bmr = 10 * u.currentweight + 6.25 * u.height - 5 * u.age - 161;

    if (strcmp(u.activity, "VeryLight") == 0)
        bmr *= 1.2;
    else if (strcmp(u.activity, "Light") == 0)
        bmr *= 1.375;
    else
        bmr *= 1.55;

    if (strcmp(u.goal, "Gain") == 0)
        bmr += 300;
    else if (strcmp(u.goal, "Lose") == 0)
        bmr -= 300;

    return bmr;
}

// ======================= CALORIES =======================
void calories(float *calorieintake, float calorieNeed) {
    int ch;
    float add;

    do {
        printf("\n--- CALORIES SECTION ---\n");
        printf("Daily Calorie Need: %.2f kcal\n", calorieNeed);
        printf("Calories Taken Today: %.2f kcal\n", *calorieintake);

        printf("1. Add Calories\n2. Reset Calories\n3. Back\n");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter calories consumed: ");
            scanf("%f", &add);
            *calorieintake += add;
        }
        else if (ch == 2) {
            *calorieintake = 0;
        }

    } while (ch != 3);
}

// ======================= STEPS =======================
void steps(int *stepswalked, int goalSteps) {
    printf("\n--- STEPS SECTION ---\n");
    printf("Goal Steps: %d\n", goalSteps);

    printf("Enter today's steps: ");
    scanf("%d", stepswalked);
}

// ======================= WEIGHT =======================
void weight(struct User *u) {
    printf("\n--- WEIGHT SECTION ---\n");
    printf("Current Weight: %.2f\n", u->currentweight);
    printf("Goal Weight: %.2f\n", u->goalWeight);

    printf("Enter new weight: ");
    scanf("%f", &u->currentweight);
}

// ======================= BMI =======================
void bmi(struct User u) {
    float bmi = u.currentweight / ((u.height / 100) * (u.height / 100));

    printf("\n--- BMI SECTION ---\n");
    printf("BMI: %.2f\n", bmi);

    if (bmi < 18.5) printf("Underweight\n");
    else if (bmi < 24.9) printf("Normal\n");
    else if (bmi < 29.9) printf("Overweight\n");
    else printf("Obese\n");
}

// ======================= SUGGESTIONS =======================
void suggestions(struct User u, float calorieNeed, float calorieintake, int stepswalked) {
    printf("\n--- SUGGESTIONS ---\n");

    printf("Calories Needed: %.2f kcal\n", calorieNeed);
    printf("Calories Taken: %.2f kcal\n", calorieintake);

    float diff = calorieintake - calorieNeed;

    if (diff > 200) 
        printf("You are in calorie surplus. Reduce intake.\n");
    else if (diff < -200)
        printf("You are in calorie deficit. Eat more.\n");
    else
        printf("Your calories are well balanced.\n");

    if (stepswalked < 7000)
        printf("You walked %d steps. Walk more!\n", stepswalked);
    else
        printf("Good! Steps today: %d\n", stepswalked);
}
