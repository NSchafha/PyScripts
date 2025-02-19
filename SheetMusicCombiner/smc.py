import argparse
import img2pdf
import os
from reportlab.pdfgen import canvas

parser = argparse.ArgumentParser()
parser.add_argument("folder")
parser.add_argument("filename")
parser.add_argument("imgFolder")
args = parser.parse_args()

outputPath = os.path.join(args.folder, args.filename)

#For Personal
#folder = "/Users/julie/Desktop/Sheet Music"
#outputPath = os.path.join(folder, args.filename)#

can = canvas.Canvas(outputPath)
can.save()

print(f"PDF created: {outputPath}")

image_files = [i for i in os.listdir(args.imgFolder) if i.endswith(".png")]

pdf_data = img2pdf.convert(image_files)

with open(outputPath, "wb") as file:
    file.write(pdf_data)