<html>
<body>


<?php 
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
	echo "Welcome stranger ur name is "; echo $_POST["name"]; echo "<br>\n";
	echo "And ur email is " ; echo $_POST["email"]; echo "<br>\n";
	echo "POST METHOD WAS USED";
}

if ($_SERVER['REQUEST_METHOD'] === 'GET')
{
	echo "Welcome stranger ur name is "; echo $_GET["name"]; echo "<br>\n";
	echo "And ur email is " ; echo $_GET["email"]; echo "<br>\n";
	echo "GET METHOD WAS USED";
}
?>



</body>
</html>

