# Insertion sort implementation -- sort integers in ascending order

def insertion_sort(arr):
    l = len(arr)
    for idx1 in range(1, l):
        current_num = arr[idx1]
        position = idx1
        while (position > 0) and (arr[position-1] > current_num):
            arr[position] = arr[position-1]
            position -= 1
        arr[position] = current_num


def main():
    input_arr = [5, 6, 2, 9, 10, 4, 3]
    insertion_sort(input_arr)
    print input_arr


if __name__ == "__main__":
    main()
