/**
 * @param {number} millis
 */
async function sleep(millis) {
    await new Promise(resolve => setTimeout(resolve,millis));
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */



// https://www.w3schools.com/Js/js_async.asp