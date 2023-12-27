package com.company.smutify.song;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class SongVo {
	int id;
	String singer;
	String title;
	String genre;
	
	int s_u_no;
	String s_u_thumbnail;
	String s_u_name;
	String s_u_content;
	int u_m_no;
}
