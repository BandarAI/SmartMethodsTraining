document.addEventListener("DOMContentLoaded", function() 
{
  function registerMovement(direction) {
    var xhr = new XMLHttpRequest();
    xhr.open("POST", "register_movement.php", true);
    xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xhr.onreadystatechange = function() {
      if (xhr.readyState === 4 && xhr.status === 200) {
        console.log(xhr.responseText);
      }
    };
    xhr.send("direction=" + direction);
  }

  document.getElementById("forwardBtn").onclick = function() 
  {
    registerMovement("forward");
  };

  document.getElementById("rightBtn").onclick = function() 
  {
    registerMovement("right");
  };

  document.getElementById("stopBtn").onclick = function() 
  {
    registerMovement("stop");
  };

  document.getElementById("leftBtn").onclick = function() 
  {
    registerMovement("left");
  };

  document.getElementById("backwardBtn").onclick = function()
  {
    registerMovement("backward");
  };
});
