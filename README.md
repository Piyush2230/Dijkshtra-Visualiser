# Dijkstra's Algorithm Visualizer

A mini project that visualizes **Dijkstra's shortest path algorithm** on a 2D grid — the same foundational logic used in real-world mapping systems like Google Maps.

---

## Project Structure

```
.
├── dijkstra_grid.cpp   # C++ implementation of Dijkstra's algorithm on a grid
├── dijkstra_grid       # Compiled binary (Linux)
├── output.txt          # Algorithm output: grid, path, start/end coordinates
├── index.html          # Browser-based interactive visualizer
└── README.md           # Project documentation
```

---

## How It Works

### 1. C++ Backend (`dijkstra_grid.cpp`)

The C++ program constructs a 10×10 grid with walls, runs Dijkstra's algorithm from a start cell to an end cell, and writes the result to `output.txt`.

**Key details:**
- Grid cells are either open (`0`) or walls (`1`)
- Movement is allowed in 4 directions: up, down, left, right
- A min-heap priority queue ensures the shortest path is explored first
- Parent tracking is used to reconstruct the full path after the algorithm completes

**Default configuration:**
| Parameter | Value |
|-----------|-------|
| Grid size | 10 × 10 |
| Start | `(1, 0)` |
| End | `(6, 9)` |
| Walls | Row 5 cols 3–7, Col 3 rows 2–6 |

### 2. Output File (`output.txt`)

The C++ program writes structured data to `output.txt`:

```
<rows> <cols>
<grid rows...>
<start_row> <start_col>
<end_row> <end_col>
<path_length>
<path coordinates...>
```

### 3. Browser Visualizer (`index.html`)

A self-contained HTML/CSS/JS page that:
- Accepts `output.txt` via a file upload button
- Renders the grid with walls, start (🏠), and end (📍) markers
- Animates the shortest path step-by-step (🟩) at 100ms per cell
- Displays the total number of steps taken

---

## Running the Project

### Step 1 — Compile and run the C++ program

```bash
g++ -o dijkstra_grid dijkstra_grid.cpp
./dijkstra_grid
```

This generates `output.txt` with the grid and shortest path data.

### Step 2 — Open the visualizer

Open `index.html` in any modern browser (no server needed).

### Step 3 — Load and animate

1. Click **Choose File** and select the generated `output.txt`
2. Click **Animate Path** to watch the shortest path unfold

---

## Example Output

For the default grid, the algorithm finds a path of **14 steps** (15 nodes):

```
(1,0) → (1,1) → (1,2) → (1,3) → (1,4) → (1,5) → (1,6) → (1,7)
      → (2,7) → (3,7) → (3,8) → (4,8) → (4,9) → (5,9) → (6,9)
```

The path navigates around the L-shaped wall barrier to reach the destination.

---

## Real-World Connection

Dijkstra's Algorithm is a foundational building block in:
- **Google Maps / Apple Maps** — finding shortest/fastest routes
- **Network routing** — determining optimal data packet paths
- **Game AI** — pathfinding for NPCs in grid-based games

---

## Dependencies

| Component | Requirement |
|-----------|-------------|
| C++ compiler | `g++` with C++17 support (`-std=c++17`) |
| Browser | Any modern browser (Chrome, Firefox, Edge) |
| External libraries | None |

---

## Author

**Piyush Tiwari** (2024UCS1652)
