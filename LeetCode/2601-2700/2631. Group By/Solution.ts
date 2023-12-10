declare global {
  interface Array<T> {
    groupBy(fn: (item: T) => string): Record<string, T[]>;
  }
}

Array.prototype.groupBy = function (fn) {
  var ans = {};
  this.forEach((e) => {
    const key = fn(e);
    if (!ans.hasOwnProperty(key)) {
      ans[key] = [];
    }
    ans[key].push(e);
  });
  return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
