package com.company.smutify.song.user.util;

import java.io.File;
import java.util.UUID;

import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

@Service
public class UploadFileService {
	public String upload(MultipartFile file) {
		
		boolean result = false;
		
		// 파일 저장
		String fileOriName = file.getOriginalFilename();
		String fileExtension = fileOriName.substring(fileOriName.lastIndexOf('.'), fileOriName.length());
		//String fileExtension = fileOriName.substring(fileOriName.lastIndexOf("."));
		String uploadDir = "/home/yj061628/downloads/tomcat/webapps/smutify";
		//String uploadDir = "C:\\smutify\\upload\\";

		
		UUID uuid = UUID.randomUUID();
		String uniqueName = uuid.toString().replaceAll("-", "");
		
		File saveFile = new File(uploadDir + File.separator + uniqueName + fileExtension);
		//File saveFile = new File(uploadDir + "\\" + uniqueName + fileExtension);
		
		if (!saveFile.getParentFile().exists()) {
            
            saveFile.getParentFile().mkdirs();
        }
		
		try {
			file.transferTo(saveFile);
			result = true;
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		if(result) {
			System.out.println("[UploadFileService] FILE UPLOAD SUCCESS!!");
			return uniqueName + fileExtension;
		} else {
			System.out.println("[UploadFileService] FILE UPLOAD FAIL!!");
			
			return null;
		}
	}

}
