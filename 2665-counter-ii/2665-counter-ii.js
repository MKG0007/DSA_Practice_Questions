/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    const val = init;
    const obj = {
        increment : ()=>{
            return ++init;
        },
        decrement : ()=>{
            return --init;
        },
        reset : ()=>{
            init = val;
            return val;
        }
    }

    return obj;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */