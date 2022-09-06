const cm = /* Author: mhufflep */ "/* Author: mhufflep */";

const write = (data) => {
    const fs = require('fs');
    fs.writeFile("Grace_kid.js", data, function(err) {});
};
const data = () => {
    return `const cm = ${cm.toString()} \"${cm.toString()}\";\n\nconst write = ${write.toString()};\nconst data = ${data.toString()};\nwrite(data());`;
};
write(data());