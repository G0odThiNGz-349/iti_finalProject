const button = document.querySelector("#submit");
button.addEventListener("click" , ()=> {
let name_ = document.getElementById("name").value;
let email = document.getElementById("email").value; 
let feedback = document.getElementById("feedback").value;
    if(name_==="" || email === "" || feedback === ""){
        alert("Please fill the requied info");
    }
    else{
    alert("Thank You For Your Feedback!");}
});