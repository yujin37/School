package com.company.smutify.user.member;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.sql.ResultSet;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Component;

@Component
public class UserMemberDao {
	
	@Autowired
	JdbcTemplate jdbcTemplate;
	
	public boolean isUserMember(String u_m_username) {
		System.out.println("[UserMemberDao] isUserMember");
		
		String sql = "SELECT COUNT(*) FROM smutify_user WHERE u_m_username = ?";
		
		int result = jdbcTemplate.queryForObject(sql,Integer.class, u_m_username);
		
		return result > 0 ? true: false;
	}
	
	public int insertUserAccount(UserMemberVo userMemberVo) {
		System.out.println("[UserMemberDao] insertUserAccount");
		
		String sql = "INSERT INTO smutify_user(u_m_username) VALUES(?)";
		
		int result = -1;
		
		try {
			result = jdbcTemplate.update(sql, userMemberVo.getU_m_username());
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		return result;
	}
	
	public UserMemberVo selectUser(UserMemberVo userMemberVo) {
		System.out.println("[UserMemberDao] selectUser");
		
		String sql = "SELECT * FROM smutify_user WHERE u_m_username = ?";
		
		List<UserMemberVo> userMemberVos = new ArrayList<UserMemberVo>();
		
		try {
			userMemberVos = jdbcTemplate.query(sql, new RowMapper<UserMemberVo>() {
				@Override
				public UserMemberVo mapRow(ResultSet rs, int rowNum) throws SQLException {
					UserMemberVo userMemberVo = new UserMemberVo();
					
					userMemberVo.setU_m_no(rs.getInt("u_m_no"));
					userMemberVo.setU_m_username(rs.getString("u_m_username"));
					return userMemberVo;
				}
				
				
				
			}, userMemberVo.getU_m_username());
		} catch (Exception e) {
			e.printStackTrace();
		}
		return userMemberVos.size() > 0 ? userMemberVos.get(0) : null;
	}
	
	
	
}
