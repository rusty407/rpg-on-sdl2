# 2D RPG Game (WIP)

A 2D RPG game and engine built in C++ using [SDL2](https://www.libsdl.org/).  
Currently in **early development**, focused on learning game programming fundamentals and building a simple engine from the ground up.

## 🚧 Project Status

🛠️ Work in Progress  
This project is in active development. Expect rough edges and ongoing changes.

## 🎮 Goals

- Build a 2D RPG game with tile-based movement
- Design a lightweight 2D engine to handle:
  - Rendering (maps, sprites)
  - Input (keyboard controls)
  - Surface optimization and scaling
  - Basic game loop and state management
- Learn low-level SDL concepts and C++ memory management

## ✨ Current Features

- Window creation using SDL2
- Input handling (arrow key events)
- Image loading and rendering (BMP format)
- Surface optimization and full-screen stretching
- Switching between images on key press

## 🧱 Planned Features

- Tile map loading and rendering
- Player character movement
- Collision detection
- NPC interaction
- Simple scripting or event system
- Save/load support

## 🖥️ Build Instructions

> 🐧 Linux instructions shown. Adjust paths and package names for your OS.

1. Install SDL2:

```bash
sudo apt install libsdl2-dev for ubuntu
sudo pacman -S sdl2 for Arch Linux (i use arch btw)


Clone the repo:

git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name


Build:

make all

Run:

./rpg_game


Make sure your BMP image files are in the correct paths.

📁 Project Structure
/bmp_files/         # Contains .bmp images used in the game
main.cpp            # Main game loop and logic
README.md           # You're reading it!
```
🧠 Why I'm Building This

I’m building this project to:

Understand how 2D games and 2D game engines work under the hood

Learn low-level C++ and SDL graphics

Create something playable and expandable

🙌 Contributions

Right now this is a personal learning project, but feedback or ideas are always welcome. Feel free to open an issue or suggest something!
