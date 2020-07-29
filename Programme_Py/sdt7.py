import turtle


def gap(t, size=50):
    t.penup()
    t.forward(size)
    t.pendown()


def draw_digit(n, size=50, pos=(0, 0)):
    t = turtle.Pen()
    t.speed(0)
    t.hideturtle()
    t.penup()
    t.goto(pos[0], pos[1])
    t.pendown()

    t.forward(size) if n in [0, 2, 3, 5, 6, 7, 8, 9] else gap(t, size)
    t.right(90)
    t.forward(size) if n in [0, 1, 2, 3, 4, 7, 8, 9] else gap(t, size)
    t.forward(size) if n in [0, 1, 3, 4, 5, 6, 7, 8, 9] else gap(t, size)
    t.right(90)
    t.forward(size) if n in [0, 2, 3, 5, 6, 8, 9] else gap(t, size)
    t.right(90)
    t.forward(size) if n in [0, 2, 6, 8] else gap(t, size)
    t.forward(size) if n in [0, 4, 5, 6, 8, 9] else gap(t, size)
    t.right(90)
    t.penup()
    t.goto(pos[0], pos[1] - size)
    t.pendown()
    t.forward(size) if n in [2, 3, 4, 5, 6, 8, 9] else gap(t, size)


for i in range(10):
    draw_digit(i, 10 + 10 * i, (-400 + i * (i + 1) * 8, 10 + 10 * i))
turtle.done()
