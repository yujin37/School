<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<script type="text/javascript">

	function createAccountForm() {
		console.log('createAccountForm() CALLED!!');
		
		let form = document.create_account_form;
		
		if (form.u_m_username.value == '') {
			alert('INPUT USERNAME.');
			form.u_m_username.focus();
			
		} else {
		
			form.submit();
			
		}
		
	}

</script>