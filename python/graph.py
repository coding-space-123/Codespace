import turtle                                       # import turtle graphics module
turtle.tracer(50)                                   #set animation speed(fast)
turtle.setposition(0,25)                            #move turtle to starting position 
turtle.bgcolor("black")                             #set the background color to black
colors=["yellow" , "red" , "yellow" , "red"]        #list of colors to use
turtle.hideturtle()                                 #hide the turtle cursor for cleaner drawing
# outer loop:draw 80 shapes
for i in range (80):                 
    #inner loop: for each color
    for c in colors:
        turtle.color(c)                             #set pen color
        turtle.circle(175-i , 100)                  #draw part of a circle (smaller each time)
        turtle.left(90)                             #turn left 90 deg
        turtle.circle(175-i , 100)                  #draw another partial circle
        turtle.right(60)                            #turn right 60 deg
turtle.done()                                       #finish drawing
