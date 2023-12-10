type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (
  arr: MultiDimensionalArray,
  n: number
): MultiDimensionalArray {
  if (n === 0) {
    return arr;
  }
  return arr.flatMap(e => {
    return typeof e === "number" ? e : flat(e, n - 1);
  });
};
