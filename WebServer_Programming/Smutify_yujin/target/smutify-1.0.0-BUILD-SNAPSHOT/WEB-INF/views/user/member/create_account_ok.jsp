<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<link href="<c:url value='/202020179/resources/css/member/message.css' />" rel="stylesheet" type="text/css">
<jsp:include page="../../include/title.jsp" />
<jsp:include page="../../include/header.jsp" />

</head>
<body>


	
	<jsp:include page="../include/nav.jsp" />
	
	<section>
		
		<div id="section_wrap">
		
			<div class="word">
			
				<h3>CREATE ACCOUNT SUCCESS!!</h3>
				
			</div>
			
			<div class="others">
				
				<a href="<c:url value='/202020179/user/member/loginForm' />">Login</a>
				
			</div>
		
		</div>
		
	</section>
	
	<jsp:include page="../../include/footer.jsp" />
	
</body>
</html>