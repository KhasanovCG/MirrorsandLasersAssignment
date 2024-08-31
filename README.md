# MirrorsandLasersAssignment
### Task Description
I am tasked with solving a problem involving a safe with a laser-based optical closure mechanism. The safe operates by having a laser beam enter the top-left corner of a grid and exit at the bottom-right corner. The grid contains mirrors that reflect the laser at 45-degree angles. The objective is to determine if the laser can exit the grid and, if not, identify the possible positions where a missing mirror could be placed to allow the laser to exit.

### Given a grid with dimensions **r×c**, mirrors oriented as `/` or `\`, and their positions, the program needs to determine:
1. If the laser exits the grid without inserting an additional mirror.
2. If the laser cannot exit, identify the positions where inserting a mirror will allow it to exit.

### The output should be:
- **0** if the laser exits the grid without any additional mirrors.
- **1** if there is no possible way to make the laser exit.
- The number of valid positions where a mirror could be placed to allow the laser to exit, along with the lexicographically smallest position.

### Solution Overview:
The solution traces the path of the laser across the grid both forward (starting from the top-left) and backward (starting from the bottom-right). The idea is to find positions where placing a mirror would enable the laser to exit the grid. The intersection of possible mirror positions from both directions is then calculated to find the valid solutions.

### Key Concepts:
Laser Tracing- The laser's path is simulated based on the current direction and mirror placements.
Set Intersection- Potential mirror positions from forward and backward paths are compared to find valid spots.
The solution is implemented in C++14, adhering to the AUTOSAR C++14 guidelines, ensuring clean, organized, and concise code.

### Detailed Breakdown of Functions Used:
1. `struct Point`:
*Represents a coordinate in the grid.
*Overloaded operators for comparison to help with sorting and equality checks.
2. `bool traceLaser(int startX, int startY, int startDir, vector<Point> &path, set<Point> &mirror_positions)`:
*Traces the laser's path from a starting position and direction.
*Updates the path and potential mirror positions where the laser could pass without an obstacle.
3. `int main()`:
*Handles input parsing.
*Calls `traceLaser` to trace the laser both forward and backward.
*Computes the intersection of potential mirror positions and determines the final output.

### How to Run the Program:
We can compile the program using the following command:
`g++ -std=c++14 -o laser_mirror_safe laser_mirror_safe.cpp`

### Input Format:
First line: Four integers r,c,m,n where:
- r: Number of rows in the grid.
- c: Number of columns in the grid.
- m: Number of `/` mirrors.
- n: Number of `\` mirrors.
- Next m lines: Two integers ri,ci specifying the position of a `/ `mirror.
- Next n lines: Two integers ri,ci specifying the position of a `\ `mirror.

### Output:
Depending on the outcome, the program will output:
- 0 if the laser exits without adding a mirror.
- -1 if no solution is possible.
- The number of valid positions and the smallest valid position in the format k r c.

I have also added sample Input and Output results as the text files.
