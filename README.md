# Invaders
Space Invader game use Bit Operations

# How to run:
Mac OS: find Xcode project file in folder.

SDL2 is used for rendering. To learn more about SDL https://wiki.libsdl.org/FrontPage

Note: The SDL2 libraries are included under Frameworks folder. In case you see error message indicate failing to load SDL2 libraries: try copy the SDL2 libraries files “SDL2*.framework” to  /Library/Frameworks/



# Classes :
Game: Maintain main loop and take care of keyboard inputs, update game status and rendering to screen.

Aliens: Use a vector of 16 bit integer to represent aliens locations. Use bitwise operations to move the aliens and detect collisions. Aliens will be recreated from top when all current aliens is destroyed by the player ship.

Player: Represents player ship. Player has three lifes when game starts and when the player is hit more than three times, game will be ended.

Rocket: Represent single rocket, owns its own location and texture.

Rockets: Contains a list of rockets. Use list for insertion and deletion efficiency.

Bomb/Bombs: Similar to Rocket/Rockets.

Timer: Keep track of game time and frame rate capping(30 fps).

Util: Macros for bit operations.
