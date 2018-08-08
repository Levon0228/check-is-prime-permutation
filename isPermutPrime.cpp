var newArr = [];
var permArr = [];
var num = 0;

function isPrime(num) {
  if (num > 0) {
    for(let i = 2; i < num/2; ++i) {
      if (num % i === 0) {
        return false;
      }
    }
  } else {
    for(let i = -2; i < num/2; --i) {
      if (num % i === 0) {
        return false;
      }
    }
  }
  return true;
}


function getPermuts(arr) {
  var curr;
  for(let i = 0; i < arr.length; i++) {
  debugger;
    curr = arr[i];
    arr.splice(i,1);
    newArr.push(curr);
    if (arr.length === 0) {
     permArr.push(newArr.slice());
         }
    getPermuts(arr);
    arr.splice(i,0,curr);
    newArr.pop();
     
  }
  return permArr
  
}

function isPermutPrime(num) {
    let arr = [];
    let count = 0;
    while (num > 0) {
      arr.unshift(num % 10);
      num = (num - num % 10) / 10;
      ++count;
    }
    let n = 0;
    var permuts = getPermuts(arr);
    for(let i = 0; i < permuts.length; ++i) {
      for (let j = 0; j < count; ++j) {
       n = n * 10 + permuts[i][j];
      }
      var tmp = isPrime(n);
      if (tmp === true) {
        n = 0;
      } else {
        return tmp;
      }  
    }
  return tmp
}


console.log(isPermutPrime(311));
