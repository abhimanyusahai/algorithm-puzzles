# Implementation of selection sort -- sort integers in descending order

def selection_sort(arr):
    l = len(arr)
    for idx1 in range(0, l-1):
        max_idx = idx1
        for idx2 in range(idx1+1, l):
            if arr[idx2] > arr[max_idx]:
                max_idx = idx2
        temp = arr[max_idx]
        arr[max_idx] = arr[idx1]
        arr[idx1] = temp


def main():
    input_arr = [5, 6, 2, 9, 10, 4, 3]
    selection_sort(input_arr)
    print input_arr


if __name__ == "__main__":
    main()
