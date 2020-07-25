var timeZone = getTimezoneName();
var Time = getCurrentTime();

function getTimezoneName() {
  const today = new Date();
  const short = today.toLocaleDateString(undefined);
  const full = today.toLocaleDateString(undefined, { timeZoneName: 'long' });

  const shortIndex = full.indexOf(short);
  if (shortIndex >= 0) {
    const trimmed = full.substring(0, shortIndex) + full.substring(shortIndex + short.length);
    return trimmed.replace(/^[\s,.\-:;]+|[\s,.\-:;]+$/g, '');

  } else {
    return full;
  }
}

document.getElementById("timeZone").innerHTML = "Time zone: " + timeZone;

function checkTime(i) {
  if (i < 10) {
    i = "0" + i;
  }
  return i;
}

function getCurrentTime() {
  var today = new Date();
  var h = today.getHours();
  var m = today.getMinutes();
  var s = today.getSeconds();
  // add a zero in front of numbers<10
  m = checkTime(m);
  s = checkTime(s);
  document.getElementById('currentTime').innerHTML = "Current time: " + h + ":" + m + ":" + s;
  t = setTimeout(function() {
    getCurrentTime();
  }, 1000);
}

getCurrentTime();
getTimezoneName();
