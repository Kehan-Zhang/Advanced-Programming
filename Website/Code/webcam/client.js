"use strict"

let width = 200, height = 150;

var originVideo = document.getElementById("originVideo");
var filterVideo = document.getElementById("filterVideo");
var takePhoto = document.getElementById("takePhoto");
var clear = document.getElementById("clear");
var photos = document.getElementById("photos")
var canvas = document.getElementById("canvas");
var filter = document.getElementById("filter");

canvas.setAttribute("width", width);
canvas.setAttribute("height", height);

function start() {
    if(!navigator.mediaDevices || !navigator.mediaDevices.getUserMedia){
        console.log('broswer is not support mediaStream');
        return;
    }

    var constrains={
        audio:false,
        video:{
            weight:400,
            height:300,
            framerate:24
        }
    };
    navigator.mediaDevices.getUserMedia(constrains)
        .then ((mediaStream)=>{
            originVideo.srcObject = mediaStream;
            filterVideo.srcObject = mediaStream;
            return navigator.mediaDevices.enumerateDevices();
        })
        
        .catch(handleErr);
}

function handleErr(err){
    console.log(err.name + ":" + err.message);
}

function takePicture() {
    const context = canvas.getContext("2d");
    canvas.width = width;
    canvas.height = height;

    context.drawImage(originVideo, 0, 0, width, height);
    const imageUrl = canvas.toDataURL("image/png");
    const image = document.createElement("img");
    image.setAttribute("src", imageUrl);
    image.style.filter = filter;
    photos.appendChild(image);
}

start();

filter.addEventListener("change", function(e) {
    filter = e.target.value;
    filterVideo.style.filter = filter;
    e.preventDefault();
})

takePhoto.addEventListener("click", function(e) {
    takePicture();
}, false);

clear.addEventListener("click", function(e) {
    photos.innerHTML = "";
}) 


