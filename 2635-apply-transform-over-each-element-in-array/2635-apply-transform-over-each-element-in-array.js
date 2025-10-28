/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let len = arr.length;
    for(let i = 0 ; i<len ; i++){
        arr[i] = fn(arr[i] , i);
    }

    return arr;
    
};