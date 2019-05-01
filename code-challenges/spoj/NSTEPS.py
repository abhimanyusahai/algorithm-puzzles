num_points = input()

for i in xrange(0, num_points):
    usr_input = raw_input()

    coordinates = usr_input.split()
    x = int(coordinates[0])
    y = int(coordinates[1])

    if x == y:
        if x%2 == 0:
            ans = 2*x
        else:
            ans = 2*x - 1
    elif x == y + 2:
        if x%2 == 0:
            ans = 2*x - 2
        else:
            ans = 2*x - 3
    else:
        ans = 'No Number'

    print ans
