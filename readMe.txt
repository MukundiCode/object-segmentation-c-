Tinashe Mukundi Chitamba

1. The PGMImageProcessor.cpp and header file have the declaration and implementation for the PGMImageProcessor 
class, and stores the connectedComponents, as well as having the required methods stated in the assignment 

2. The connectedComponent.cpp and header file have the declaration and implementation for the PGMImageProcessor
class, which stores a connectedComponent, in the form of a vector of pixels

3. The pixel.cpp and header file have the declaration and implementation for the pixel class, which stores the
data for a single pixel (x value, y value, unsigined char value)

4. Added the boundaryCount variable in connectedComponent
Please note that my program converts unsigned char values to ints, and so the threshold should be within the specfied range 
of values printed by cout. The values will be negative.

SAMPLE CMD STATEMENT TO RUN

./findcomp.exe chess2.pgm -s 500 8241 -t -95 -p -w out.pgm
