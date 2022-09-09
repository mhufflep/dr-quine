/*
    Author: mhufflep
*/

const write = `require('fs').writeFile("Grace_kid.js", data(data.toString()), function(err) {});`;
const execute = (x) => { eval(x) };
const data = (x) => `/*\n    Author: mhufflep\n*/\n\nconst write = \`${write}\`;\nconst execute = ${execute.toString()};\nconst data = ${x};\nexecute(write);`;
execute(write);