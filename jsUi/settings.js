var timeZone = getTimezoneName();

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
getTimezoneName();
