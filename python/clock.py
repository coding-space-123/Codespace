import turtle
import time

t = turtle.Turtle()
x = 0
y = 0
t.home()   # turtle at origin
t.speed(0)

y = -100
t.penup()
t.goto(x, y)
t.pendown()
t.begin_fill()
t.fillcolor("red")
t.circle(100)
t.end_fill()

t.penup()
t.home()
y = -60
t.goto(x, y)
t.pendown()
t.circle(60)

# for writing numbering using for loop
t.penup()
t.home()
t.left(90)
for i in range(12):  # i=0 to 11
    t.right(360/12)
    t.fd(85)
    t.write(i+1, align="center", font=("Arial", 10, "normal"))
    t.goto(0, 0)

def draw_hour_arm():
    t.penup()
    t.home()
    t.right(180)
    t.pendown()
    t.pensize(5)
    t.fd(40)

def draw_min_arm():
    t.penup()
    t.home()
    t.right(270)
    t.pendown()
    t.pensize(3)
    t.fd(70)

draw_hour_arm()
draw_min_arm()

t.pensize(2)
angle1 = 0

a = 1
while True:
    if a == 1:
        t.penup()
        t.home()
        t.left(90)
        a = 2

    t.right(angle1)
    t.pendown()
    t.fd(60)
    time.sleep(1)  # Use simple sleep for 1 second delay
    t.undo()       # Undo the last step (the second hand line)
    t.penup()
    t.goto(0, 0)
    angle1 += (360/60)  # Move by 6 degrees each second

turtle.done()
