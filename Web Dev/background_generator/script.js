let color1 = document.querySelector("input[name=color1]");
let color2 = document.querySelector("input[name=color2]");
let css = document.querySelector("h3");
let body = document.getElementById("gradient");

var selectedColor1 = '#ff0000', selectedColor2='#00ff00';

console.log(body);
color1.addEventListener("input", function() {
    selectedColor1 = color1.value;
    body.style.background = 'linear-gradient(to right, '+ selectedColor1+ ' 0%, '+ selectedColor2+' 100%)';
})

color2.addEventListener("input", function() {
    selectedColor2 = color2.value;
    body.style.background = 'linear-gradient(to right, '+ selectedColor1+ ' 0%, '+ selectedColor2+' 100%)';
})

