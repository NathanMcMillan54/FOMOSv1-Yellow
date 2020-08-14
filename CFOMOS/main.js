const { app, BrowserWindow, screen} = require('electron');

app.whenReady().then(wifiWindow);

function wifiWindow(){
    const { width, height } = screen.getPrimaryDisplay().workAreaSize;
    let wifi = new BrowserWindow({
        fullscreen: true,
        width: width * 90,
        height: height * 90,
        webPreferences: {
            nodeIntegration: true
        }
    });
    wifi.loadFile('wifi.html');
    wifi.show();
}

exports.wifiWindow = wifiWindow;
