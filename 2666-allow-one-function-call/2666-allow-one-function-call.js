/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let used=false;
    let result;
    return function(...args){
        if(!used){
            result=fn(...args);
            used=true;
            return result;
        }
        return undefined;
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
