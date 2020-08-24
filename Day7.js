
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() 
{
    return inputString[currentLine++];
}

function countSort(arr) 
{
  
    for(let i=0; i<arr.length/2; i++)
    {
        arr[i][1] = '-';
    }

    let counts = {}, sorted = []
    arr.forEach(ar => counts.hasOwnProperty(ar[0]) ? counts[ar[0]]++ : counts[ar[0]]=1)

    for (let n in counts)
    {
        let numArr = []
        arr.forEach(ar => ar[0] === n ? numArr.push(ar[1]) : null)
        sorted.push(numArr)
    }

    console.log(sorted.map(ar => ar.join(' ')).join(' '))

}

function main() 
{
    const n = parseInt(readLine().trim(), 10);

    let arr = Array(n);

    for (let i = 0; i < n; i++) 
    {
        arr[i] = readLine().replace(/\s+$/g, '').split(' ');
    }

    countSort(arr);

}