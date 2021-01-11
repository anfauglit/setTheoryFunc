function getRndInt(max) {
	return Math.floor(Math.random() * Math.floor(max));
}

var A = [1, 2, 3, 4];
var B = [5, 6, 7, 8];

var C = []; // empty array for cartesian product
	A.forEach(x => B.forEach(y => C.push([x, y])));

var dict = {}; // object for the future dictionary

var func = pair => {
	if (pair[0] in dict) {
		dict[pair[0]].push(pair);
	} else {
		dict[pair[0]] = [pair];
	}
}
C.forEach(func);
console.log(dict);

var myFunc = [];
for (var x in dict) {
	let rnd = getRndInt(4);
	myFunc.push(dict[x][rnd]);
}

console.log(myFunc);
