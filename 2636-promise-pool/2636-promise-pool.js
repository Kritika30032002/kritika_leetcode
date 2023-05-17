/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    async function evaluateNext() {
        if (functions.length === 0) return; // null check to see if array is empty
        const fn = functions.shift(); // the first function will be removed and assigned to `fn`
        await fn(); // just awaiting
        await evaluateNext(); // recursively call the function when done
    }

    const nPromises = Array(n).fill().map(evaluateNext); // with `n` items only, it first creates an empty array and fill it with undefined and then put `evaluateNext` in it (which is a promise itself).
    await Promise.all(nPromises); // call first n item promises 
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */