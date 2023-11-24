<?php
$servername = "localhost";
$username = "root";
$password ="";
$dbname="student";
$conn=new mysqli($servername,$username,$password,$dbname);
if(!$conn)
{
die('Could not connect: '.mysql_connect_error());
}
echo 'Connected successfully<br/>';
$u=$_POST["user"];
$p=$_POST["pass"];
$sql="SELECT name,password FROM user where name= '{$u}'";
$result = $conn->query($sql);
if($result->num_rows > 0)
{
//output data of each row
while($row = $result->fetch_assoc()) {
if($row["name"]==$u && $row["password"]==$p)
{
echo "You have been successfully Validated";
}
else
{
echo "Credentials Wrong, Try again";
}
}
}
else
{
echo "User name given was not exist";
}
$conn->close();
header("refresh:2; url=home.html");
?>