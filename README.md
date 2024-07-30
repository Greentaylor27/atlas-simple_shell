
# Simple Shell

This is a project aimed to rebuild a simple shell. The difference between this shell and one more commonly used "shell" this is built from the ground up by two people. With that in mind this repo is open to anybody that wants it. This program has only been test with the intergrated ls function. To exit the program, type "exit" to exit the shell.


## Authors

- [@Taylor Green](https://www.github.com/Greentaylor27)
- [@Tsimmuaj Yan](https://github.com/Jimwall0)

## Flowchart

![Imgur](https://i.imgur.com/SQLra8e.jpeg)

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

## Examples
With file path<br>
/bin/ls<br><br>
without file path<br>
ls

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
There is a error that props up from valgrind saying there is a write of 1 byte. This is most propably from concatanation 
