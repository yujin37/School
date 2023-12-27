<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">

<jsp:include page="../../include/title.jsp" />

<jsp:include page="../include/playlist_detail_js.jsp" />
<link href="<c:url value='/202020179/resources/css/member/playlist_detail.css' />" rel="stylesheet" type="text/css">
</head>
<body>

	<jsp:include page="../../include/header.jsp" />
	
	<jsp:include page="../include/nav.jsp" />
	
	<section>
		
		<div id="section_wrap">
		
			<div class="word">
			
				<h3> [${playListVos[0].s_u_name}] PLAYLIST DETAIL</h3>
				
 			</div>
			
			<div class="playlist_detail">
			
				<ul>
					<li> 
						
						<img src="<c:url value='/202020179/smutifyUploadImg/${playListVos[0].s_u_thumbnail}'/>"> 
						
						<p> 소개 글: ${playListVos[0].s_u_content} </p>
						<br>
						<hr>
					</li>
					<li>
						<table>
							<thead>
								<tr>
									<th> 노래명 </th>
									<th> 가수 </th>
									<th> 장르 </th>
									<th> 삭제 </th>
								</tr>
							</thead>
							
							<tbody>
								
									
								<c:forEach var="item" items="${playListVos}">
									<tr>
										<td> ${item.title} </td>
										<td> ${item.singer} </td>
										<td> ${item.genre} </td>
										<td> 
											<c:if test = "${not empty item.title}">
												<input type="button" value = "삭제하기" onClick="deleteSong('${item.title}',${item.s_u_no},${item.id})"/> 
											</c:if>
										</td>
										
									</tr>
								</c:forEach>
										
									
								
							</tbody>
							
						</table>
					</li>
				</ul>
				
			</div>
			<div id = changeButton>
				<form id = modify_button>
					<input type="button" value="수정하기" onClick="modifyPlaylist(${playListVos[0].s_u_no})">
				</form>
				<form id = delete_button>
					<input type="button" value="삭제하기" onClick="deletePlaylist('${playListVos[0].s_u_name}', ${playListVos[0].s_u_no})">
				</form>
			</div>
		
		</div>
		
	</section>
	
	<jsp:include page="../../include/footer.jsp" />

</body>
</html>