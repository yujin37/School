<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<script src="http://code.jquery.com/jquery-3.2.1.min.js"></script>
<script type="text/javascript">

	function searchSongForm() {
		console.log('searchSongForm() CALLED!!');
		
		let form = document.search_song_form;
		let sortSearch = form.elements["sort"].value;
		if (form.name.value == '' && sortSearch == '') {
			console.log('아무것도 입력하지 않으므로 전체 곡을 출력합니다.');
			location.href = 'searchSong';
			
			
		} else { 
			location.href='searchSongConfirm?sort='+sortSearch+'&name='+form.name.value;
			
		}
		
	}
	function changeGenre(genre, id){
		console.log("장르 변경이 감지되었습니다.");
		let form = document.search_song_form;
		location.href="changeGenreConfirm?id=" + id + "&genre=" + genre;
	
	};
	
	function addPlaylist(name, id){
		console.log('플레이리스트 추가');
		if(name == "create_Playlist")
			location.href="addNewPlaylist?id=" + id;
		else
			location.href="addSongPlaylist?playlist=" + name + "&id=" + id;
	}
	
	

</script>