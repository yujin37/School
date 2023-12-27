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
<link href="<c:url value='/202020179/resources/css/member/create_account.css' />" rel="stylesheet" type="text/css">
<jsp:include page="../include/create_account_form_js.jsp" />

</head>
<body>

	
	
	
	
	<section>
		
		<div id="section_wrap">
		
			<div class="word">
			
				<h3>USER CREATE ACCOUNT FORM</h3>
				
			</div>
		
			<div class="create_account_form">
			
				<form action="<c:url value='/202020179/user/member/createAccountConfirm' />" name="create_account_form" method="post">
					
					<input type="text" name="u_m_username" placeholder="INPUT USER Name."> <br>
					
					<input type="button" value="회원가입" onclick="createAccountForm();"> 
					
					
				</form>
				
			</div>
			
		
		</div>
		
	</section>
	
	<jsp:include page="../../include/footer.jsp" />
	
</body>
</html>