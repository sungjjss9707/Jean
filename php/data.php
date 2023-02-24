<?php
	$con = mysqli_connect("localhost", "sungjjss9707", "tjdnffhrkwk82!", "sungjjss9707"); 

	if (mysqli_connect_errno())
	{
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}

   $num = $_GET["num"];

   $sql = "insert into STORE(Store_current) values ($num)";
   mysqli_query($con, $sql);

   mysqli_close($con);
?>

