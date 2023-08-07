<?php

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "robot_db";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

function insertText($texts) {
    global $conn;

    $sql = "INSERT INTO speech_recognition (texts) VALUES ('$texts')";

    if ($conn->query($sql) === TRUE) {
        echo "Text registered.";
    } else {
        echo "Text not registered: " . $sql . "<br>" . $conn->error;
    }
}

if (isset($_POST['texts'])) {
    $texts = $_POST['texts'];
    insertText($texts);
} else {
    echo "Text error.";
}
?>