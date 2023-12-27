package com.company.smubook;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

//import org.apache.taglibs.standard.extra.spath.Path;
import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.Resource;
import org.springframework.stereotype.Component;
import org.springframework.util.FileCopyUtils;
import org.springframework.util.StreamUtils;

@Component
public class MemberDao {
	private static Map<String, MemberVo> memberDB = new HashMap<String, MemberVo>();
	
	//일단 확인용
	private static void readMembersFromTxt() throws IOException {
	    // txt 파일을 읽기 위한 FileReader 객체 생성
	    FileReader fr = new FileReader("mid_pjt_yujinchoi/members.txt");

	    // BufferedReader 객체 생성
	    BufferedReader br = new BufferedReader(fr);

	    // 파일의 내용을 한 줄씩 읽어서 memberDB에 저장
	    String line;
	    while ((line = br.readLine()) != null) {
	        // 한 줄의 내용을 ","로 분리
	        String[] memberInfo = line.split(",");

	        // MemberVo 객체 생성
	        MemberVo memberVo = new MemberVo();
	        memberVo.setM_username(memberInfo[0]);
	        memberVo.setM_pw(memberInfo[1]);

	        // memberDB에 저장
	        memberDB.put(memberVo.getM_username(), memberVo);
	    }

	    // BufferedReader 객체 닫기
	    br.close();
	} //여기까지
	public void insertMember(MemberVo memberVo) throws IOException {
	    System.out.println("insertMember");
	    //ClassPathResource resource = new ClassPathResource("members.csv");

        String newUsername = memberVo.getM_username();
        String newPassword = memberVo.getM_pw();
        String[] newMember = {newUsername, newPassword};
        
        String filePath = "C:\\Coding_Dir\\springMVC_STS\\project\\mid_pjt_yujinchoi\\src\\main\\resources\\members.txt";
        
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath));
        		BufferedWriter writer = new BufferedWriter(new FileWriter(filePath, true))) {
            // 데이터 쓰기 (파일 끝에 추가)
        	String line;
        	boolean flag = false;
        	while ((line = reader.readLine()) != null) {
        		if(line.contains(newUsername)) {
        			flag = true;
        			break;
        		}
        	}
        	if(!flag) {
	            writer.write(String.join(",", newMember));
	            writer.newLine(); // 다음 라인으로 이동
        	}
        } catch (IOException e) {
            e.printStackTrace();
            throw e; // 예외를 다시 던지거나 처리하세요.
        } 
	}
	
	public MemberVo selectMember(MemberVo memberVo) throws IOException {
		System.out.println("[MemberDao] selectMember()");
		readMembersFromTxt();
		System.out.println(memberVo.m_username +  memberVo.m_pw);
		MemberVo signInedMember = memberDB.get(memberVo.getM_username());
		
		if(signInedMember != null && memberVo.getM_pw().equals(signInedMember.getM_pw()))
			return signInedMember;
		else
			return null;
	}
}
