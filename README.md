![](https://github.com/SenseLogic/GRID/blob/master/LOGO/grid.png)

# Grid

An 8-bit 3D retro game for the Commodore 64.

## Description

A nostalgic tribute to my early days of 3D game development, this project is a complete rewrite in C of the Tron-inspired 3D fan game I originally created in 1983 on my Commodore 64 using 6502 assembly language.

## History

When the iconic movie "Tron" was released in 1982, it revolutionized the industry and inspired a generation of aspiring game developers, myself included.

So when I bought a Commodore 64 the following year, it was already with the clear goal of trying to reimplement a 3D tank game similar to the one depicted in the movie.

![Movie](https://github.com/SenseLogic/GRID/blob/master/IMAGE/movie_1.png)
![Space Paranoids](https://github.com/SenseLogic/GRID/blob/master/IMAGE/movie_2.png)

Unfortunately, as I was learning how to program Commodore 64 games in Basic and then 6502 assembly language, I quickly realized that its hardware was exclusively designed for 2D games made of sprites and character maps.

Of course, despite these harsh limitations, it wasn't short of fantastic games, such as Shamus, Boulder Dash, MatchPoint, International Soccer, Commando and International Karate, to name just a few.

![Shamus](https://github.com/SenseLogic/GRID/blob/master/IMAGE/shamus.gif)
![Boulder Dash](https://github.com/SenseLogic/GRID/blob/master/IMAGE/boulder_dash.gif)
![MatchPoint](https://github.com/SenseLogic/GRID/blob/master/IMAGE/match_point.gif)
![International Soccer](https://github.com/SenseLogic/GRID/blob/master/IMAGE/international_soccer.gif)
![Commando](https://github.com/SenseLogic/GRID/blob/master/IMAGE/commando.gif)
![International Karate](https://github.com/SenseLogic/GRID/blob/master/IMAGE/international_karate.gif)

But making it run such a 3D game seemed initially impossible, due to the following constraints :

-   A very slow 8-bit CPU :
    -   Only capable of basic arithmetic operations on 8-bit integers;
    -   Without hardware support for integer divisions, 16-bit operations or floating-point numbers.
-   A 2D graphics chip with :
    -   A character-based display with 40 rows of 25 characters;
    -   Eight 24x21 pixel hardware sprites.
-   Only 64 KB of RAM to store all the game code and data.

However with considerable persistence and dedication, I eventually managed to make my dream a reality, though I had to drastically reduce my ambitions to deal with the hardware at hand.

![Grid 1](https://github.com/SenseLogic/GRID/blob/master/IMAGE/grid_1.png)
![Grid 2](https://github.com/SenseLogic/GRID/blob/master/IMAGE/grid_2.png)
![Grid 3](https://github.com/SenseLogic/GRID/blob/master/IMAGE/grid_3.png)
![Grid 4](https://github.com/SenseLogic/GRID/blob/master/IMAGE/grid_4.png)
![Grid 5](https://github.com/SenseLogic/GRID/blob/master/IMAGE/grid_5.png)
![Grid 6](https://github.com/SenseLogic/GRID/blob/master/IMAGE/grid_6.png)

[![Gameplay Video](https://img.youtube.com/vi/fgE7rKQw6oo/0.jpg)](https://www.youtube.com/watch?v=fgE7rKQw6oo)

But despite its ugly graphics and repetitive gameplay, this little fan-game still remains one of my proudest programming achievements to date, along with my full-body real-time 3D character animation application for television shows (1994), my commercial 3D game engine for Windows, Xbox, PlayStation 2 and GameCube (2001), and my real-time supermassive point cloud VR explorer (2019).

Not only did this project start my long journey into 3D multimedia development, but it was an incredibly rewarding and enlightening experience, and even today, each time I think about it, I can't help but smile :)

## Implementation details

Here are some of the strategies I used to make this small 3D game run on a Commodore 64 :

*   **8-bit CPU** :

    *   Implement the entire game in highly optimized 6502 assembly language.
    *   Use 8-bit integers (-128 to 127) for angles, allowing for 256 possible angles.
    *   Use 2.6 fixed-point 8-bit integers for sinuses and cosinuses.
    *   Use 4.4 fixed-point 8-bit integers for local scales.
    *   Use 6.2 fixed-point 8-bit integers for local coordinates and speeds.
    *   Use 16-bit integers (-32768 to 32767) for 8-bit product and left shift results.
    *   Use 14.2 fixed-point 16-bit integers for world coordinates.
    *   Emulate 16-bit operations (addition, multiplication, shift, division) in software.
    *   Use multiplications and divisions only where it's not possible to replace them by shifts.
    *   Use lookup tables with precomputed sinuses, arctangents and projection factors.
    *   Move and rotate the world around the player tank to keep it at the origin.
    *   Rotate the camera by 7-degree increments, using 1 and 1/8 as cosinus and sinus approximations.
    *   Cull models outside the view frustum.
    *   Render models in wireframe, using as few vertices as possible.
    *   Use 2D models for the recognizers and 3D models for the arrows.
    *   Render less wireframe lines for distant recognizers and arrows.
    *   Only allow X and Y rotations for 3D models.

*   **2D GPU** :

    *   Define a custom font of 256 characters that renders all possible tiles of 2x4 pixels.
    *   Draw the 3D grid, recognizers and arrows through this font on the 40x25 screen characters, allowing for a virtual grid of 80x100 pixels.
    *   Draw the ground dots row by row, extrapolating all row vertices from the two middle dots.
    *   Draw everything else (title, mountains, reticle, radar) using the 8 hardware sprites.

*   **64 KB of RAM**

    *   Use compact data types for all variables, arrays and data structures.
    *   Compress the model, sprite and music data.
    *   Generate the level music dynamically.

## Installation

*   Download [Oscar64](https://github.com/drmortalwombat/oscar64/releases/download/v1.32.263/oscar64.zip)
*   Decompress it in the `TOOL/OSCAR64/` folder
*   Download [VICE](https://sourceforge.net/projects/vice-emu/files/releases/binaries/windows/GTK3VICE-3.8-win64.zip/download)
*   Decompress it in the `TOOL/VICE/` folder
*   Run "run.bat" from the `CODE/` folder

## Gameplay

You command a battle tank tasked with surviving six waves of incoming recognizers, with up to five enemies per wave.

Recognizers come in four distinct classes, each with unique characteristics (color, speed and shield level).

The fastest ones can be derezzed with only one shot, while the heaviest ones require four hits to obliterate them.

## Controls

- **Numpad 4**: Turn left
- **Numpad 6**: Turn right
- **Numpad 8**: Aim higher
- **Numpad 2**: Aim lower
- **Numpad 0**: Shoot

## Changes

Apart from being implemented in C, this rewrite includes a few other differences from the original :

- There are only six enemy waves.
- The opening theme is inspired by Daft Punk's *Tron: Legacy* soundtrack.

## Version

2.0

## Author

Eric Pelzer (ecstatic.coder@gmail.com).

## License

This project is licensed under the GNU General Public License version 3.

See the [LICENSE.md](LICENSE.md) file for details.

## Disclaimer

This project is a fan-made, unofficial tribute to the 1982 movie "Tron", and is not endorsed by or affiliated with The Walt Disney Company.
