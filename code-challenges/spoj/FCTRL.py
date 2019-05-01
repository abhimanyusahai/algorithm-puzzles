num_numbers = input()

for i in xrange(0, num_numbers):
    N = input()
    num_fives = 0
    num_twos = 0

    for j in xrange(0, N):
        if (N - j) % 5 == 0:
            k = N - j
            while (k % 5 == 0):
                num_fives += 1
                k = k/5
        if (N - j) % 2 == 0:
            k = N - j
            while (k % 2 == 0):
                num_twos += 1
                k = k/2

    if num_fives <= num_twos:
        print num_fives
    else:
        print num_twos
