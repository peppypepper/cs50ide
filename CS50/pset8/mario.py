import cs50

while True:
    height = cs50.get_int("height: ")
    if height > 0 and height < 24:
        break

for i in range(height):

    for j in range(height - i):
        print(" ", end="")

    for k in range(i):
        print("#", end="")

    print()