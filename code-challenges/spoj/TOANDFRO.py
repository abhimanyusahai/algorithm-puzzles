num_cols = input()

while num_cols:
    input_code = raw_input()

    rows = []
    output_sentence = []
    num_rows = len(input_code)/num_cols

    for i in xrange(0, num_rows):
        if i % 2 == 0:
            rows.append(input_code[(i * num_cols):((i + 1) * num_cols)])
        else:
            rows.append(input_code[(((i + 1) * num_cols) - 1):((i * num_cols) - 1):-1])

    for i in xrange(0, num_cols):
        for j in xrange(0, num_rows):
            output_sentence.append(rows[j][i])

    print ''.join(output_sentence)
    num_cols = input()
