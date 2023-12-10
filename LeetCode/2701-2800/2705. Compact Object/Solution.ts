type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function isNested(val: JSONValue): boolean {
  return val instanceof Array || val instanceof Object;
}

function compactObject(obj: Obj): Obj {
  if (obj instanceof Array) {
    return obj.filter(e => e).map((e) => 
        // @ts-ignore
        isNested(e) ? compactObject(e) : e)
  } else {
    var res = {};
    for (const [key, val] of Object.entries(obj)) {
      if (Boolean(val).valueOf()) {
        // @ts-ignore
        res[key] = isNested(val) ? compactObject(val) : val;
      }
    }
    return res;
  }
}
