
process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() 
{
    return input_stdin_array[input_currentline++];
}

function main() 
{
    var g = parseInt(readLine());
    var primeNums = [];
    var i, j;

    for (i = 2; i <= 100000; ++i) 
    {
            if (i == 2 || i == 3) 
            {
                primeNums.push(i);
                continue;
            }
            
            if (i % 2 == 0)
                continue;

            var half = i / 2;
            var prime = true;

            for (j = 3; j <= half; j += 2)
                if (i != j && i % j == 0) 
                {
                    prime = false;
                    break;
                }

            if (prime)
                primeNums.push(i);
        }

    for(var a0 = 0; a0 < g; a0++)
    {
        var n = parseInt(readLine());
        var current = 0;
        while (primeNums[current] <= n) ++current;
        if (current % 2 == 0)
            process.stdout.write("Bob\n");
        else
            process.stdout.write("Alice\n");
    }

}