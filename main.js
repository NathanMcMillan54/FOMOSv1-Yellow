const { app, BrowserWindow, screen} = require('electron');

app.whenReady().then(startFomos);

async function startFomos() {
   let startfomos = new BrowserWindow({
       fullscreen: true,
       webPreferences: {
           nodeIntegration: true
       }
   });
   startfomos.loadFile('htmlAlerts/strtFOMOS.html');
   startfomos.show();
   await new Promise(r => setTimeout(r, 1500));
   homeScreen();
   startfomos.close();
}

function homeScreen() {
   let homeScreen;
   homeScreen = new BrowserWindow({
       fullscreen: true,
       webPreferences: {
           nodeIntegration: true
       }
   });
   homeScreen.loadFile('htmlUi/homeScreen.html');
   homeScreen.webContents.openDevTools();
}

function settingsWindow(){
   const { width, height } = screen.getPrimaryDisplay().workAreaSize;
   let settings = new BrowserWindow({
           parent: homeScreen,
           fullscreen: false,
           width: width * 0.9,
           height: height * 0.8,
           webPreferences: {
               nodeIntegration: true
           }
       });
       settings.loadFile('htmlUi/settings.html');
       settings.show();
       settings.webContents.openDevTools();
}

exports.settingsWindow = settingsWindow;

