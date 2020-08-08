const { app, BrowserWindow, screen} = require('electron');

app.whenReady().then(startFomos);

async function startFomos() {
    const { width, height } = screen.getPrimaryDisplay().workAreaSize;
   let startfomos = new BrowserWindow({
       fullscreen: true,
       width: 100,
       height: 100,
       webPreferences: {
           nodeIntegration: true
       }
   });
   startfomos.loadFile('htmlAlerts/strtFOMOS.html');
   startfomos.show();
   await new Promise(r => setTimeout(r, 3500));
   homeScreen();
   startfomos.close();
}

function homeScreen() {
   const { width, height } = screen.getPrimaryDisplay().workAreaSize;
   let homeScreen = new BrowserWindow({
       fullscreen: true,
       width: width * 100,
       height: height * 100,
       webPreferences: {
           nodeIntegration: true
       }
   });
   homeScreen.loadFile('htmlUi/homeScreen.html');
   homeScreen.show();
}

function settingsWindow(){
   const { width, height } = screen.getPrimaryDisplay().workAreaSize;
   let settings = new BrowserWindow({
       fullscreen: true,
           width: width * 100,
           height: height * 100,
           webPreferences: {
               nodeIntegration: true
           }
       });
       settings.loadFile('htmlUi/settings.html');
       settings.show();
}

function google(){
   const { width, height } = screen.getPrimaryDisplay().workAreaSize;
   let google = new BrowserWindow({
       fullscreen: true,
           width: width * 100,
           height: height * 100,
           webPreferences: {
               nodeIntegration: true
           }
       });
       google.loadURL('https://www.google.com');
       google.show();
}

function calculatorWindow(){
   const { width, height } = screen.getPrimaryDisplay().workAreaSize;
   let calculator = new BrowserWindow({
       fullscreen: true,
           width: width * 100,
           height: height * 100,
           webPreferences: {
               nodeIntegration: true
           }
       });
       calculator.loadFile('htmlUi/calculator.html');
       calculator.show();
}

exports.settingsWindow = settingsWindow;

exports.google = google;

exports.calculatorWindow = calculatorWindow;
