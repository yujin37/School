<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<script src="http://code.jquery.com/jquery-3.2.1.min.js"></script>
<script type="text/javascript">

	function deleteSong(p_name, p_id, id) {
		console.log('노래 삭제 요청');
		let result = confirm('노래 ' + p_name + ' 정말로 삭제할까요?');
		if(result)
			location.href="deleteSongConfirm?p_id=" + p_id + "&id=" + id;
	}
	
	function deletePlaylist(p_name, p_id) {
		console.log('플레이리스트 삭제 요청' + p_id);
		let result = confirm('플레이리스트 ' + p_name + '을 삭제할까요? 저장되어있는 노래도 삭제됩니다.');
		if(result)
			location.href="deletePlaylistConfirm?p_id=" + p_id;
	}
	
	function modifyPlaylist(p_id) {
		console.log('플레이리스트 수정 요청');
		location.href="modifyPlaylist?p_id=" + p_id;
	}

</script>