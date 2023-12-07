type Fn = (n: number, i: number) => any;

function filter(arr: number[], fn: Fn): number[] {
  var result: number[] = [];
  arr.forEach((e, i) => {
    if (fn(e, i)) {
      result.push(e);
    }
  });
  return result;
}
