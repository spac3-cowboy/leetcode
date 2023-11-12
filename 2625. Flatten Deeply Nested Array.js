/**
 * This function flattens a multi-dimensional array up to a specified depth.
 *
 * @param {any[]} arr - The array to be flattened.
 * @param {number} depth - The maximum depth to flatten.
 * @return {any[]} - The flattened array.
 */
var flat = function(arr, depth) {
    // Initialize a stack with the array items and their corresponding depth.
    const stack = [...arr.map(item => [item, depth])];
    // Initialize an empty array to store the result.
    const result = [];
  
    // Loop until the stack is empty.
    while (stack.length > 0) {
      // Pop an item and its depth from the stack.
      const [item, depth] = stack.pop();
  
      // If the item is an array and the depth is greater than 0,
      // push its items onto the stack with a decremented depth.
      if (Array.isArray(item) && depth > 0) {
        stack.push(...item.map(subItem => [subItem, depth - 1]));
      } else {
        // Otherwise, push the item onto the result array.
        result.push(item);
      }
    }
  
    // Reverse the result array to get the items in the original order and return it.
    return result.reverse();
  };