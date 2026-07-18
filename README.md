
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
 
You can spam this to toggle TUI mode in and out anytime. (Way more stable than brute-forcing `gdb --tui` directly on Cygwin/mintty ngl)

---
## Pls help I confused using VIM 😭🙏

<img src="https://media1.tenor.com/m/FGmeK_2r6jUAAAAd/denia-wuwa.gif" alt="denia confused" width="600"/>

Going in to folder (if I forgot where my file where for some reason)  
`cd /cygdrive/e/KMITL/Year_2/Physic_Com/It_all_C/quiz`  

```bash
# ==============================================================================
# 💻 Basic Command Survival Guide
# ==============================================================================

# [Command]                   [Shortcut]    [What it actually does]
ls                            -             # check files in current dir
cd path_file/                 -             # go in to file / folder
vim file_name.c               -             # create or edit file
gcc -g file.c -o file.exe     -             # compile file 
gdb --tui file_name           -             # debug mode (UI might break lol)

# --- GDB Mode ---
info break                    i b           # check break point info
info local                    i loc         # show local variables (let me see what values I got rn)
next                          n             # go to next line (Step OVER functions, skip the boring details)
step                          s             # dive INTO the function line-by-line
run                           r             # it just run man what did u expect man???
break [line]                  b [line]      # R u for real man... (Code stops BEFORE the line u input, e.g., input 15 stops at 14)
```

---

<img src="https://media1.tenor.com/m/9Wv5g8uNqHgAAAAd/denia-wuthering-waves.gif" alt="denia loading" width="400"/>

## 📂 World Map (Project Structure)

This is where things were.

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
