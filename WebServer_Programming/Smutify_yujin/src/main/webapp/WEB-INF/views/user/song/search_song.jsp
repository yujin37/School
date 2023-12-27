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
										<option value="Balad" ${item.genre eq 'Balad' ? 'selected':'' }>Balad</option>
										<option value="Dance/Electric" ${item.genre eq 'Dance/Electric' ? 'selected':'' }>Dance/Electric</option>
										<option value="RnB" ${item.genre eq 'RnB' ? 'selected':'' }>R&B</option>
										<option value="Hiphop" ${item.genre eq 'Hiphop' ? 'selected':'' }>Hiphop</option>
										<option value="OST/BGM" ${item.genre eq 'OST/BGM' ? 'selected':'' }>OST/BGM</option>
										<option value="Indie" ${item.genre eq 'Indie' ? 'selected':'' }>Indie</option>
										<option value="Pop/acoustic" ${item.genre eq 'Pop/acoustic' ? 'selected':'' }> Pop/acoustic</option>
										<option value="Folk" ${item.genre eq 'Folk' ? 'selected':'' }>Folk</option>
										<option value="Rock/Metal" ${item.genre eq 'Rock/Metal' ? 'selected':'' }>Rock/Metal</option>
									</select>
								
								</td>
								<td> 
                                   
                                   	<select name="selectplaylist" id = "selectplaylist" onchange="addPlaylist(this.value, ${item.id})">
                                   		<option value="" disabled selected>저장할 플레이리스트 선택</option>
                                   	 	<c:forEach var="playList" items="${playListVos}">
                                   	 		<option value="${playList.s_u_no}" >${playList.s_u_name}</option>
                  
                                   	 	</c:forEach>
                                   	 	<option value="create_Playlist"> 새로운 플레이리스트 생성 </option>
                                   	</select>
                                   	
                                   	
                                    
                                </td>
							</tr>
						</c:forEach>
					</tbody>
				</table>
				
			</div>
			
			
	</section>
	<jsp:include page="../../include/footer.jsp" />
</body>
</html>
