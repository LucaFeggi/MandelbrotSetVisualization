#!/usr/bin/env bash

pdflatex main.tex
bibtex main
pdflatex main
pdflatex main
atril ./main.pdf &
