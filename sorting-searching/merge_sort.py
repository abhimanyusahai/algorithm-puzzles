# Implementation of merge sort - sort integers in ascending order

def merge_sort(arr):
    if len(arr) > 1:
        mid_idx = len(arr)/2
        left_half = arr[:mid_idx]
        right_half = arr[mid_idx:]
        merge_sort(left_half)
        merge_sort(right_half)

        # Perform merge
        i = j = k = 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1


def main():
    input_arr = [5, 6, 2, 9, 10, 98, 4, 3, 0]
    merge_sort(input_arr)
    print input_arr


if __name__ == "__main__":
    main()
