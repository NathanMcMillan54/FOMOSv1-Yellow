const electron= require('electron');
const main = electron.remote.require('./main.js');

var settingsBtn = document.getElementById('settingsBtn');

settingsBtn.addEventListener('click', function () {
    main.settingsWindow();
})

var googleBtn = document.getElementById('googleBtn');

googleBtn.addEventListener('click', function () {
    main.google();
})

var calculatorBtn = document.getElementById('calculatorBtn');

calculatorBtn.addEventListener('click', function () {
    main.calculatorWindow();
})

var time = setInterval(time, 1000);
function time() {
    var time = new Date();
    document.getElementById("time").innerHTML = time;
}

