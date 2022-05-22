# Game_of_Life
My Git Repository URL: https://github.com/INversionNan/Game_of_Life
Screenshot of my git commit history:
![image](https://user-images.githubusercontent.com/102014220/169686485-d0a6e570-17ca-4219-9a43-7e55ed7127a4.png)
I choose the project two "Game of Life":
Introduction on how to run my program:
1. Primarily, the player needs to have the option of passing either 1 argument (filename) or 2 arguments (filename and number of iterations) to the command line.
2. Next, the player has three options, the first is to initialize the game by modifying the contents of the file, the second is to initialize the game by clicking on the map, and the third is to exit the program.
3. For the first choice, the player need to modify the file content in advance, such as adding {{0,0,0,0}, {1,1,0,1}, {1,0,1,0}} to initialize the initial state. And you can choose automatic cell update or keyboard input for update. 
4. For the second choice, the player need to click on the map to initialize it, and use keyboard input to iterate through updates.
5. Furthermore, the whole game follows as Conway's set of rules which is summarised as:
   Any live cell with 0 or 1 live neighbour becomes dead because of underpopulation
   Any live cell with 2 or 3 live neighbours stays alive because its neighbourhood is just right
   Any live cell with more than 3 live neighbours becomes dead because of overpopulation
   Any dead cell with exactly 3 live neighbours becomes alive by reproduction
6. The game ends when all cells die or remain in a constant state throughout the map and the number of iterations previously set is exhausted. Exit the program.
