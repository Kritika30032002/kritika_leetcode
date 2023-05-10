/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let value=init;
    for(let i=0;i<nums.length;i++){
        value = fn(value, nums[i]);
    }
    return value;
};



// https://leetcode.com/problems/array-reduce-transformation/discuss/3506475/5-Diff-Method-or-Solution-in-TypeScript-and-JS-or-Learn-JS-with-Question-or-Day-6