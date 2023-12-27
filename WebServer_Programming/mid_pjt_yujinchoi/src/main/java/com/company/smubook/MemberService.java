package com.company.smubook;

import java.io.IOException;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class MemberService {
	
	@Autowired
	MemberDao memberDao; 
	public int signUpConfirm(MemberVo memberVo) throws IOException {
		System.out.println("SingUpConfirm");
		
		System.out.println("m_username" + memberVo.getM_username());
		System.out.println("m_pw" + memberVo.getM_pw());
		
		memberDao.insertMember(memberVo);
		return 0;
	}
	
	public MemberVo loginConfirm(MemberVo memberVo) throws IOException {
		System.out.println("loginConfirm");
		
		MemberVo loginedMember = memberDao.selectMember(memberVo);
		System.out.println("결과" + loginedMember);
		return loginedMember;
	}
}
