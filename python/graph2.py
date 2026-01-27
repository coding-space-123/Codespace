from  turtle import *                                    # import  all turtle graphics module
bgcolor("black")                              #set the background color to black
speed(0)                            #set turtle speed(fast)
pencolor("gold")                          #set pen color to gold
#define a function to draw a rotated square 
def draw(x):
    right(10)  #turn the turtle 10 deg to the right
    for i in range(4):
        forward(x)
        right(90)
        forward(x)

x=120
for i in range (8):
    for j in range (36):
        draw(x)
    x-=10
hideturtle()
done()
