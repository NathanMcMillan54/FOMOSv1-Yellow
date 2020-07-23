var exec = require('child_process').exec;

function shutdown() {
    var shutdown = exec('sh osShellScripts/shutdown.sh', (err, stdout, stderr) => {
        if (err) {
            console.log(`exec error: ${err}`);
            return;
        }
        document.getElementById("shutdown").innerHTML = `${stdout}`
    })
}
