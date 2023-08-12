<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "robot_db";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "GET") {
    if (isset($_GET["direction"]) && isset($_GET["x"]) && isset($_GET["y"])) {
        $direction = $_GET["direction"];
        $x = $_GET["x"];
        $y = $_GET["y"];
        
        if ($direction == "delete") {
            $x = 0;
            $y = 0;
        }

        $sql = "INSERT INTO map (direction, x, y) VALUES ('$direction', $x, $y)";
        
        if ($conn->query($sql) === TRUE) {
            echo "Data saved successfully";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    }
}

$conn->close();
?>
