# Dots and Boxes Game

This is my first project and it is a personal one. My aim was to take this problem and find the most efficient, elegant yet simple one; logically and code wise. I wanted my code to be self-explanatory and easy to follow by any one.

This project marks the beginning of my journey towards learning how to design and write sustainable, scalable software that can handle real-life, large-scale applications.


## Game Description
Starting with an empty grid of dots, two players take turns adding a single horizontal or vertical line between two unjoined adjacent dots. The player who completes the fourth side of a 1x1 box (or groups of one or more adjacent boxes) earns one point(s) and takes another turn. The game ends when no more lines can be placed. The winner is the player with the most points.


## Implementation
   - ### Dots Grid 
       The game grid is 2-Dimentional vector that can be of any size up to 9x9.
     
   - ### All Boxes
       2-Dimentional vector representing all Boxes formed on the Grid.

   - ### Building Blocks
     - #### Edge
         Two Dots connect to form an Edge represented by a ***string***.
     - #### Box
         Four Dots connect to form a Box.
      
   - ### Mapping
     - #### Connected Dots - Edges
         Each ***string*** representing an edge mapped to its Edge object.
     - #### Edges - Boxes
         Each Edge, represented by its ***string*** is mapped to the Box/Boxes it is a part of.
         
## Features
   - ### Save and Load Game
\
\
\
\
Feedback is highly appreciated.
##
> Future Update to include : Human Vs Computer Mode - Larger Grid size.     
