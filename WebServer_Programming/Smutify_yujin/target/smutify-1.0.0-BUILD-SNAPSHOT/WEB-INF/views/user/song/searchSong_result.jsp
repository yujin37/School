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
<jsp:include page="../include/search_song_js.jsp" />
<link href="<c:url value='/202020179/resources/css/member/search_song.css' />" rel="stylesheet" type="text/css">

</head>
<body>
	
	<section>
		
		<div id="section_wrap">
		
			<div class="word">
			
				<h3>음악 검색하기</h3>
				
			</div>
		</div>
		
		<div class="search">
			
			<form action="<c:url value='/202020179/song/user/searchSongConfirm' />" name="search_song_form" method="get">
				<select name="sort">
						<option value="" selected>정렬 방식</option>
						<option value="title"> 노래 제목 순</option>
						<option value="singer"> 가수 이름 순</option>
						<option value="genre"> 장르 순</option>

				</select>
				<input type="text" name="name" placeholder="검색어를 입력하세요.">
				<input type="button" value="search" onclick="searchSongForm();">
			</form>
			
		</div>
		
		<div class="song_list">
				<table>
					<thead>
						<tr>
							<th>노래제목</th>
							<th>가수이름</th>
							<th>장르</th>
							<th>플레이리스트 추가</th>
						</tr> 
					</thead>
					<tbody>
						<c:forEach var="item" items="${songVos}">
							<tr>
								<td>${item.title}</td>
								<td>${item.singer}</td>
								<td>										
									<select name="genre" id="genre" onchange="changeGenre(this.value, ${item.id})">
										<option value="" ${item.genre eq 'NULL' ? 'selected':'' }>장르 선택</option>
										<option value="balad" ${item.genre eq 'balad' ? 'selected':'' }>발라드</option>
										<option value="dance/elect" ${item.genre eq 'dance/elect' ? 'selected':'' }>댄스/일렉</option>
										<option value="R&B" ${item.genre eq 'R&B' ? 'selected':'' }>알앤비</option>
										<option value="HipPop" ${item.genre eq 'HipPop' ? 'selected':'' }>힙합</option>
										<option value="OST/BGM" ${item.genre eq 'OST/BGM' ? 'selected':'' }>OST/BGM</option>
										<option value="Indie" ${item.genre eq 'Indie' ? 'selected':'' }>인디</option>
										<option value="Pop/acustic" ${item.genre eq 'Pop/acustic' ? 'selected':'' }> 팝/어쿠스틱</option>
										<option value="Folk" ${item.genre eq 'Folk' ? 'selected':'' }>포크</option>
										<option value="Rock" ${item.genre eq 'Rock' ? 'selected':'' }>록/메탈</option>
									</select>
								
								</td>
								<td> 
                                   
                                   	<select name="selectplaylist">
                                   		<option value="" disabled selected>저장할 플레이리스트 선택</option>
                                   	 	<c:forEach var="playlist" items="${playlistVos}">
                                   	 		<option value="${playlist.s_u_no}">${playlist.s_u_name}</option>
                                   	 		<option value="create_Playlist"> 새로운 플레이리스트 생성 </option>
                                   	 	</c:forEach>
                                   	</select>
                                   	
                                   	<input type="submit" value="추가하기"/>
                                    
                                </td>
							</tr>
						</c:forEach>
					</tbody>
				</table>
				
			</div>
			
			
	</section>
</body>
</html>
