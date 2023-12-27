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
<link href="<c:url value='/202020179/resources/css/member/create_playlist.css' />" rel="stylesheet" type="text/css">
<jsp:include page="../include/modify_playlist_js.jsp" />

</head>
<body>

	
	
	
	
	<section>
		
		<div id="section_wrap">
		
			<div class="word">
			
				<h3>플레이리스트 수정하기</h3>
				
			</div>
		
			<div class="create_playlist_form">
			
				<form action="<c:url value='/202020179/song/user/modifyPlaylistConfirm' />" name="modify_playlist_form" method="post" enctype="multipart/form-data">
					<table>
						<tr>
							<td> <label for="file">파일 선택: </label> </td>
							<td> <input type="hidden" name="s_u_no" value="${playListVos[0].s_u_no}">
								<input type="file" name="file"> 
							</td>
						</tr>
						<tr>
							<td> <label for="s_u_name">이름: </label> </td>
							<td> <input type="text" name="s_u_name" value = "${playListVos[0].s_u_name}" placeholder="INPUT USER Name."> </td>
						</tr>
						<tr>
							<td> <label for="s_u_content">소개글: </label> </td>
							<td> <input type="text" name="s_u_content" value = "${playListVos[0].s_u_content}" placeholder="INPUT USER Content."> </td>
						</tr>
						
					
					</table>
					<input type="button" value="수정하기" onclick="modifyPlaylist();"> 
				</form>
				
			</div>
			
		
		</div>
		
	</section>
	
	<jsp:include page="../../include/footer.jsp" />
	
</body>
</html>