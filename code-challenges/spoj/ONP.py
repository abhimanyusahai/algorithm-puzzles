num_cases = input()
ALPHABETS = map(chr, xrange(97, 123))
OPERATORS = ['+', '-', '*', '/', '^']

for i in xrange(0, num_cases):
    usr_input = raw_input()
    usr_input = list(usr_input)
    operator_stack = []
    answer = []

    for j in xrange(0, len(usr_input)):
        if usr_input[j] in ALPHABETS:
            answer.append(usr_input[j])
        elif usr_input[j] in OPERATORS:
            operator_stack.append(usr_input[j])
        elif usr_input[j] == ')':
            answer.append(operator_stack.pop())

    print ''.join(answer)
