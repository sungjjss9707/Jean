<?php 
    $con = mysqli_connect("localhost", "sungjjss9707", "tjdnffhrkwk82!", "sungjjss9707");
    mysqli_query($con,'SET NAMES utf8');

    $userID = $_POST["userID"];
    $userPassword = $_POST["userPassword"];
    $userName = $_POST["userName"];
    $userPhone = $_POST["userPhone"];
	
    $statement = mysqli_prepare($con, "INSERT INTO GUEST VALUES (?,?,?,?)");
    mysqli_stmt_bind_param($statement, "ssss", $userID, $userPassword, $userName, $userPhone);
    mysqli_stmt_execute($statement);


    $response = array();
    $response["success"] = true;
 
   
    echo json_encode($response);



?>
