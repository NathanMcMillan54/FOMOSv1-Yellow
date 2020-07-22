const electron= require('electron');
const main = electron.remote.require('./main.js');

var settingsBtn = document.getElementById('settingsBtn');

settingsBtn.addEventListener('click', function () {
    main.settingsWindow();
})

var time = setInterval(time, 1000);
function time() {
    var time = new Date();
    document.getElementById("time").innerHTML = time;
}

