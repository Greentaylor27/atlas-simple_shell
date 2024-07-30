
# Simple Shell

This is a project aimed to rebuild a simple shell. The difference between this shell and one more commonly used "shell" this is built from the ground up by two people. With that in mind this repo is open to anybody that wants it.


## Authors

- [@Taylor Green](https://www.github.com/Greentaylor27)
- [@Tsimmuaj Yang](https://github.com/Jimwall0)


## Deployment

To deploy this project run

```bash
  git clone https://github.com/Greentaylor27/atlas-simple_shell.git
```
after you have cloned the repository run

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
After compilation to run in interactive mode run

```bash
./hsh
```
To run in non-interactive mode run

```bash
./hsh ls
```


## Lessons Learned

One of the biggest challenges we faced in this project were both technical challenges and personal conflicts.

### Technical Challenges

The biggest challenge we faced during this section of the project was memory allocation. The hardest challenge was were to place the mallocs and frees within the program. Another big struggle was implementation and layout of the project.

### Personal Challenges

We both for the most part worked on this project remotely, which isn't easy to do on such a massive project. Another challenge we faced was scheduling conflicts, it was hard with busy schedules to sync up and work on the project together other than the dedicated times we either were at school or set aside to work at home.
## Known Bugs

Currently the most know bug within the program is 

### 1.

Non-interactive mode is not implemented. (We ran out of time, spent probably too much trying to debug interactive mode)

### 2.

The loop is not infinite, it starts the program allows one use then exits unexpectedly. From during some research I believe that it is a memory issue somewhere within the code.
