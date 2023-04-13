from keras.models import load_model
from keras.utils import np_utils
from PIL import Image
import numpy as np
import cv2
import matplotlib.pyplot as plt

model = load_model('Predict_Model_2.h5')

img_path = "/home/iotuser/CLionProjects/paint_brush_v5/image/my_save.png"

img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)

#plt.imshow(img)
#plt.show()

img = cv2.resize(255 - img, (28, 28))
#plt.imshow(img)
#plt.show()

test_num = img.flatten() / 255.0
test_num = test_num.reshape((-1, 28, 28, 1))

prob = model.predict(test_num)

predicted = np.argmax(prob, axis = -1)

print('The Answer is ', predicted)