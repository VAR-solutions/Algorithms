const queue = [];

module.exports = {
  get: function() {
    queue.shift();
  },
  add: function(item) {
    queue.push(item);
  },
  clear: function() {
    queue = [];
  }
}
