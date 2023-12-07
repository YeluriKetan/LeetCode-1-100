function map(arr: number[], fn: (n: number, i: number) => number): number[] {
  var result = [...arr];
  result.forEach((e, i) => (result[i] = fn(e, i)));
  return result;
}
