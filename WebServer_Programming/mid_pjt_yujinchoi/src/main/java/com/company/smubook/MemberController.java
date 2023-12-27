package com.company.smubook;

import java.io.IOException;

import org.springframework.beans.factory.annotation.Autowired;
//import java.text.DateFormat;
//import java.util.Date;
//import java.util.Locale;
//
//import org.slf4j.Logger;
//import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Controller;
//import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
//import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class MemberController {
	//MemberService memberService = new MemberService();
	
	@Autowired
	MemberService memberService;
	@RequestMapping("/")
	public String login() {
		System.out.println("시작");
		return "login";
	}
	
	@RequestMapping("/signUp")
	public String signUp() {
	    return "signUp";
	}
	
	@RequestMapping("/signUpConfirm") //회원가입
    public String signUpConfirm(MemberVo memberVo) throws IOException {
        System.out.println("signUp");
        System.out.println("m_username" + memberVo.getM_username());
        System.out.println("m_pw" + memberVo.getM_pw());
        memberService.signUpConfirm(memberVo);
        return "redirect:/";
    }
	
	@RequestMapping("/loginConfirm") //로그인
	public String loginConfirm(@RequestParam("m_username") String m_username, @RequestParam("m_pw") String m_pw) {
		System.out.println("[MemberController] signInConfirm()");
		
		//서비스 호출
		//MemberVo loginedMember = memberService.loginConfirm(memberVo);
		return "mainFeed";
		//if(loginedMember != null)
		//	return "mainFeed";
		//else
		//	return "loginError";
		//return null;
	}

}