<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>SMU BOOK</title>
</head>
<body>
		<h3> SMU BOOK </h3>
		
		<form action="/loginConfirm" method="post">
			UserName : <input type="text" name="m_username"> <br/>
			Password : <input type="password" name="m_pw"> <br/>
			
			<input type="submit" value = "Login">
		</form>
		
		<a href="/smubook/signUp">
			<input type="button" value="SignUp">
		</a>
</body>
</html>