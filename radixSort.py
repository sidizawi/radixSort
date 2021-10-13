import sys

def countingSort(arr, div):
    n = len(arr)
    out = [0]*n
    count = [0]*10

    for x in arr:
        count[(x // div)%10] += 1
    
    for i in range(1, 10):
        count[i] += count[i - 1]

    for x in arr[::-1]:
        indx = (x // div)%10
        out[count[indx] - 1] = x
        count[indx] -= 1
    
    for i in range(n):
        arr[i] = out[i]

def radixSort(arr):
    m = max(arr)
    div = 1
    while m // div:
        countingSort(arr, div)
        div *= 10

if __name__ == '__main__':
    arr = list(map(int, sys.argv[1:]))
    radixSort(arr)
    print(arr)
