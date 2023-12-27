package com.company.smutify.user;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/user")
public class UserHomeController {
	
	@GetMapping({"", "/"})
	public String home() {
		System.out.println("[UserHomeController] login");
		
		String nextPage = "user/member/login_form";
		
		return nextPage;
	}
}