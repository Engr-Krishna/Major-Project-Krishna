The Personal Health Dashboard is a simple, menu-driven C program designed to help users track their daily health activities. It allows users to create or log into a profile, store their basic health information, and monitor daily calories, steps, weight, and BMI. The program uses file handling to save user data, so progress is retained across sessions.
This project demonstrates the use of structures, functions, conditional logic, loops, and file operations in C.


--------------------------------------------------------------------------------

## 🧠 Concepts Demonstrated
File operations (fopen, fwrite, fread, remove, rename)

Pointer-based string manipulation

Dynamic memory management

Modular programming using header files


--------------------------------------------------------------------------------


## ✨ Features

User signup/login using Name + Contact

Track calories consumed

Track daily steps

Update weight

Compute BMI & category

Auto-calculate BMR based on gender, age, height, activity

Smart suggestion system

Persistent data stored in user.text

--------------------------------------------------------------------------------

## 🛠️ Compilation & Execution Instructions

Follow the steps below to compile and run the project:

1. Navigate to the project folder

```bash
cd Personal-Health-Dashboard
```

3. Compile the program

If your project uses a single main.c file:

```bash
gcc main.c -o Tracker
```



If your project has multiple files (example: main.c, utils.c):

```bash
gcc main.c utils.c -o Tracker
```

3. Run the application

```bash
./Tracker
```

--------------------------------------------------------------------------------
