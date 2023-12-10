type Fn<T> = () => Promise<T>;

function promiseAll<T>(functions: Fn<T>[]): Promise<T[]> {
  return new Promise((res, rej) => {
    const len = functions.length;
    var ans: T[] = Array<T>(len);
    var count = 0;
    functions.forEach((f, i) => {
      f()
        .then((result) => {
          ans[i] = result;
          count++;
          if (count >= len) {
            res(ans);
          }
        })
        .catch((reason) => rej(reason));
    });
  });
}

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
