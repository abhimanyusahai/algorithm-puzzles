# Implementation of bubble sort -- sort integers in ascending order

def bubble_sort(arr):
    for j in range(len(arr)-1, 0, -1):
        for i in range(0, j):
            if arr[i+1] < arr[i]:
                temp = arr[i+1]
                arr[i+1] = arr[i]
                arr[i] = temp


def main():
    input_arr = [5, 6, 2, 9, 10, 4, 3]
    bubble_sort(input_arr)
    print input_arr


if __name__ == "__main__":
    main()
