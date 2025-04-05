import os
import qrcode

img = qrcode.make('https://www.youtube.com/watch?v=2X0g1j4v8mA')
img.save(os.path.join('m06', 'ex36.png'))
img.show()
