const n = parseInt(process.argv[2]);
let compositeNumbers = new Array(n).fill(false);
let primeIterator = 2;
// Probably faster using streams? Maybe make another implementation

console.log('Generating all primes from 2 -> ' + n + '...');
const startTime = console.time('time');

while (primeIterator < n - primeIterator) {
    for (let i = primeIterator * 2; i < n; i += primeIterator) {
        compositeNumbers[i-1] = true;
    }

    for (let i = primeIterator; i < n; i++) {
        if (!compositeNumbers[i]) {
            primeIterator = i + 1;
            break;
        }
    }
}

const endTime = console.timeEnd('time');
console.log('Done!');

//Print out prime numbers from 2 -> n
console.log("Prime numbers");
for (let i = 0; i < n; i++) {
    if (!compositeNumbers[i]) {
        process.stdout.write((i + 1) + ', ');
    }
}
console.log();
console.timeLog('time');
