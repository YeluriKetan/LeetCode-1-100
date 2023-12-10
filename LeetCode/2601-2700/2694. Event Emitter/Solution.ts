type Callback = (...args: any[]) => any;
type Subscription = {
  unsubscribe: () => void;
};

class EventEmitter {
  eventStore: Map<string, Map<number, Callback>>;
  id: number;

  constructor() {
    this.eventStore = new Map<string, Map<number, Callback>>();
    this.id = 0;
  }

  subscribe(eventName: string, callback: Callback): Subscription {
    const currId = this.id++;
    if (!this.eventStore.has(eventName)) {
      this.eventStore.set(eventName, new Map());
    }
    this.eventStore.get(eventName)?.set(currId, callback);
    return {
      unsubscribe: () => {
        this.eventStore.get(eventName)?.delete(currId);
      },
    };
  }

  emit(eventName: string, args: any[] = []): any[] {
    if (this.eventStore.has(eventName)) {
      const currMap = this.eventStore.get(eventName);
      const iterator = currMap?.values();
      var ind = 0;
      var res = [];
      // @ts-ignore
      while (ind < currMap.size) {
        // @ts-ignore
        res.push(iterator.next().value(...args));
        ind++;
      }
      return res;
    } else {
      return [];
    }
  }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
