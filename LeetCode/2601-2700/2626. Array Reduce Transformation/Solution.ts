type Fn = (accum: number, curr: number) => number;

function reduce(nums: number[], fn: Fn, init: number): number {
  var curr = init;
  nums.forEach(e => curr = fn(curr, e));
  return curr;
}
