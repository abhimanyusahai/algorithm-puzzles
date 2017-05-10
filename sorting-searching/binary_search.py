# Implementation of binary search (array sorted in ascending order)
# Return index if number found, else return -1

def binary_search_helper(arr, first, last, value):
    if last >= first:
        mid_idx = (first + last)/2

        if value < arr[mid_idx]:
            result = binary_search_helper(arr, first, mid_idx-1, value)
        elif value > arr[mid_idx]:
            result = binary_search_helper(arr, mid_idx+1, last, value)
        else:
            result = mid_idx
    else:
        result = -1

    return result


def binary_search(arr, value):
    return binary_search_helper(arr, 0, len(arr)-1, value)


def main():
    input_arr = [2, 3, 6, 7, 10, 17, 20, 21]
    print binary_search(input_arr, 20)


if __name__ == "__main__":
    main()
