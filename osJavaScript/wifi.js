var exec = require('child_process').exec;

function localSsid() {
    var localSsid = exec('sh osShellScripts/localSsid.sh', (err, stdout, stderr) => {
        if (err) {
            console.log(`exec error: ${err}`);
            return;
        }
        document.getElementById("localSsid").innerHTML = `${stdout}`
    })
}

localSsid();
