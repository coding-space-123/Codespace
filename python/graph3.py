from turtle import *
from colorsys import *
tracer(10)
bgcolor("black")
h = 0.2
pensize(3)
for i in range (200):
    color(hsv_to_rgb(h,1,1))
    h+=0.005
    left(100)
    up()
    forward(i)
    down()
    circle(i,-90)
    right(200)
    up()
    forward(i)
    left(120)
    forward(i)
    down()
done()
