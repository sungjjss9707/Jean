<?php
    $con = mysqli_connect("localhost", "sungjjss9707", "tjdnffhrkwk82!", "sungjjss9707");
    mysqli_query($con,'SET NAMES utf8');

    $userID = $_POST["userID"];
    $Store_name = $_POST["Store_name"];
    $Store_openorclose = $_POST["Store_openorclose"];
    $statement = mysqli_prepare($con, "UPDATE STORE SET Store_openorclose=? WHERE Store_name = ? AND Store_hostid = ?");
    mysqli_stmt_bind_param($statement, "sss", $Store_openorclose, $Store_name, $userID);
    mysqli_stmt_execute($statement);


    $response = array();
    $response["success"] = true;
 
   
    echo json_encode($response);

?>
