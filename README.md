# JuliaSetRenderer

## Julia Set rendering
(My own attempt at explaining this thing. I'm not gonna be a math major)
Julia sets are in my description/definition just mapping all Complex numbers on a Complex plane to some set which doesn't converge to infinity.(woah complex numbers so cool I sound so advanced in math so cool) The function of it is just a function you call many times: z = z ^ 2 + c, where c is some complex number constant and z is a complex number on the complex plane you want to map. If you perform this function on the same input many times and it does not go out of range in this case: |z| < 2, then this complex number is in the julia set.

## Design of renderer
I choose the ranges of the plane to be between -1 and 1 and I can adjust how many numbers I want to render. The color of a pixel/rect that represents a complex number on the complex plane is dependant on the number of iterations that took for the number to go out of range, or if it is in the set I'll set it to some color. I don't plan on adding a UI to control the range/ number of complex numbers to check/ color etc. because this is just a beginner project for someone who is new to C++ like me.

## Purpose of project
My first C++ project in my quest to master C++. I used SFML to render the pixels(actually rects). This project is about rendering Julia sets using the function z = z ^ 2 + c. The purpose of this project was just for my own personal satisfaction and pain where I actually figure out how C++ works from a JS programmer's point of view. Also because I think the Julia Set images I've seen online are very nice and I want to render my own to use as a wallpaper.
This is also my first legitmate GitHub repository and I'm learning how to use GitHub(I totally did not go through a lot of pain trying to commit changes)
