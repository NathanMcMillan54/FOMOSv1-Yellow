var exec = require('child_process').exec;

function localSsid() {
    var localSsid = exec('sh osShellScripts/localSsid.sh', (err, stdout, stderr) => {

        if (err) {
            console.log(`exec error: ${err}`);
            return;
        }
        document.getElementById("localSsid").innerHTML = `${stdout}`;
    });
}


function connectToWifi() {
    event.preventDefault();
    var ssid = document.getElementById("ssid");
    console.log(ssid.value);

    event.preventDefault();
    var password = document.getElementById("password");
    console.log("Password was entered");

    var connectToWifi = exec('sudo sh osShellScripts/connectToWifi.sh ' + ssid.value + ' ' + password.value, (err, stdout, stderr) => {
        if (err) {
            console.log(`exec error: ${err}`);
            return;
        }
        document.getElementById("connectToWifi").innerHTML = `${stdout}`
    })
}

localSsid();
