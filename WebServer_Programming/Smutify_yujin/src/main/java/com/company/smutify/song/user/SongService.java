package com.company.smutify.song.user;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.company.smutify.song.PlayListVo;
import com.company.smutify.song.SongVo;

@Service
public class SongService {
	
	final static public int PLAYLIST_NAME_ALREADY_EXIST = 0;
	final static public int PLAYLIST_CREATE_SUCCESS = 1;
	final static public int PLAYLIST_CREATE_FAIL = -1;
	
	@Autowired
	SongDao songDao;
	
	public List<SongVo> listOfSong() {
		System.out.println("[SongService] listOfSong");
		
		return songDao.selectSong();
	}
	
	public List<SongVo> searchSongConfirm(String name, String method) {
		System.out.println("[SongService] searchSongConfirm");
		
		return songDao.selectSongBySearch(name, method);
	}
	
	public void changeGenre(int id, String genre) {
		System.out.println("[SongService] changeGenre");
		
		songDao.changeGenre(id, genre);
	}
	
	public int addNewPlaylistConfirm(PlayListVo playListVo, int u_m_no) {
		System.out.println("[SongService] addNewPlaylistConfirm");
		
		boolean isName = songDao.isName(playListVo.getS_u_name(), u_m_no);
		
		if(!isName) {
			int result = songDao.insertPlaylist(playListVo, u_m_no);
			
			if(result > 0)
				return PLAYLIST_CREATE_SUCCESS;
			else
				return PLAYLIST_CREATE_FAIL;
			
		} else {
			return PLAYLIST_NAME_ALREADY_EXIST;
		}
	}
	
	public List<PlayListVo> listOfPlaylist(int u_m_no) {
		System.out.println("[SongService] listOfSong");
		
		return songDao.selectPlaylist(u_m_no);
	}
	
	public void addSongPlaylist(int playlist, int id) {
		System.out.println("[SongService] addSongPlaylist");
		
		songDao.addSongPlaylist(playlist, id); 
	}
	
	public List<PlayListVo> playListDetail(int s_u_no) {
		System.out.println("[SongService] playListDetail");
		
		return songDao.playListDetail(s_u_no);
	}
	
	public void deleteSong(int p_id, int id) {
		System.out.println("[SongService] deleteSong");
		
		songDao.deleteSong(p_id, id);
	}
	
	public List<PlayListVo> onlyPlaylist(int s_u_no){
		System.out.println("[SongService] onlyPlayListVo");
		
		return songDao.onlyPlaylist(s_u_no);
	}
	
	public void deletePlaylist(int p_id) {
		System.out.println("[SongService] deletePlaylist");
		
		songDao.deletePlaylist(p_id);
	}
	
	public void deleteAllSong(int p_id) {
		System.out.println("[SongService] deleteAllSong");
		
		songDao.deleteAllSong(p_id);
	}
	
	public int modifyPlaylistConfirm(PlayListVo playlistVo, int u_m_no) {
		System.out.println("[SongService] modifyPlaylistConfirm");
		return songDao.updatePlaylist(playlistVo, u_m_no);
	}
}
