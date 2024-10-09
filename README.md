# So_long
![42](https://img.shields.io/badge/School-42-black?style=flat-square&logo=42)

So_long is a basic 2D game implemented in C as part of a project at 19 (42 Network). The objective is to create a game where a character collects items and escapes from a map. 

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Game Mechanics](#game-mechanics)
- [Graphic Management](#graphic-management)
- [Map Structure](#map-structure)

## Project Overview

The So_long project aims to enhance our skills in computer graphics, window management, and event handling using the MiniLibX graphical library. The game involves collecting collectibles and finding the exit while adhering to the rules outlined.

## Features

- Basic 2D graphics using MiniLibX
- Player movement using keyboard inputs (WASD or arrow keys)
- Collectibles to gather
- Smooth window management
- Error handling for invalid maps

## Requirements

- All requirements for this project are outlined in the project description.
- Language: C, following the Norm.
- Memory Management: All allocated memory must be properly freed, and no memory leaks are tolerated.
- Makefile: The project must include a Makefile with at least the following rules: NAME, all, clean, fclean, re, and bonus if applicable.
- Compilation: Use `cc` with the flags `-Wall`, `-Wextra`, and `-Werror`.
- External functions: open, close, read, write, malloc, free, perror, strerror, exit, math library functions, MiniLibX functions, and your own ft_printf.

## Installation

To build and run So_long, you need a C compiler and `make`. This program uses minilibx and you need to install it to build and run So_long. [Here is how you do that](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

1. Clone the repository:
```
git clone https://github.com/yourusername/so_long.git
```
2. Go in the cloned repository
```
cd so_long
```
3. Build the project:
```
make
```
4. The Makefile includes the following targets:
- `NAME`: Compiles the project
- `all`: Compiles the project
- `clean`: Removes object files
- `fclean`: Removes object files and the executable
- `re`: Rebuilds the project

## Usage

After building the project, you can start it by running:
```
./so_long map.ber
```
This will open the game window with the specified map.

## Game Mechanics

- The player’s goal is to collect every collectible present on the map, then escape through the exit.
- Use the W, A, S, and D keys to move the character.
- The character cannot move into walls.
- The number of movements is displayed in the shell.
- The game uses a 2D top-down or profile view.

## Graphic Management

- The game window must remain responsive to minimize, maximize, and switch between windows.
- Pressing the ESC key or clicking the window's close button will exit the game cleanly.
- MiniLibX images must be used for graphics.

## Map Structure

- The map is composed of walls, collectibles, free spaces, and the player’s starting position.
- Valid characters are: 
  - `0` for an empty space
  - `1` for a wall
  - `C` for a collectible
  - `E` for the exit
  - `P` for the player's starting position

### Example Map
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```


- The map must contain at least 1 exit, 1 collectible, and 1 starting position.
- Maps must be rectangular and enclosed by walls.
- The program must check for a valid path from the starting position to the exit.
- If any issues are detected in the map file, the program will exit cleanly and return an error message.

