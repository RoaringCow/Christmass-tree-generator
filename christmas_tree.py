import random
body_height = int(input("Body height?:\n"))
root_height = int(input("Root height?\n"))
root_thickness = int(input("Root thickness?\n"))
decoration_ask = str(input("Do you want to add decorations?(Y/N)\n"))
body_list = []
space_list = []
root_list = []

if decoration_ask.lower() == "n":
    print("ok")
elif decoration_ask.lower() == "y":
    decorations = str(input("Type in the letters you want for decoration: \n"))
else:
    print("You didn't type in a letter that i wanted you to type so im counting that as a no")
while root_thickness >= 2 * body_height - 1:
    print("So... You want to make a tree that has a thicker trunk than its width with leaves?")
    root_thickness = int(input("Root thickness?\n"))

while root_thickness % 2 == 0 or root_thickness % 1 != 0: # to make sure they give an input that can be divided by 3 or 1
    print("Please give an input that can be divided by 3 or 1 or your tree would look scuffed")
    root_thickness = int(input("Root thickness?\n"))

for x in range(1, body_height + 1):
    sayac = 0
    temporary_string = (" " * (body_height - x))
    while sayac < (x * 2 - 1):
        chance = random.randint(1, 8)
        if chance == 1:
            temporary_string += random.choice(decorations)
        else:
            temporary_string += "*"
        sayac += 1
    print(temporary_string)
sayac = 0
while sayac < root_height:
    print(" " * ((body_height - int((root_thickness + 1) / 2)) - 1), "*" * root_thickness)
    sayac += 1
