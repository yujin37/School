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
<link href="<c:url value='/202020179/resources/css/member/main.css' />" rel="stylesheet" type="text/css">
<jsp:include page="../include/main_js.jsp" />

</head>
<body>

	
	
	
	
	<section>
		
		<div id="section_wrap">
		
			<div class="word">
			
				<h3>Main</h3>
				
			</div>
			
			<div class="playlist">
				<h3>PlayList</h3>
			</div>
			<div class="button">
				<button id="create_playlist" onclick="create_playlist()">
					Create Playlist 
				</button>
			</div>
			<div class="playlist_list">
				<table>
					<thead>
						<tr>
							<th>썸네일</th>
							<th>플레이리스트 명</th>
							<th>상세보기</th>
							
						</tr> 
					</thead>
					<tbody>
						<c:forEach var="item" items="${playListVos}">
							<tr onClick="location.href='playListDetail?s_u_no=' + ${item.s_u_no}"  style="cursor:pointer;" >
								<td> 
                                    <img src="<c:url value='/202020179/smutifyUploadImg/${item.s_u_thumbnail}'/>"> 
                                </td>
								<td> 
                                    ${item.s_u_name} 
                                </td>
								
								<td> 
                                     <img src="<c:url value='/202020179/resources/img/playlist_icon.png' />">
                                </td>
							</tr>
						</c:forEach>
					</tbody>
				</table>
				
			</div>
		</div>
	</section>
	<jsp:include page="../../include/footer.jsp" />
</body>
</html>