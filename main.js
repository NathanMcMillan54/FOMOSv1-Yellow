const { app, BrowserWindow} = require('electron');

app.whenReady().then(wifiWindow);

function wifiWindow(){
    let wifi = new BrowserWindow({
        fullscreen: true,
        width: 900,
        height: 900,
        webPreferences: {
            nodeIntegration: true
        }
    });
    wifi.loadFile('index.html');
    wifi.show();
}

exports.wifiWindow = wifiWindow;
