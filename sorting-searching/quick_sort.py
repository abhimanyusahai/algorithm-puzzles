# Implementation of quick sort - sort integers in descending order


def quick_sort_helper(arr, left_idx, right_idx):
    if left_idx < right_idx:
        pivot_idx = partition(arr, left_idx, right_idx)
        quick_sort_helper(arr, left_idx, pivot_idx - 1)
        quick_sort_helper(arr, pivot_idx + 1, right_idx)


def partition(arr, left_idx, right_idx):
    pivot_element = arr[left_idx]
    left_marker = left_idx + 1
    right_marker = right_idx

    done = False
    while not done:
        while left_marker <= right_marker and arr[left_marker] <= pivot_element:
            left_marker += 1
        while arr[right_marker] >= pivot_element and right_marker >= left_marker:
            right_marker -= 1
        if right_marker < left_marker:
            done = True
        else:
            temp = arr[left_marker]
            arr[left_marker] = arr[right_marker]
            arr[right_marker] = temp

    arr[left_idx] = arr[right_marker]
    arr[right_marker] = pivot_element

    return right_marker


def quick_sort(arr):
    quick_sort_helper(arr, 0, len(arr)-1)


def main():
    input_arr = [5, 6, 2, 9, 10, 98, 4, 3]
    quick_sort(input_arr)
    print input_arr


if __name__ == "__main__":
    main()
