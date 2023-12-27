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
<link href="<c:url value='/202020179/resources/css/member/my_account.css' />" rel="stylesheet" type="text/css">
<jsp:include page="../include/main_js.jsp" />

</head>
<body>

	
	
	
	
	<section>
		
		<div id="section_wrap">
		
			<div class="word">
			
				<h3>My account</h3>
				
			</div>
			
			<div class="myinfo">
				<p> 내 계정 ${loginedMemberVo.u_m_username} </p>
				
			</div>
		</div>
	</section>
	<jsp:include page="../../include/footer.jsp" />
</body>
</html>