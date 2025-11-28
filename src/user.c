#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "utils.h"

//  SIGNUP 
void signup() {
    struct User user;
    printf("\n========= Fitness Tracker =========\n");

    printf("Enter Name: ");
    scanf("%s", user.name);

    printf("Enter Contact Number: ");
    scanf("%s", user.contact);

    if (userexists(user.name, user.contact, &user)) {
        printf("\nWelcome back, %s! Login successful.\n", user.name);
        mainmenu(user);
        return;
    }

    printf("\nNew user detected. Please complete your profile.\n");

    printf("Enter Gender (Male/Female): ");
    scanf("%s", user.gender);

    printf("Enter Age: ");
    scanf("%d", &user.age);

    printf("Enter Height (cm): ");
    scanf("%f", &user.height);

    printf("Enter Current Weight (kg): ");
    scanf("%f", &user.weight);
    user.currentweight = user.weight;

    printf("\nSelect Goal (Gain/Maintain/Lose): ");
    scanf("%s", user.goal);

    printf("Select Activity Level (VeryLight/Light/Active): ");
    scanf("%s", user.activity);

    printf("Enter Goal Steps per Day: ");
    scanf("%d", &user.goalSteps);

    printf("Enter Goal Weight: ");
    scanf("%f", &user.goalWeight);

    printf("Choose Weekly Rate (0.25 or 0.5 kg/week): ");
    scanf("%f", &user.ratePerWeek);

    user.calorieintake = 0;
    user.stepswalked = 0;

    saveuser(user);

    printf("\nSignup successful! Welcome, %s.\n", user.name);
    mainmenu(user);
}

//  CHECK IF USER EXISTS 
int userexists(char name[], char contact[], struct User *u) {
    FILE *fp = fopen("user.text", "r");
    if (!fp) return 0;

    struct User temp;

    while (fscanf(fp, "%[^,],%[^,],%[^,],%d,%f,%f,%[^,],%[^,],%d,%f,%f,%f,%d,%f\n",
                  temp.name, temp.contact, temp.gender, &temp.age, &temp.height, &temp.weight,
                  temp.goal, temp.activity, &temp.goalSteps, &temp.goalWeight,
                  &temp.ratePerWeek, &temp.calorieintake, &temp.stepswalked,
                  &temp.currentweight) == 14) {

        if (strcmp(temp.name, name) == 0 && strcmp(temp.contact, contact) == 0) {
            *u = temp;
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

//  SAVE USER DATA 
void saveuser(struct User u) {
    FILE *fp = fopen("user.text", "a");
    if (!fp) {
        printf("Error saving user data!\n");
        return;
    }

    fprintf(fp, "%s,%s,%s,%d,%.2f,%.2f,%s,%s,%d,%.2f,%.2f,%.2f,%d,%.2f\n",
            u.name, u.contact, u.gender, u.age, u.height, u.weight,
            u.goal, u.activity, u.goalSteps, u.goalWeight,
            u.ratePerWeek, u.calorieintake, u.stepswalked,
            u.currentweight);

    fclose(fp);
}

//  MAIN MENU 
void mainmenu(struct User user) {
    int choice;
    float calorieNeed = calculateBMR(user);

    float calorieintake = user.calorieintake;
    int stepswalked = user.stepswalked;

    do {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Calories\n2. Weight\n3. Steps\n4. BMI\n5. Suggestions\n6. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                calories(&calorieintake, calorieNeed);
                user.calorieintake = calorieintake;
                break;

            case 2:
                weight(&user);
                break;

            case 3:
                steps(&stepswalked, user.goalSteps);
                user.stepswalked = stepswalked;
                break;

            case 4:
                bmi(user);
                break;

            case 5:
                suggestions(user, calorieNeed, calorieintake, stepswalked);
                break;

            case 6:
                printf("Logged out.\n");
                saveuser(user);
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);
}

