var exec = require('child_process').exec;

function update() {
    var update = exec('sh osShellScripts/update.sh', (err, stdout, stderr) => {
        if (err) {
            console.log(`exec error: ${err}`);
            return;
        }
        document.getElementById("update").innerHTML = `${stdout}`
    })
}
