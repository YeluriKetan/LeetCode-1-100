type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type Fn = (value: JSONValue) => number;

function sortBy(arr: JSONValue[], fn: Fn): JSONValue[] {
  var indices = arr.map((e, i) => [i, fn(e)]);
  indices.sort((a, b) => a[1] - b[1]);
  return indices.map(e => arr[e[0]]);
}
