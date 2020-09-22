import hashlib
from PIL import Image

def compareImage(filename1,filename2):
  md5hash = hashlib.md5(filename1)
  image1 = md5hash.hexdigest()

  md5hash = hashlib.md5(filename2)
  image2 = md5hash.hexdigest()

  if(image1 == image2):
    print(image1)
    print(image2)
    return ("Image Not Tampered")
  else:
    print(image1)
    print(image2)
    return("Image is Tampered")

filename1=Image.open(r'down.png').tobytes()
filename2=Image.open(r'down_tamp.png').tobytes()
compareImage(filename1,filename2)

filename1=Image.open(r'down.png').tobytes()
filename3=Image.open(r'down_tamp2.png').tobytes()
compareImage(filename1,filename3)