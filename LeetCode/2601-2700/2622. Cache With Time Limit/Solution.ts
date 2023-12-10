class TimeLimitedCache {
  cache: Map<number, number>;
  pendingClear: Map<number, number | NodeJS.Timeout>;

  constructor() {
    this.cache = new Map();
    this.pendingClear = new Map();
  }

  set(key: number, value: number, duration: number): boolean {
    var alreadyPresent = this.cache.has(key);
    var clearId = this.pendingClear.get(key);
    clearTimeout(clearId);
    this.cache.set(key, value);
    var newId = setTimeout(() => {
      this.cache.delete(key);
      this.pendingClear.delete(key);
    }, duration);
    this.pendingClear.set(key, newId);
    return alreadyPresent;
  }

  get(key: number): number {
    var val = this.cache.get(key);
    return val === undefined ? -1 : val;
  }

  count(): number {
    return this.cache.size;
  }
}

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
