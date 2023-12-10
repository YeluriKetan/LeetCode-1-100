type Fn = (...params: number[]) => number;

function memoize(fn: Fn): Fn {
  var cacheMap: Map<string, number> = new Map();
  return function (...args: number[]): number {
    var hash = args.toString();
    if (!cacheMap.has(hash)) {
      cacheMap.set(hash, fn(...args));
    }
    return cacheMap.get(hash);
  };
}

/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */
