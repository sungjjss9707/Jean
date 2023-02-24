<?php
    $con = mysqli_connect("localhost", "sungjjss9707", "tjdnffhrkwk82!", "sungjjss9707");
    mysqli_query($con,'SET NAMES utf8');

    $userID = $_POST["userID"];
    $storenumber;
    $statement = mysqli_prepare($con, "SELECT count(*) FROM STORE WHERE Store_hostid = ?");
    mysqli_stmt_bind_param($statement, "s", $userID);
    mysqli_stmt_execute($statement);


    mysqli_stmt_store_result($statement);
    mysqli_stmt_bind_result($statement, $storenumber);

    $response = array();
    $response["success"] = false;
 
    $response["success"] = true;
    $response["storenumber"] = $storenumber;
        
       
    

    echo json_encode($response);



?>
