const electron= require('electron');
const main = electron.remote.require('./main.js');

var settingsBtn = document.getElementById('settingsBtn');

settingsBtn.addEventListener('click', function () {
    main.settingsWindow();
})
