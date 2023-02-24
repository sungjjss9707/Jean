<?php
    $con = mysqli_connect("localhost", "sungjjss9707", "tjdnffhrkwk82!", "sungjjss9707");
    mysqli_query($con,'SET NAMES utf8');

    $Store_name = $_POST["Store_name"];
    
    $response = array();
    $statement = mysqli_prepare($con, "SELECT Store_name,Store_location, Store_hostname FROM STORE WHERE Store_name = ?");
    mysqli_stmt_bind_param($statement, "s", $Store_name);
    mysqli_stmt_execute($statement);

    $result = mysqli_stmt_get_result($statement);
    $rowcnt = mysqli_num_rows($result);
    
    for($i=0; $i<$rowcnt; $i++){
        
	$row = mysqli_fetch_array($result, MYSQLI_ASSOC);
	$response[$i] = $row;
    }
   
    echo json_encode($response);

?>
