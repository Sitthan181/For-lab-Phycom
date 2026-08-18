
# (￣へ￣) C Lab Phycom

<img src="https://media1.tenor.com/m/geSFdExOq-wAAAAd/stdio-stdioh.gif" alt="animated bold text" width="400"/>

This repository contains the source code for my **PHYSICAL COMPUTING (PHYCOM)** labs at the Faculty of Information Technology (KMITL) so I don't have to use Google drive.

---
## How to creat and debug vim file.C001

<img src="https://media1.tenor.com/m/4qIz-GOR9nMAAAAC/denia-denia-wuwa.gif" alt="denia shaking" width="400"/>

```bash
# 1. Creat/Edit vim file.c
vim main.c
 
# 2. Compile with flag -g (it gcc -g + filename.c + -o + filename that gonna be .exe)
gcc -g main.c -o main
 
# 3. Open gdb
gdb main
 
# 3.5 For Just Run the code
./ main
 
# **NOTE!! main stand for file name (Can be change)
```
 
### Entering TUI (It just IDE UI but in vim)
 
```
Ctrl + x  followed by  a
```
 
You can spam this to toggle TUI mode in-aNd-out anytime. (Way more stable than brute-forcing `gdb --tui` directly on Cygwin/mintty ngl)

---
## Pls help I confused using VIM 😭🙏

<img src="https://media1.tenor.com/m/FGmeK_2r6jUAAAAd/denia-wuwa.gif" alt="denia confused" width="600"/>

Going in to folder (if I forgot where my file where for some reason)  
`cd /cygdrive/e/KMITL/Year_2/Physic_Com/It_all_C/quiz`  

## ⌨️ How to input things properly without crying

For input entire line  
`%[^\n]`  
Ex :  
```c
    char Z[101];
    scanf(" %[^\n]", Z);
    printf("%s", Z);
```

When inputting, if it's not string (`%s`) need to use `&`. if it IS a string ya need to give it max size it can hold. using `[]`  
```c
    char a[*how much bytes it can hold];
    int b;
    float c;
    scanf("%s", a);
    scanf("%c", a);       // for 1 char
    scanf("%d", &b);
    scanf("%f", &c);
    printf("%c\n", a);    // for 1 char
    printf("%s\n", a);
    printf("%d %f", b, c);
```  

## 💻 Basic Command Survival Guide

```bash
# [Command]                   [Shortcut]    [What it actually does]
ls                            -             # check files in current dir
cd path_file/                 -             # go in to file / folder
vim file_name.c               -             # create or edit file
gcc -g file.c -o file.exe     -             # compile file 
gdb --tui file_name           -             # debug mode (Just go use gdb file_name -> ctrl + x -> a | it alot ezer)

# --- GDB Mode ---
info break                    i b           # check break point info
info local                    i loc         # show local variables (let me see what values I got rn)
next                          n             # go to next line (Step OVER functions, skip the boring details)
step                          s             # dive INTO the function line-by-line
run                           r             # it just run man what did u expect man???
print                         p             # it print but shoter
break [line]                  b [line]      # Code stops BEFORE the line u input, e.g., input 15 stops at 14
```

## 🔁 For-loop | Array and Function Structure

This is Ex and reminder of how to write all of this

### For-Loop, While-Loop, Do-While

```c
// ==========================================
// 1. FOR LOOP (The "I know how many times" loop)
// Syntax | for (Start; Condition; Update){do smth}
// ==========================================
for (int i = 5; i > 0; i--) {
    // Runs exactly 5 times
}

// ==========================================
// 2. WHILE LOOP (The "Check first, run later" loop)
// Syntax while (con-d) {do smth + Update}
// ==========================================
int w = 1;
while (w <= 10) {
    // If condition is false, this never runs.
    w++; // ⚠️ FORGET THIS -> INFINITE LOOP IS CALLING ⚠️
}

// ==========================================
// 3. DO-WHILE LOOP (The "Run first, ask later" loop)
// Syntax do{smth} while(con-d); 
// ==========================================
int d = 0;
do {
    // Guarantees at least 1 run no matter what
    d++;
} while (d < 10); // ⚠️ DONT FORGET THE ';' HERE ⚠️
```

### Array

You can use `#define SIZE X` where X is any number, and `SIZE` can be renamed to anything — every array size that uses that keyword changes at once when you edit the `#define`.

```c
#define SIZE 10 // Change here = changes everywhere

// --- 1D Array ---
int num[5] = {2, 10, 3, 11, 5}; 
int num2[5] = {2, 10, 3};       // The rest becomes 0 -> {2,10,3,0,0}
int zero[5] = {0};              // Quick way to clear all to 0
num[0] = 99;                    // Change first slot

// --- 2D Array (Rows x Cols) ---
int arr[3][4] = {0}; // 3 rows, 4 cols. All cleared to 0.

// Ex: Standard way to loop 2D Array without brain dmg
int r, c;
for (r = 0; r < 3; r++) {
    for (c = 0; c < 4; c++) {
        scanf("%d", &arr[r][c]);    // Input
        printf("%5d ", arr[r][c]);  // Output
    }
    printf("\n"); // New line for new row
}
```

**Ex Use case — input then print entire array**
```c
#include <stdio.h>
#define ROWS 3
#define COLS 4

int main() {
    int arr[ROWS][COLS];
    int r, c;

    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            scanf("%d", &arr[r][c]);

    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++)
            printf("%5d ", arr[r][c]);
        printf("\n");   // new line when finished with each row
    }

    return 0;
}
```

### Function Structure

**Note** do "Function Prototype" first so code won't error

which is smth like this
```c
// ==========================================
// Function Syntax
// ReturnType functionName(ParameterType name);
// ==========================================
//Ex:
#include <stdio.h>

// 1. PROTOTYPES (Declare them here!)
int getNum(void);       // Takes nothing, returns an int
int sqr(int x);         // Takes an int, returns an int
void printOne(int x);   // Takes an int, returns NOTHING (void)

// 2. MAIN FUNCTION
int main() {
    int a = getNum();
    int b = sqr(a);
    printOne(b);
    return 0;
}

// 3. THE ACTUAL FUNCTIONS (Write what they do down here)
int getNum(void) {
    int numIn;
    scanf("%d", &numIn);
    return numIn;
}

int sqr(int x) {
    return x * x;
}

void printOne(int x) {
    printf("The value is: %d\n", x);
    // No return needed because the type is 'void'
}
```

---

<img src="https://media1.tenor.com/m/9Wv5g8uNqHgAAAAd/denia-wuthering-waves.gif" alt="denia loading" width="400"/>

## 📂 World Map (Project Structure)

This is where things were. also some.md were not in place cause it my mark for what quiz/lab does, what I learned

```text
For-lab-Phycom/
├── 📂 .vscode/               <-- I don't even know why it here...
├── 📂 It_all_C/              <-- [Source] The raw C code & config
│   ├── 📁 lab02/         
│   │   └── ...
│   ├── 📁 lab03/         
│   │   └── ...
│   ├── 📁 output/         
│   │   └── ...           <-- [Compiled] .exe file
│   ├── 📁 quiz/         
│   │   └── ...
│   ├── 📄 readme(for how to GDB).md
│   │   └── ...
│   └── 📁 lab0X/         <-- Future labs
└── 📂 Raptor/                <--[Source] The raw Raptor file
```

---
## U think there more? Nah bro there not thing down here!

<img src="https://media1.tenor.com/m/58EUqZ4oTRkAAAAd/denia-denia-wuwa.gif" alt="denia haha" width="400"/>

---
## IDK what to wrote next, might add later, Thx

<img src="https://media1.tenor.com/m/XOzaTur0OVIAAAAd/out-stairs.gif" alt="I'm out" width="400"/>
