/* Author: mhufflep */

const child = "Grace_kid.js";
const write = `require('fs').writeFile("Grace_kid.js", data(data.toString()), function(err) {});`;
const data = (x) => `/* Author: mhufflep */\n\nconst child = \"${child}\";\nconst write = \`${write}\`;\nconst data = ${x};\neval(write);`;
eval(write);