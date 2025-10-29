/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let once = 1;
    return function(...args){
        let ans;
        if(once){
            ans = fn(...args);
            once = 0;
        }
        return ans;
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
