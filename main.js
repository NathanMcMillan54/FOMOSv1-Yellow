const {app, BrowserWindow, screen} = require('electron');

app.whenReady().then(mainWindow);

function mainWindow() {
    let mainWindow = new BrowserWindow({
        fullscreen: true,
        webPreferences: {
            nodeIntegration: true
        }
    });
    mainWindow.loadFile("htmlUi/index.html");
}

