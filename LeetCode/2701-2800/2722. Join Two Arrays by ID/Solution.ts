type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };

function join(arr1: JSONValue[], arr2: JSONValue[]): JSONValue[] {
  var combined = arr1.concat(arr2).sort((a, b) => a["id"] - b["id"]);
  if (combined.length === 0) return [];
  var prev: JSONValue = combined[0];
  var result: JSONValue[] = [];
  for (let i = 0; i < combined.length; i++) {
    // @ts-ignore
    if (combined[i].id === prev.id) {
      // @ts-ignore
      prev = { ...prev, ...combined[i] };
    } else {
      result.push(prev);
      prev = combined[i];
    }
  }
  result.push(prev);
  return result;
}
