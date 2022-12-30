#!/bin/bash
cp fxdata.txt temp.txt


#
# Level 1
#
line=$(grep -n '<insert Level1_BG.csv>' temp.txt | cut -d ":" -f 1)
line2=$((line+1))
{ head -n $(($line-1)) temp.txt; cat ../levels/Level1_BG.csv; tail -n +$line2 temp.txt; } > temp2.txt
cp temp2.txt temp.txt
#
line=$(grep -n '<insert Level1_FG.csv>' temp.txt | cut -d ":" -f 1)
line2=$((line+1))
{ head -n $(($line-1)) temp.txt; cat ../levels/Level1_FG.csv; tail -n +$line2 temp.txt; } > temp2.txt
cp temp2.txt temp.txt


#
# Level 2
#
line=$(grep -n '<insert Level2_BG.csv>' temp.txt | cut -d ":" -f 1)
line2=$((line+1))
{ head -n $(($line-1)) temp.txt; cat ../levels/Level2_BG.csv; tail -n +$line2 temp.txt; } > temp2.txt
cp temp2.txt temp.txt
#
line=$(grep -n '<insert Level2_FG.csv>' temp.txt | cut -d ":" -f 1)
line2=$((line+1))
{ head -n $(($line-1)) temp.txt; cat ../levels/Level2_FG.csv; tail -n +$line2 temp.txt; } > temp2.txt
cp temp2.txt temp.txt


#
# Level 3
#
line=$(grep -n '<insert Level3_BG.csv>' temp.txt | cut -d ":" -f 1)
line2=$((line+1))
{ head -n $(($line-1)) temp.txt; cat ../levels/Level3_BG.csv; tail -n +$line2 temp.txt; } > temp2.txt
cp temp2.txt temp.txt
#
line=$(grep -n '<insert Level3_FG.csv>' temp.txt | cut -d ":" -f 1)
line2=$((line+1))
{ head -n $(($line-1)) temp.txt; cat ../levels/Level3_FG.csv; tail -n +$line2 temp.txt; } > temp2.txt
cp temp2.txt temp.txt



#
# Cut scenes
#
line=$(grep -n '<insert cutscenes.txt>' temp.txt | cut -d ":" -f 1)
line2=$((line+1))
{ head -n $(($line-1)) temp.txt; cat cutscenes.txt; tail -n +$line2 temp.txt; } > temp2.txt
cp temp2.txt temp.txt

#
# Images
#
line=$(grep -n '<insert images.txt>' temp.txt | cut -d ":" -f 1)
line2=$((line+1))
{ head -n $(($line-1)) temp.txt; cat images.txt; tail -n +$line2 temp.txt; } > temp2.txt
cp temp2.txt temp.txt

#
# Sounds
#
line=$(grep -n '<insert sounds.txt>' temp.txt | cut -d ":" -f 1)
line2=$((line+1))
{ head -n $(($line-1)) temp.txt; cat sounds.txt; tail -n +$line2 temp.txt; } > temp2.txt
cp temp2.txt temp.txt

#
# Constants
#
line=$(grep -n '<insert constants.txt>' temp.txt | cut -d ":" -f 1)
line2=$((line+1))
{ head -n $(($line-1)) temp.txt; cat constants.txt; tail -n +$line2 temp.txt; } > temp2.txt
cp temp2.txt temp.txt


python3 ./Arduboy-Python-Utilities-master/fxdata-build.py temp.txt
mv temp.bin fxdata.bin
mv temp.h fxdata.h

cp fxdata.bin ../../build/fxdata.bin

rm temp2.txt
rm temp.txt
