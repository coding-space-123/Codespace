from turtle import*
speed(0)
bgcolor("#081b29")
colors=['#0ef','red']

for i in range(122):
    goto(0,0)
    color(colors[i%2])
    forward(130)
    left(3)
    circle(40)
    forward(130)
    right(180)
hideturtle()
done()