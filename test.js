/**
 * @param {number[]} arr
 * @return {boolean}
 */
var canMakeArithmeticProgression = function (arr) {
  if (arr.length == 1 || arr.length == 0) {
    return false;
  } else if (arr.length == 2) {
    return true;
  } else {
    arr.sort();
    console.log(arr);
    let diff = arr[1] - arr[0];
    for (let i = 2; i < arr.length; i++) {
      if (arr[i] - arr[i - 1] != diff) {
        // console.log("The difference is " + diff2);
        console.log("False through here");
        return false;
      }
    }
    return true;
  }
};
let arr = [-68, -96, -12, -40, 16];
console.log(canMakeArithmeticProgression(arr));
