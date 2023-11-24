<?php
$servername = "localhost";
$username = "root";
$password ="";
$dbname="student";
$conn=new mysqli($servername,$username,$password,$dbname);
if(!$conn)
{
die('Could not connect: '.mysqli_connect_error());
}
echo 'Connected successfully<br/>';
$stmt = $conn->prepare("INSERT INTO user(name,password) VALUES(?,?)");
$stmt->bind_param("ss",$u,$p);
//set parameters and execute
$u=$_POST["user"];
$p=$_POST["pass"];
$stmt->execute();
echo "Record inserted successfully";
$stmt->close();
$conn->close();
header("refresh:2; url=home.html");
?>