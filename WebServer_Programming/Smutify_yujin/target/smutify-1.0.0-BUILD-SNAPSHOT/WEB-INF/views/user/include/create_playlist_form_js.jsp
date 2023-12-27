<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<script type="text/javascript">

	function createPlaylistForm() {
		console.log('createPlaylistForm() CALLED!!');
		let form = document.create_playlist_form;
		if (form.s_u_name.value == '') {
			alert('INPUT PLAYLIST NAME.');
			form.s_u_name.focus();
			
		}  else if(form.s_u_content.value == ''){
			alert('INPUT PLAYLIST CONTENT');
			form.s_u_content.focus();
		} else if (form.file.value == '') {
			alert('SELECT IMAGE FILE');
			form.s_u_thumbnail.focus();
			
		}
		
		else {
		
			form.submit();
			
		}
		
	}

</script>