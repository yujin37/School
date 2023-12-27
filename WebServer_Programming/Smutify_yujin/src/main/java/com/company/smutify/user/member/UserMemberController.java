package com.company.smutify.user.member;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;


@Controller
@RequestMapping("/user/member")
public class UserMemberController {
	@Autowired
	UserMemberService userMemberService;
	
	// 회원가입
	@GetMapping("/createAccountForm")
	public String createAccountForm() {
		System.out.println("[UserMemberController] createAccountForm");
		
		String nextPage = "user/member/create_account_form";
		
		return nextPage;
	}
	
	// 회원가입 확인
	@PostMapping("/createAccountConfirm")
	public String createAccountConfirm(UserMemberVo userMemberVo) {
		System.out.println("[UserMemberConroller] createAccountConfirm");
		
		String nextPage = "user/member/create_account_ok";
		
		int result = userMemberService.createAccountConfirm(userMemberVo);
		
		if(result <= 0) 
			nextPage = "user/member/create_account_ng";
		
		return nextPage;
	}
	
	// 로그인
	@GetMapping("/loginForm")
	public String loginForm() {
		System.out.println("[UserMemberController] loginForm");
		
		String nextPage = "/user/member/login_form";
		
		return nextPage;
	}
	
	// 로그인 확인
	@PostMapping("/loginConfirm")
	public String loginConfirm(UserMemberVo userMemberVo, HttpSession session) {
		System.out.println("[UserMemberController] loginConfirm");
		
		String nextPage = "user/member/login_ok";
		
		UserMemberVo loginedMemberVo = userMemberService.loginConfirm(userMemberVo);
		
		if(loginedMemberVo == null) {
			nextPage = "user/member/login_ng";
		} else {
			session.setAttribute("loginedMemberVo", loginedMemberVo);
			session.setMaxInactiveInterval(60*30);
			
			
		} 
		return nextPage;
	}
	
	// 로그아웃 확인
	@GetMapping("/logoutConfirm")
	public String logoutConfirm(HttpSession session) {
		System.out.println("[UserMemberController] logoutConfirm");
		
		String nextPage = "redirect:/";
		
		session.invalidate();
		return nextPage;
	}
	
	// 내 계정
	@GetMapping("/myAccount")
	public String myAccount(UserMemberVo userMemberVo, Model model) {
		String nextPage = "user/member/my_account";
		
		UserMemberVo loginedMemberVo = userMemberService.loginConfirm(userMemberVo);
		
		model.addAttribute("loginedMemberVo", loginedMemberVo);
				
		return nextPage;
	}
	
}
