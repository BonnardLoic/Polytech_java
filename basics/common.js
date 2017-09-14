
function xmultiLang() {
  var body = document.getElementsByTagName("body");
  // body.setAttribute("lang","en-US");
  //body.setAttribute("lang","fr");
  var z, i, elem, innerHTML;
  z = document.getElementsByTagName("xfr");
  for (i = 0; i < z.length; i++) {
    child = z[i];
    var parent = child.parentElement;
    var innerHTML;
    innerHTML = '<button id="flag-en" onclick="doXTranslate(this)"></button>';
    innerHTML += '<p lang="fr">';
    // style="display: none; border: 1px solid black; margin: 1px; width: 100%; margin-left: 0%"
    var text = child.textContent;
    var wtext = child.wholeContent;
    innerHTML += child.innerHTML;
    innerHTML += '</p>';
    child.innerHTML = innerHTML;
  } 
}

function doXTranslate(self) {
  var parent = self.parentElement;
  var child = parent.firstChild;
  while (child) {
    if (child.localName == "p" && child.lang == 'fr') {
      if (child.style.display=='none' || child.style.display=='')
	child.style.display='block';
      else
	child.style.display='none';
      return;
    }
    child = child.nextSibling;
  };
}

function multiLang() {

  xmultiLang();
  
  var body = document.getElementsByTagName("body");
  // body.setAttribute("lang","en-US");
  //body.setAttribute("lang","fr");
  var z, i, elem, innerHTML;
  z = document.getElementsByTagName("m");
  for (i = 0; i < z.length; i++) {
    elem = z[i];
    var child = elem.firstChild;
    var en,fr;
    while (child) {
      var text = child.innerHTML;
      if (child.localName == "en")
	en = text;
      else if (child.localName == "fr")
	fr = text;
      child = child.nextSibling;
    }
    innerHTML = '<div>';
    innerHTML += '<p style="display: block" lang="en-US" >';
    innerHTML += en;
    if (fr) {
      innerHTML += '<button id="flag-en" onclick="doTranslate(this)"></button>';
      innerHTML += '</p>';
      innerHTML += '<p lang="fr" style="display: none; margin: 1px; width: 100%; margin-left: 0%">';
      innerHTML+= fr;
    }
    innerHTML += '</p>';
    innerHTML += '</div>';
    elem.innerHTML = innerHTML;
  } 
}

function doTranslate(self) {
  var parent = self.parentElement.parentElement;
  var child = parent.firstChild;
  while (child) {
    if (child.localName == "p" && child.lang == 'fr') {
      if (child.style.display=='none')
	child.style.display='block';
      else
	child.style.display='none';
      return;
    }
    child = child.nextSibling;
  };
}
