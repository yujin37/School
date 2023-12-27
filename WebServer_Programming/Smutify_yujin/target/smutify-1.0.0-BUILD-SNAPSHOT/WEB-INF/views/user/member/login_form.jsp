<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<jsp:include page="../../include/title.jsp" />
<jsp:include page="../../include/header.jsp" />
<jsp:include page="../include/nav.jsp" />

<jsp:include page="../include/login_js.jsp" />
<link href="<c:url value='/202020179/resources/css/member/login.css' />" rel="stylesheet" type="text/css">
</head>
<body>

	
	
	
	
	<section>
		
		<div id="section_wrap">
		
			<div class="word">
			
				<h3>Smutify LOGIN FORM</h3>
				
			</div>
		
			<div class="login_form">
			
				<form action="<c:url value='/202020179/user/member/loginConfirm' />" name="login_form" method="post">
					
					<input type="text" name="u_m_username" placeholder="INPUT USERNAME."> <br>
		
					<input type="button" value="Login" onclick="loginForm();"> 
					
					
				</form>
				
			</div>
			
		
		</div>
		
	</section>
	
	<jsp:include page="../../include/footer.jsp" />
	
</body>
</html>