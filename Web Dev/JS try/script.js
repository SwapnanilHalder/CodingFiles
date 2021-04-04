let enter = document.getElementById("enter");
let input = document.getElementById("userinput");
let ul = document.getElementById("unordered_list");


function createListElement() {
    let new_li = document.createElement("li");
    new_li.appendChild(document.createTextNode(input.value));
    ul.appendChild(new_li);
    input.value = "";
}

function addListAfterClick() {
    if (input.value != "") {
        createListElement();
    }
}

function addListAfterEnter(event) {
    if (input.value != "" && event.key == "Enter") {
        createListElement();
    }
}

enter.addEventListener("click", addListAfterClick,);
input.addEventListener("keypress", addListAfterEnter,);


