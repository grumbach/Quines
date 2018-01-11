/*
    comment
*/
const defone = require('fs');
const deftwo = (a) => {defone.writeFile("Grace_kid.js", a, (err) => {if(err) {return console.log(err)}});}
const defthree = () => {deftwo("/*\n    comment\n*/\nconst defone = require('fs');\nconst deftwo = " + deftwo + "\nconst defthree = " + defthree + "\n\ndefthree()\n")}

defthree()
