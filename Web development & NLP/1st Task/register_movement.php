<?php

include 'db_connect.php';

function insertMovement($direction) {
    global $conn;

    $sql = "INSERT INTO movements (direction) VALUES ('$direction')";

    if ($conn->query($sql) === TRUE) {
        echo "Direction registered.";
    } else {
        echo "Direction not registered: " . $sql . "<br>" . $conn->error;
    }
}

if (isset($_POST['direction'])) {
    $direction = $_POST['direction'];
    insertMovement($direction);
} else {
    echo "direction error.";
}
?>
