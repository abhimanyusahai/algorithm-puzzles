testcases = input()
current_highest = 1
current_highest_factorial = 1

for i in xrange(0, testcases):
    n = input()
    factorial = n
    j = 1

    if n == current_highest:
        factorial = current_highest_factorial
    elif n > current_highest:
        while (n - j) > current_highest:
            factorial = factorial * (n - j)
            j += 1
        factorial = factorial * current_highest_factorial
        current_highest = n
        current_highest_factorial = factorial
    else:
        while (n - j) > 1:
            factorial = factorial * (n - j)
            j += 1

    print factorial
