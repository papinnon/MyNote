import tensorflow as tf
from tensorflow.keras.models import load_model
import numpy as np

mnist =  tf.keras.datasets.mnist
(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train, x_test = x_train/255.0, x_test/255.0

def func(x):
    return x*x*0.1+101

x_train = np.random.rand(20000,1)
for i in range(len(x_train)):
    x_train[i][0]*= 1000

print(x_train)
y_train = np.array([func(xi[0]) for xi in x_train])
print(y_train)
x_test  = np.array([1,5,100,250,750])
print(x_test.shape)

model  = tf.keras.models.Sequential()
model.add(tf.keras.layers.Dense(64, activation="relu",input_shape=(1,)))
model.add(tf.keras.layers.Dense(64,activation="relu"))
model.add(tf.keras.layers.Dense(1))

model.compile(optimizer='adam',loss= 'mse', metrics=['mae'])
model.fit(x_train, y_train, epochs =200)

print("prediction:")
print(model.predict(x_test))
for i in x_test:
    print(func(i))
