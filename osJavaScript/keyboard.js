var exec = require('child_process').exec;

function keyboard() {
    var keyboard = exec('sh osShellScripts/keyboard.sh', (err, stdout, stderr) => {
        if (err) {
            console.log(`exec error: ${err}`);
        }
    })
}
