function countingSort(arr, div) {
    let n = arr.length
    let out = Array(n).fill(0)
    let count = Array(10).fill(0)

    for (let x of arr) {
        count[Math.floor(x / div) % 10]++
    }

    for (let i = 1; i < 10; i++) {
        count[i] += count[i - 1]
    }
    
    for (let i = n-1; i >= 0; i--) {
        let indx = Math.floor(arr[i] / div) % 10
        out[count[indx] - 1] = arr[i]
        count[indx]--
    }

    for (let i = 0; i < n; i++) {
        arr[i] = out[i]
    }
}

function radixSort(arr) {
    let m = Math.max(...arr)
    let div = 1
    while (Math.round(m / div) > 0) {
        countingSort(arr, div)
        div *= 10
    }
}

if (require.main.children.length === 0) {
    let arr = process.argv.slice(2)
    arr = arr.map(num => parseInt(num))
    arr = arr.filter(num => Number.isInteger(num))
    radixSort(arr)
    console.log(arr)
}
