#!/bin/bash
python3 ./Arduboy-Python-Utilities-master/fxdata-build.py fxdata.txt

cp fxdata.bin ../../build/fxdata.bin

# montage ???_*.png -geometry 36x36+0+0 -background none -tile 15x15 Mirror_Right_36x36.png
# ./midiConverter -o2 -k12 -fa pop_ending