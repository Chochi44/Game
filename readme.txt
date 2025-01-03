# Trash Master

## Overview
Trash Master is an arcade game where you control a garbage truck across multiple lanes. Navigate through streets, collect trash to earn points, and avoid obstacles that end your cleaning spree.

## Game Features
- Multi-lane gameplay environment with 7 total lanes:
  - 5 main street lanes
  - 2 grass side lanes 
  - Configurable lane count via parameters (Main.cpp, line 9)
  - Possible extension of the game to dynamically change the lanes as the levels progress.
- Dynamic obstacle placement system
- Point-based scoring mechanics
- Intuitive controls for accessibility
- Extensible architecture for future enhancements

## Gameplay Instructions

### Controls
- Left/Right Arrow Keys: Move truck between lanes
- Any Key: Start game or restart after collision

### Basic Rules
1. Navigate between lanes to collect trash items
2. Avoid all obstacles - collisions end the game
3. Missed trash items deduct from score
4. Aim for highest possible score

### Scoring System
- Gain points: Collect trash items
- Lose points: Miss trash items
- Game over: Collide with any obstacle

## Technical Architecture

### Design Philosophy
The game architecture prioritizes extensibility, allowing easy addition of new features and obstacles through its modular design.

### Key Components
- Main.cpp: Entry point and game loop implementation
- Game.h: Core game logic and mechanics
- GameControl.h: Shared control interface for game objects
- Obstacle.h: Base class for all obstacles
- Trash.h: Base class for collectible items
- Pothole.h: Base class for collision obstacles
- Island.h: Complex multi-sprite obstacle implementation
- Trees.h: Dynamic texture obstacle example

## Credits
- Artwork: @sharky__lady on Instagram
- Sounds and Fonts: Microsoft