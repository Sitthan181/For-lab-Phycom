
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
    scanf("%d", &b);
    scanf("%f", &c);
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

**For-loop** has 3 parts separated by `;` — this is what makes it different from `while`/`do-while` (which need init/update written separately):

| Part | Name | Runs when | What it does |
|---|---|---|---|
| `exp1` | Initialize | Once, at the very start | Set starting value of loop variable (e.g. `i = 5`) |
| `exp2` | Condition | Checked before every loop | Loop keeps running while this stays true |
| `exp3` | Update | After every loop body | Update loop variable (e.g. `i--`) |

```c
for (exp1; exp2; exp3)
{
    statement1;
    statement2;
    ...
}
```

```c
// Ex
#include <stdio.h>
int main() {
    int i;
    for (i = 5; i > 0; i--)
        printf("%d\n", i);
    return 0;
}
```

---

**While-loop** — pre-test loop, checks condition **BEFORE** running. If condition is false from the start, body never runs even once. Init and update gotta be written yourself (easy to forget the update = infinite loop, watch out).

```c
while (expression)
{
    statement1;
    statement2;
    ...
    statementn;
}
```

```c
// Ex
#include <stdio.h>
int main() {
    int i = 1;
    int sum = 0;

    while (i <= 10)
    {
        sum = sum + i;
        i++;
    }

    printf("%d", sum);
    return 0;
}
```

---

**Do-while** — post-test loop, runs the body FIRST then checks condition after. Guarantees at least 1 run even if condition is false from the start. Don't forget the `;` after `while(...)` — that trips people up a lot switching between loop types.

```c
do
{
    statement1;
    statement2;
    ...
    statementn;
} while (expression);
```

```c
// Ex
#include <stdio.h>
int main() {
    int i = 0;
    do {
        printf("%d ", i);   // runs at least once, THEN checks condition
        i++;
    } while (i < 10);
    return 0;
}
```

### Array

You can use `#define SIZE X` where X is any number, and `SIZE` can be renamed to anything — every array size that uses that keyword changes at once when you edit the `#define`.

```c
arrayName[index]      // Accessing array
num[0]                // first index (index 0)
num[3] = 5;           // change num[3] to 5

type arrayName[arraySize];                          // declare array
type arrayName[arraySize] = {value1, value2, ...};  // declare + default values

int inum[9];          // array of int with 9 slots (index 0-8)
float fnum[5];        // array of float with 5 slots
char nname[4];        // array of char with 4 slots

int num[5] = {2, 10, 3, 11, 5};   // normal
int num[5] = {2, 10, 3};          // other than those 3 will be 0 (2,10,3,0,0)
int num[5] = {0};                  // set all to 0
int num[] = {2, 10, 3, 11, 5};    // no size given → max size = input
```

**Two-Dimensional Array**
```c
type arrayName[rows][columns];
int arr[3][4];   // 3 rows, 4 columns = 12 slots total

// accessing Two-Dimensional Array
arr[0][0]  arr[0][1]  arr[0][2]  arr[0][3]
arr[1][0]  arr[1][1]  arr[1][2]  arr[1][3]
arr[2][0]  arr[2][1]  arr[2][2]  arr[2][3]

int arr[3][4] = {{0, 1, 2, 3},
                  {10, 11, 12, 13},
                  {20, 21, 22, 23}}; // assign values

int arr[3][4] = {0};   // clear all to 0
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
