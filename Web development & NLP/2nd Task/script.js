const c = document.getElementById("myCanvas");
const ctx = c.getContext("2d");
ctx.lineWidth = 5;
ctx.strokeStyle = "black"; 
let lastx = c.width / 2;   
let lasty = c.height / 2; 
let fragain = 0;
let cright = 0;
let cleft = 0;

document.getElementById("forwardBtn").addEventListener("click", function () {
  moveAndSendData(0, -10, "forward");
});

document.getElementById("rightBtn").addEventListener("click", function () {
  moveAndSendData(10, 0, "right");
});

document.getElementById("leftBtn").addEventListener("click", function () {
  moveAndSendData(-10, 0, "left");
});

document.getElementById("backwardBtn").addEventListener("click", function () {
  moveAndSendData(0, 10, "backward");
});

document.getElementById("delBtn").addEventListener("click", function () {
  moveAndSendData(0, 0, "delete");
});


document.getElementById("delBtn").addEventListener("click", Delete);

function drawPath() {
  ctx.clearRect(0, 0, c.width, c.height);  
  ctx.beginPath();
  ctx.moveTo(lastx - 10, lasty);  
  ctx.lineTo(lastx, lasty);      
  ctx.stroke();
}

function moveAndSendData(xMove, yMove, direction) {
  ctx.moveTo(lastx, lasty);
  lastx += xMove;
  lasty += yMove;
  ctx.lineTo(lastx, lasty);
  ctx.stroke();

  sendData(direction, lastx, lasty);
}

function sendData(direction, x, y) {
  const Http = new XMLHttpRequest();
  const url = `db.php?direction=${direction}&x=${x}&y=${y}`;
  Http.open("GET", url);
  Http.send();
}

function Delete() {
  ctx.clearRect(0, 0, c.width, c.height);
  lastx = c.width / 2;
  lasty = c.height / 2;
}
