#!/usr/bin/env bash

INCDIR='./src'
TESTDIR='./test'
BIN='./bin'

gcc -D_REENTRANT "-I$INCDIR" -I/usr/include/SDL2 "$TESTDIR/test_window.c" -o "$BIN/test_window" -lSDL2

gcc "-I$INCDIR" "$TESTDIR/test_mandelbrot.c" -o "$BIN/test_mandelbrot" -lm
gcc "-I$INCDIR" "$TESTDIR/test_print.c" -o "$BIN/test_print"
gcc "-I$INCDIR" "$TESTDIR/test_traverse.c" -o "$BIN/test_traverse" -lm

#gcc -D_REENTRANT -I/usr/include/SDL2 ./test_window.c -lSDL2
