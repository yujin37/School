package com.company.smutify.song.user;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Component;

import com.company.smutify.song.PlayListVo;
import com.company.smutify.song.SongVo;


@Component
public class SongDao {
	
	@Autowired
	JdbcTemplate jdbcTemplate;
	
	public List<SongVo> selectSong() {
		System.out.println("[SongDao] selectSong");
		
		String sql = "SELECT * FROM song_table";
		
		List<SongVo> songVos = new ArrayList<SongVo>();
		
		try {
			songVos = jdbcTemplate.query(sql, new RowMapper<SongVo> () {
				@Override
				public SongVo mapRow(ResultSet rs, int rowNum) throws SQLException {
					SongVo songVo = new SongVo();
					songVo.setId(rs.getInt("id"));
					songVo.setSinger(rs.getString("singer"));
					songVo.setTitle(rs.getString("title"));
					songVo.setGenre(rs.getString("genre"));
				
					
					return songVo;
					
				}
			});
		} catch(Exception e) {
			e.printStackTrace();
		}
		return songVos;
	}
	
	public List<SongVo> selectSongBySearch(String name, String method){
		System.out.println("[SongDao] selectSong");
		System.out.println("장르 확인하기 " + name);
		String sql = "";
		
		if(method != "")
			sql = "SELECT * FROM song_table"
					+ " WHERE title LIKE ? OR singer LIKE ? OR genre LIKE ? "
						+ "ORDER BY " + method + " ASC";
		else
			sql = "SELECT * FROM song_table"
					+ " WHERE (title LIKE ? OR singer LIKE ? OR genre LIKE ?)";
		List<SongVo> songVos = new ArrayList<SongVo>();
		
		try {
			songVos = jdbcTemplate.query(sql, new RowMapper<SongVo> () {
				@Override
				public SongVo mapRow(ResultSet rs, int rowNum) throws SQLException {
					SongVo songVo = new SongVo();
					songVo.setId(rs.getInt("id"));
					songVo.setSinger(rs.getString("singer"));
					songVo.setTitle(rs.getString("title"));
					songVo.setGenre(rs.getString("genre"));
				
					
					return songVo;
					
				}
			}, "%" + name + "%",  "%" + name + "%",  "%" + name + "%");
			
		} catch(Exception e) {
			e.printStackTrace();
		}
		return songVos.size() > 0 ? songVos : null;
	}
	
	public void changeGenre(int id, String genre) {
		System.out.println("[SongDao] changeGenre");
		
		String sql = "UPDATE song_table SET genre = ? WHERE id = ?";
		
		System.out.println("장르 확인" + genre + "여기");
		
		try {
			if(genre!="")
				jdbcTemplate.update(sql, genre, id);
			else
				jdbcTemplate.update(sql, null, id);
			
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		
	}
	
	public boolean isName(String s_u_name, int u_m_no) {
		System.out.println("[SongDao] isName");
		
		String sql = "SELECT COUNT(*) FROM smutify_playlist "
					+ "WHERE s_u_name = ? AND u_m_no = ?";
		
		int result = jdbcTemplate.queryForObject(sql,  Integer.class, s_u_name, u_m_no);
		
		return result > 0 ? true : false;
	}
	
	public int insertPlaylist(PlayListVo playListVo, int u_m_no) {
		System.out.println("[SongDao] insertPlaylist");
		
		String sql = "INSERT INTO smutify_playlist(s_u_thumbnail, "
				+ "s_u_name, s_u_content, u_m_no) "
				+ "VALUES(?,?,?,?)";
		
		int result = -1;
		
		try {
			result = jdbcTemplate.update(sql, playListVo.getS_u_thumbnail(),
									playListVo.getS_u_name(), playListVo.getS_u_content(),
									u_m_no);
		} catch(Exception e) {
			e.printStackTrace();
		}
		return result;
	}
	
	public List<PlayListVo> selectPlaylist(int u_m_no) {
		System.out.println("[SongDao] selectSong");
		
		String sql = "SELECT * FROM smutify_playlist WHERE u_m_no = ?";
		
		List<PlayListVo> playListVos = new ArrayList<PlayListVo>();
		
		try {
			playListVos = jdbcTemplate.query(sql, new RowMapper<PlayListVo> () {
				@Override
				public PlayListVo mapRow(ResultSet rs, int rowNum) throws SQLException {
					PlayListVo playListVo = new PlayListVo();
					playListVo.setS_u_no(rs.getInt("s_u_no"));
					playListVo.setS_u_thumbnail(rs.getString("s_u_thumbnail"));
					playListVo.setS_u_name(rs.getString("s_u_name"));
					playListVo.setS_u_content(rs.getString("s_u_content"));
					playListVo.setU_m_no(rs.getInt("u_m_no"));
					
					return playListVo;
					
				}
			}, u_m_no);
		} catch(Exception e) {
			e.printStackTrace();
		}
		return playListVos;
	}
	
	public void addSongPlaylist(int playlist, int id) {
		System.out.println("[SongDao] addSongPlaylist");
		
		String sql = "INSERT INTO smutify_playlist_song(s_u_no, id)"
				+ "VALUES(?,?)";
		
		int result = -1;
		
		try {
			result = jdbcTemplate.update(sql, playlist, id);
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public List<PlayListVo> playListDetail(int s_u_no){
		System.out.println("[SongDao] playListDetail");
		
		String sql = "SELECT * FROM smutify_playlist_song ps "
				+ "JOIN smutify_playlist p "
				+ "ON ps.s_u_no = p.s_u_no "
				+ "JOIN song_table s "
				+ "ON ps.id = s.id "
				+ "WHERE ps.s_u_no = ?";
		
		List<PlayListVo> playListVos = new ArrayList<PlayListVo>();
		
		try {
			playListVos = jdbcTemplate.query(sql, new RowMapper<PlayListVo> () {
				@Override
				public PlayListVo mapRow(ResultSet rs, int rowNum) throws SQLException {
					PlayListVo playListVo = new PlayListVo();
					playListVo.setS_u_no(rs.getInt("s_u_no"));
					playListVo.setS_u_thumbnail(rs.getString("s_u_thumbnail"));
					playListVo.setS_u_name(rs.getString("s_u_name"));
					playListVo.setS_u_content(rs.getString("s_u_content"));
					playListVo.setU_m_no(rs.getInt("u_m_no"));
					
					playListVo.setP_no(rs.getInt("p_no"));
					playListVo.setId(rs.getInt("id"));
					
					playListVo.setSinger(rs.getString("singer"));
					playListVo.setTitle(rs.getString("title"));
					playListVo.setGenre(rs.getString("genre"));
					
					
					return playListVo;
				}
			} , s_u_no);
		} catch(NumberFormatException e) {
			
		}catch(Exception e) {
		
			e.printStackTrace();
		}
		
		return playListVos;
	}
	
	public void deleteSong(int p_id, int id) {
		System.out.println("[SongDao] deleteSong");
		
		String sql = "DELETE FROM smutify_playlist_song WHERE s_u_no = ? AND id = ?";
		
		try {
			jdbcTemplate.update(sql, p_id, id);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public List<PlayListVo> onlyPlaylist(int s_u_no) {
		System.out.println("[SongDao] onlyPlaylist");
		
		String sql = "SELECT * FROM smutify_playlist WHERE s_u_no = ?";
		
		List<PlayListVo> playListVos = new ArrayList<PlayListVo>();
			
		try {
			playListVos = jdbcTemplate.query(sql, new RowMapper<PlayListVo> () {
				@Override
				public PlayListVo mapRow(ResultSet rs, int rowNum) throws SQLException {
					PlayListVo playListVo = new PlayListVo();
					playListVo.setS_u_no(rs.getInt("s_u_no"));
					playListVo.setS_u_thumbnail(rs.getString("s_u_thumbnail"));
					playListVo.setS_u_name(rs.getString("s_u_name"));
					playListVo.setS_u_content(rs.getString("s_u_content"));
					playListVo.setU_m_no(rs.getInt("u_m_no"));
					
					
					return playListVo;
				}
			} , s_u_no);
		} catch(NumberFormatException e) {
			
		}catch(Exception e) {
		
			e.printStackTrace();
		}
		
		return playListVos;
	}
	
	public void deletePlaylist(int p_id) {
		System.out.println("[SongDao] deletePlaylist");
		
		String sql = "DELETE FROM smutify_playlist WHERE s_u_no = ?";
		
		try {
			jdbcTemplate.update(sql, p_id);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void deleteAllSong(int p_id) {
		System.out.println("[SongDao] deletePlaylist");
		
		String sql = "DELETE FROM smutify_playlist_song WHERE s_u_no = ?";
		
		try {
			jdbcTemplate.update(sql, p_id);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public int updatePlaylist(PlayListVo playListVo, int u_m_no) {
		System.out.println("[SongDao] updatePlaylist" + playListVo.getS_u_no());
		
		List<String> args = new ArrayList<String>();
		
		String sql = "UPDATE smutify_playlist SET ";
		
		if(playListVo.getS_u_thumbnail() != null) {
			sql += "s_u_thumbnail = ?, ";
			args.add(playListVo.getS_u_thumbnail());
		}
		
		sql += "s_u_name = ?, ";
		args.add(playListVo.getS_u_name());
		sql += "s_u_content = ? ";
		args.add(playListVo.getS_u_content());
		
		sql += "WHERE (s_u_no = ? AND u_m_no = ?)";
		args.add(Integer.toString(playListVo.getS_u_no()));
		args.add(Integer.toString(u_m_no));
		
		
		int result = -1;
		
		try {
			result = jdbcTemplate.update(sql, args.toArray());
		} catch(Exception e) {
			e.printStackTrace();
		}
		return result;
	}
}
