# Battle of Numbers

**Author**: Ákos Juhász  
**University**: Babeș-Bolyai University  
**Group**: 512  
**Year**: 2024  

---

## Project Overview

**Battle of Numbers** is a multiplayer elimination game implemented using a circular linked list. Each player takes turns adding numbers to a shared total, and the goal is to avoid being the one to push the total to or above 100. The last remaining player wins the game.

The application serves as a data structures project with a strong emphasis on dynamic player management using circular lists.

---

## Gameplay Description

### Game Initialization

- Players enter their names and the total number of participants (minimum 2).
- The shared sum starts at 0.

### Turn-Based Play

- Each player, in turn, adds a number between 1 and 9 to the shared total.
- After each number is added, the total is checked.

### Elimination Rules

- If the total reaches or exceeds 100, the player who caused it is eliminated.
- Eliminated players are removed from the circular list.

### Dynamic Player Management

- Players can join or leave the game at any time.
- New players are inserted at a specified position, or at the end if no position is available.

### Game End

- The game ends when only one player remains, who is then declared the winner.

### Input/Output

- Input: Player names, numbers played, and join/leave commands.
- Output: Current state after each turn, eliminations, and final winner.

---

## Data Structure: Circular Linked List

The player list is implemented as a circular linked list that supports:

- Adding players:
  - At a specific index
  - At the beginning
  - After a specific player
- Removing players
- Searching by name
- Printing the previous or next player
- Counting elements
- Printing the full list
- Accessing an element by index or value

Each node in the list contains:

- A name
- A pointer to the next player

---

## Constraints & Validations

- Player names must be unique.
- Only numbers between 1 and 9 are accepted.
- The game ensures valid input, otherwise prompts for re-entry.

---

## Example

### Input

2 Anna Peter 9 9 ...

### Output

Anna caused the sum to reach 108 and was eliminated. The winner is Peter!

---
