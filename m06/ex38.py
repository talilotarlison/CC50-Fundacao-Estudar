import os
import qrcode

img = qrcode.make('https://www.youtube.com/watch?v=2X0g1j4v8mA')
img.save("qr.png", "PNG")
os.system("open qr.png")# open for MacOS, use "xdg-open" for Linux or "start" for Windows
