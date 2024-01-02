Xming with Ubuntu or WSL1.0 is required to run the code.

If using Ubuntu:

If OpenGL and GLUT are not installed:
"sudo apt-get install freeglut3-dev"
It needs to be installed by running the code in the terminal.

If using WSL1.0:

To enable WSL1.0, it is enough to turn on the Windows Subsystem for Linux feature.
Xming can be downloaded from the internet. (The purpose of Xming is to create an interface that will process the image running with code by creating a local server in Windows)

To compile the code:
"g++ hw1.cpp -o hw1 -lglut -lGLU -lGL"
After compiling the code
"./hw1"
You can run it with the command.

After the code runs:

Rotation can be performed by holding down the left mouse button.
You can move forward with W.
You can go back with S.
You can go left with A.
You can go right with D.
You can be zoom in with Q.
You can be zoom out with E.
Upward rotation can be done with Y.
Downward rotation can be done with H.
Rotation to the left can be done with G.
Rotation to the right can be done with J.
You can exit the program with ESC.