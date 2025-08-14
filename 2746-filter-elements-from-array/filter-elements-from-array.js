/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const ans = [];
    for (let i = 0; i < arr.length; i++) {
        if (fn(arr[i], i)) {  // keep only truthy results
            ans.push(arr[i]);
        }
    }
    return ans;
};
