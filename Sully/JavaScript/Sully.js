const n = 5;

const main = (data) => {
    const name = `Sully_${n - 1}.js`;
    require('fs').writeFile(name, data, function(err) {});
    if (n > 0) {
        require('child_process').fork(name);
    }
};
const data = () => {
    return `const n = ${n - 1};\n\nconst main = ${main.toString()};\nconst data = ${data.toString()};\nmain(data());`;
};
main(data());