<?php
    $con = mysqli_connect("localhost", "sungjjss9707", "tjdnffhrkwk82!", "sungjjss9707");
    mysqli_query($con,'SET NAMES utf8');

    $userID = $_POST["userID"];
    
    $statement = mysqli_prepare($con, "SELECT * FROM GUEST WHERE userID = ?");
    mysqli_stmt_bind_param($statement, "s", $userID);
    mysqli_stmt_execute($statement);


    mysqli_stmt_store_result($statement);
    mysqli_stmt_bind_result($statement, $userID, $userPassword, $userName, $userPhone);

    $response = array();
    $response["success"] = false;
 
    while(mysqli_stmt_fetch($statement)) {
        $response["success"] = true;      
    }

    echo json_encode($response);



?>
