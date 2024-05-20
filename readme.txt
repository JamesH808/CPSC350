to compile and run:
g++ *.cpp
./a.out

so ive got hold.txt as the output file for when the program is terminated. my program does most of the heavy lifting in the bst file. to keep integrety, 
my method was to advise the user to add a student or faculty with a missing ID of either advisor or advisee after adding a student or faculty. 
when an advisee is removed from a faculty, i opted to automatically give the student a new advisor, that being whoever the root faculty is. 
if integrety is broken, i would throw an error message without excecuting any changes, letting the user make the changes themselves for the most part. 