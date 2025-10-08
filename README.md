# 🎮 2D RPG Game Engine (WIP)

A **2D RPG game and engine** built with **C++** and **[SDL2](https://www.libsdl.org/)**.  
Currently in **early development**, focused on learning game development fundamentals and building a lightweight, custom engine from the ground up.

---

## 🚧 Project Status

🛠️ **In Progress**  
This project is under active development. Expect rapid changes, work-in-progress features, and learning-driven code.

---

## 🧠 Why I'm Building This

- To understand how 2D games and engines work under the hood
- To learn SDL2 and low-level graphics programming in C++
- To build something playable and expandable from scratch

---

## 🎯 Core Goals

- Tile-based RPG gameplay
- Lightweight 2D engine handling:
  - Rendering (maps, sprites)
  - Input (keyboard)
  - Surface optimization & stretching
  - Game loop + state management

---

## ✨ Current Features

- ✅ SDL2 window creation
- ✅ Input handling (arrow keys)
- ✅ BMP image loading and rendering
- ✅ Surface optimization to match screen format
- ✅ Fullscreen image scaling with `SDL_BlitScaled`
- ✅ Switching scenes/images with key presses

---

## 🧱 Planned Features

- [ ] Tile map loading + rendering
- [ ] Player character movement
- [ ] Collision detection
- [ ] NPC interaction
- [ ] Event/scripting system
- [ ] Save/load game state
- [ ] Audio (SFX + BGM)

---

## 🛠️ Build & Run Instructions

> 🐧 Linux-based instructions (tested on Arch & Ubuntu)  
> ✅ Requires SDL2 development libraries

### 🔧 Install SDL2

```bash
# Ubuntu/Debian:
sudo apt install libsdl2-dev

# Arch Linux (I use Arch btw 😎)
sudo pacman -S sdl2
```
📦 Clone the repo
```bash
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name
```
🏗️ Build the game
```bash
make all
```
If you don't have a Makefile, you can manually compile:

```bash
g++ main.cpp -o rpg_game -lSDL2
```
▶️ Run it
```bash
./rpg_game
```
Make sure your .bmp image files are placed in the correct path.

📁 Project Structure
```bash
/bmp_files/          # BMP image assets
main.cpp             # Core game logic + event loop
README.md            # You're reading it!
Makefile             # (Optional) Build script
```
## ✨ Contributions
This is a personal learning project — but feedback, ideas, and suggestions are always welcome.

Open an issue or start a discussion if you’d like to contribute or ask questions.

## ✨ License
Feel free to add a license here (MIT is common for open learning projects).

## ✨ Videos and Screenshots...
Screenshots, engine structure docs, and dev logs as progress continues!

[![Watch the video](https://img.youtube.com/vi/d0tMFpN2BHQ/hqdefault.jpg)](https://www.youtube.com/watch?v=d0tMFpN2BHQ)
