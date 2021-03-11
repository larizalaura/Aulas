#!/bin/sh

echo 'removendo objetos'
rm -f *.o

echo 'compilando objetos' &&
g++ -c -g BinaryTree.cpp

echo 'compilando main' 
g++   main.cpp BinaryTree.o  -o main

echo 'executando main' 
./main
