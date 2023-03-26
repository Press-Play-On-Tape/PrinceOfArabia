#images to image sheet

import sys
import os
from PIL import Image
from math import sqrt

spacing = 0

if (len(sys.argv) < 2) or (len(sys.argv) > 3):
  sys.stderr.write("Usage: {} imagefolder [outputfile]\nWhen no outputfile is given, the imagesheet will be created in the parent folder.".format(os.path.basename(sys.argv[0])))
  sys.exit(-1)

imagepath = sys.argv[1]
if os.path.isfile(imagepath):
  imagepath = os.path.dirname(os.path.abspath(imagepath))
imagepath += os.sep  

images = []
for f in os.listdir(imagepath):
  if os.path.isfile(imagepath + f):
    images.append(f)

imagecount = len(images)
cols = imagecount // int(sqrt(imagecount))
if  (imagecount % cols) > (imagecount % (cols+1)): cols += 1
rows = (imagecount + cols -1) //  cols
if rows * cols > imagecount:
  rows = 1
  cols = imagecount
img = Image.open(imagepath + images[0]).convert("RGBA")
width = img.size[0]
height = img.size[1]
new = Image.new("RGBA", (cols * (width + spacing) + spacing, rows * (height + spacing) + spacing), (0,0,0,0))
c = 0
r = 0
for i in range(len(images)):
  img = Image.open(imagepath + images[i]).convert("RGBA")
  new.paste(img,(c * (width+spacing) + spacing, r * (height + spacing) + spacing))
  c += 1
  if c == cols:
    c = 0
    r += 1
if len(sys.argv) == 3:
  filename =sys.arg[2]
elif spacing > 0:
  filename = '{}{}{}_{}x{}_{}.png'.format(os.path.dirname(imagepath[:-1]), os.sep, os.path.basename(imagepath[:-1]),width,height,spacing)
else:  
  filename = '{}{}{}_{}x{}.png'.format(os.path.dirname(imagepath[:-1]), os.sep, os.path.basename(imagepath[:-1]),width,height)
new.save(filename)
