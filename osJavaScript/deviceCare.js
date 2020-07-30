var exec = require('child_process').exec;

var refreshDeviceCare = setInterval(deviceCare, 10000)
function deviceCare() {
var deviceCare = exec('sh osShellScripts/deviceCare.sh', (err, stdout, stderr) => {
        if (err) {
            console.log(`exec error: ${err}`);
            return;
        }
        document.getElementById("deviceCare").innerHTML = `${stdout}`
    })
}


deviceCare();
