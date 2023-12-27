<%@page import="com.company.smutify.user.member.UserMemberVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<link href="<c:url value='/202020179/resources/css/member/include/nav.css' />" rel="stylesheet" type="text/css">

<nav>
	
	<div id="nav_wrap">
		
		<%
		UserMemberVo loginedMemberVo = (UserMemberVo) session.getAttribute("loginedMemberVo");
		if (loginedMemberVo != null) {
		%>
		
		<div class="menu">
			<ul>
				<li><a href="<c:url value='/202020179/song/user/main' />">| Main</a></li>
				<li><a href="<c:url value='/202020179/song/user/searchSong' />">| Search</a></li>
				<li><a href="<c:url value='/202020179/user/member/logoutConfirm' />">| Logout</a></li>
				<li><a href="<c:url value='/202020179/user/member/myAccount' />">My account</a></li>
				
				
				
				
			</ul>
		</div>
		<%
		} else {
		%>
		<div class="menu">
			<ul>
				<li><a href="<c:url value='/202020179/user/member/loginForm' />">| Login</a></li>
				<li><a href="<c:url value='/202020179/user/member/createAccountForm' />">Create Account</a></li>
			</ul>
		</div>
		<%
		}
		%>
		
	</div>
	
</nav>