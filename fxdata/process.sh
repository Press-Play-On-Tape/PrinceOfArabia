#!/bin/bash

Python3 scripts/createMovements.py ../src/utils/Constants.h movements.txt
Python3 scripts/createSEQData.py ../src/utils/Constants.h ../src/utils/movements_SEQData.h
Python3 scripts/createOFFSETSData.py ../src/utils/Constants.h ../src/utils/movements_OFFSETSData.h

python3 ./Arduboy-Python-Utilities-master/fxdata-build.py fxdata.txt

cp fxdata.bin ../../build/fxdata.bin



# montage ???_*.png -geometry 36x36+0+0 -background none -tile 15x15 Mirror_Right_36x36.png
# ./midiConverter -o2 -k12 -fa pop_ending