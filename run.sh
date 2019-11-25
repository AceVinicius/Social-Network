# !/bin/bash

# Create Object files
cd src
ccache clang dbBinaryTree.c -c -Wall -W -O3 -o ../obj/dbBinaryTree.o
ccache clang flBinaryTree.c -c -Wall -W -O3 -o ../obj/flBinaryTree.o
ccache clang operations.c   -c -Wall -W -O3 -o ../obj/operations.o
ccache clang parseInput.c   -c -Wall -W -O3 -o ../obj/parseInput.o
ccache clang CUI.c          -c -Wall -W -O3 -o ../obj/CUI.o

# Create static library
cd ../obj
ar -rcs libbst.a dbBinaryTree.o flBinaryTree.o 
ar -rcs libop.a operations.o
ar -rcs libpi.a  parseInput.o
ar -rcs libCUI.a  CUI.o

# Compile and link static libraries
cd ../src
ccache clang main.c -lCUI -lpi -lop -lbst -L../obj -Wall -W -O3 -o ../bin/social_network -g

# Run social_network
cd ../bin
./social_network #< ../lib/log/socialMediaLog.txt