usr_input = raw_input()

while (usr_input != '0 0 0'):
    numbers = usr_input.split()
    a = int(numbers[0])
    b = int(numbers[1])
    c = int(numbers[2])
    progression_type = ""
    next_num = 0

    # Test for AP
    if (b - a) == (c - b):
        progression_type = "AP"
        next_num = c + (c - b)
    # If not AP, it's a GP
    else:
        progression_type = "GP"
        next_num = c * (c / b)

    print progression_type + " " + str(next_num)
    usr_input = raw_input()
