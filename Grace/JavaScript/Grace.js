/*
    Author: mhufflep
*/

const child = "Grace_kid.js";
const write = `require('fs').writeFile("Grace_kid.js", data(data.toString()), function(err) {});`;
const data = (x) => `/*\n    Author: mhufflep\n*/\n\nconst child = \"${child}\";\nconst write = \`${write}\`;\nconst data = ${x};\neval(write);`;
eval(write);