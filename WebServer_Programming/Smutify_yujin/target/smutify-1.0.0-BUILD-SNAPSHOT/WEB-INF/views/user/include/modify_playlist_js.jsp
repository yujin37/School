<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<script type="text/javascript">

	function modifyPlaylist() {
		console.log('modifyPlaylist() CALLED!!');
		
		let form = document.modify_playlist_form;
		
		if (form.s_u_name.value == '') {
			alert('INPUT PLAYLIST NAME.');
			form.s_u_name.focus();
			
		} else if (form.s_u_content.value == '') {
			alert('INPUT PLAYLIST CONTENT.');
			form.s_u_content.focus();
			
		} else {
		
			form.submit();
			
		}
		
	}

</script>