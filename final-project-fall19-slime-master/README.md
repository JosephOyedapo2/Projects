

#  Space invaders
## CS 110 Final Project
###  Fall semester, 2019
### [Assignment Description](https://drive.google.com/open?id=1HLIk-539N9KiAAG1224NWpFyEl4RsPVBwtBZ9KbjicE)

* Github repository link
 (https://github.com/bucs110/final-project-fall19-slime.git)

* Presentation slides link
  (https://binghamton-my.sharepoint.com/personal/amanzan1_binghamton_edu/Documents/CS%20final%20project%20slides.pptx?web=1)

### Team Name: Slime
#### Team Members: Adonay Manzanares, Michael Campese, Joseph Oyedapo

***

## Project Description
 side scroller space invader where the player is a ship shooting incoming enemies to earn points with only 3 lives available 

***    

## User Interface Design
* << A wireframe or drawing of the user interface concept along with a short description of the interface. You should have one for each screen in your program. >>
    * For example, if your program has a start screen, game screen, and game over screen, you should include a wireframe / screenshot / drawing of each one and a short description of the components
* << You should also have a screenshot of each screen for your final GUI >>

***        

## Program Design
* Non-Standard libraries
    *  N/A
* Class Interface Design
* ![class diagram](assets/Class_Diagram.jpeg)

* Classes
    * class bullet -> contains the functions for the bullet the user shoots to appear on screen and works the controller class
    * class controller -> contains the import code for the scoreboard hero and enemy movement and lives
    * class enemy -> contains the functions for the enemies to appear and move on the screen
    * class hero -> contains the functions for the hero input movement
    * class laser ->contains the functions for the enemy laser which is aimed towards the user to make them lose lives

***

## Tasks and Responsibilities
* You must outline the team member roles and who was responsible for each class/method, both individual and collaborative.

### Software Lead -  Adonay Manzanares

Worked as integration specialist by deciding what project to due and deciding what images and classes to use for the project and helped on all classes when members would need help  

### Front End Specialist - Joseph Oyedapo

 Front-end lead conducted significant research on how to size the models to fit in the screen get the enemy to move and shoot and the fonts folder and overall giving the game a more smooth flow and look

### Back End Specialist -  Michael Campese

 The back end specialist, worked on getting the controller, hero, enemy, bullet, class to operate

## Testing
* whenever we added something new we would test the code to see if it would run.
* EXAMPLE: When we added a new class we would run the code after each commit and safe to see if the code would work.

* Your ATP

| Step                  | Procedure     | Expected Results  | Actual Results |
| ----------------------|:-------------:| -----------------:| -------------- |
|  1  | Run game in terminal | GUI window appears ||
|  2  | Press space bar to begin | Game begins ||
|  3  | Move with the up and down key|Player moves in vertical motion||
|  4  | Player presses space bar to shoot| Bullet gets shot in horizontal motion||
|  5  | Hit enemies to get points| Each one has different points||
|  6  | Player has 3 lives| If hit more than 3 times player dies||
|  7  | Once out of lives| Game over screen appears ||
