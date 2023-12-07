type ToBeOrNotToBe = {
  toBe: (val: any) => boolean;
  notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
  return {
    toBe: (other: any) => {
      if (val === other) {
        return true;
      } else {
        throw "Not Equal";
      }
    },
    notToBe: (other: any) => {
      if (val !== other) {
        return true;
      } else {
        throw "Equal";
      }
    },
  };
}

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */