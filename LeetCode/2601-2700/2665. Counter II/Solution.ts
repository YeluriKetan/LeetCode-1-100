type ReturnObj = {
  increment: () => number;
  decrement: () => number;
  reset: () => number;
};

function createCounter(init: number): ReturnObj {
  var curr: number = init;
  return {
    increment: () => ++curr,
    decrement: () => --curr,
    reset: () => {
      curr = init;
      return curr;
    }
  }
}

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
