package com.company.smutify.song.user;

import java.util.List;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import com.company.smutify.song.PlayListVo;
import com.company.smutify.song.SongVo;
import com.company.smutify.song.user.util.UploadFileService;
import com.company.smutify.user.member.UserMemberVo;

@Controller
@RequestMapping("/song/user")
public class SongController {
	
	@Autowired
	SongService songService;
	
	@Autowired
	UploadFileService uploadFileService;
	
	// 메인 페이지
	@GetMapping("/main")
	public String main(HttpSession session, Model model) {
		System.out.println("[SongController] main");
		
		String nextPage = "user/song/main";
		
		UserMemberVo loginedMemberVo = (UserMemberVo) session.getAttribute("loginedMemberVo");
		
		List<PlayListVo> playListVos = songService.listOfPlaylist(loginedMemberVo.getU_m_no());
		
		model.addAttribute("playListVos", playListVos);
		
		return nextPage;
	}
	
	// 검색 페이지
	@GetMapping("/searchSong")
	public String search_song(HttpSession session, Model model) {
		System.out.println("[SongController] search song");
		
		String nextPage = "user/song/search_song";
		
		List<SongVo> songVos = songService.listOfSong();
		
		model.addAttribute("songVos", songVos);
		 
		UserMemberVo loginedMemberVo = (UserMemberVo) session.getAttribute("loginedMemberVo");
		
		List<PlayListVo> playListVos = songService.listOfPlaylist(loginedMemberVo.getU_m_no());
		
		model.addAttribute("playListVos", playListVos);
		
		return nextPage;
	}
	
	// 노래 검색
	@GetMapping("/searchSongConfirm") 
	public String searchSongConfirm(@RequestParam("name") String name, @RequestParam("sort") String method, SongVo songVo, 
								Model model, HttpSession session) {
		System.out.println("[SongController] searchSongConfirm");
		
		String nextPage = "user/song/search_song";
		
		List<SongVo> songVos = songService.searchSongConfirm(name, method);
		
		model.addAttribute("songVos", songVos);
		
		UserMemberVo loginedMemberVo = (UserMemberVo) session.getAttribute("loginedMemberVo");
		
		List<PlayListVo> playListVos = songService.listOfPlaylist(loginedMemberVo.getU_m_no());
		
		model.addAttribute("playListVos", playListVos);
		
		return nextPage;
	}
	
	// 노래 장르 변경
	@GetMapping("/changeGenreConfirm")
	public String changeGenreConfirm(@RequestParam("id") int id, @RequestParam("genre") String genre, HttpSession session) {
		System.out.println("[SongController] changeGenreConfirm");
		
		String nextPage = "redirect:/song/user/searchSong";
		
		songService.changeGenre(id,genre);
		return nextPage;
	}
	
	// 플레이리스트 생성
	@GetMapping("/addNewPlaylist")
	public String addNewPlaylist(@RequestParam("id") int id) {
		System.out.println("[PlaylistController] addNewPlaylist");
		
		String nextPage = "user/playlist/create_playlist";
		
		return nextPage;
	}
	
	// 플레이리스트 생성 확인
	@PostMapping("addNewPlaylistConfirm")
	public String addNewPlaylistConfirm(PlayListVo playListVo, @RequestParam("file")
										MultipartFile file, HttpSession session) {
		System.out.println("[SongController] addNewPlaylistConfirm");
		
		String nextPage = "user/playlist/create_playlist_ok";
		
		UserMemberVo loginedMemberVo = (UserMemberVo) session.getAttribute("loginedMemberVo");
		//System.out.println("사용자 정보 가져오기" + userMemberVo.getU_m_no());
		
		// 파일저장
		String savedFileName = uploadFileService.upload(file);
		
		if(savedFileName != null) {
			playListVo.setS_u_thumbnail(savedFileName);
			int result = songService.addNewPlaylistConfirm(playListVo, loginedMemberVo.getU_m_no());
			
			if(result <= 0)
				nextPage = "user/playlist/create_playlist_ng";
		} else {
			nextPage = "user/playlist/create_playlist_ng";
		}
		return nextPage;
	}
	
	// 플레이리스트에 노래 추가하기
	@GetMapping("/addSongPlaylist")
	public String addSongPlaylist(@RequestParam("playlist")int playlist, @RequestParam("id") int id) {
		System.out.println("[SongController] addSongPlaylist");
		
		String nextPage = "redirect:/song/user/searchSong";

		songService.addSongPlaylist(playlist, id);
		
		return nextPage;
		
	}
	
	// 플레이리스트 화면
	@GetMapping("/playListDetail")
	public String playListDetail(@RequestParam("s_u_no") int s_u_no, Model model) {
		System.out.println("[SongController] playListDetail");
		
		String nextPage = "user/playlist/playlist_detail";
		
		List<PlayListVo> playListVos = songService.playListDetail(s_u_no);
		
		if(!playListVos.isEmpty())
			model.addAttribute("playListVos", playListVos);
		else {
			playListVos = songService.onlyPlaylist(s_u_no);
			model.addAttribute("playListVos", playListVos);
		}
		return nextPage;
	}
	
	// 플레이 리스트에서 곡 삭제
	@GetMapping("/deleteSongConfirm")
	public String deleteSongConfirm(@RequestParam("p_id") int p_id, @RequestParam("id") int id) {
		System.out.println("[SongController] deleteSongConfirm");
		
		String nextPage = "redirect:/song/user/playListDetail?s_u_no=" + p_id;
		
		songService.deleteSong(p_id, id);
		
		return nextPage;
	}
	
	// 플레이리스트 삭제
	@GetMapping("/deletePlaylistConfirm")
	public String deletePlaylistConfirm(@RequestParam("p_id") int p_id) {
		System.out.println("[SongController] deletePlayListConfirm");
		
		String nextPage = "redirect:/song/user/main";
		
		// 플레이리스트 삭제
		songService.deletePlaylist(p_id);
		// 플레이리스트 곡 삭제 
		songService.deleteAllSong(p_id);
		
		return nextPage;
	}
	
	// 플레이리스트 수정하기
	@GetMapping("/modifyPlaylist")
	public String modifyPlaylist(@RequestParam("p_id") int p_id, Model model) {
		System.out.println("[SongController] modifyPlaylistConfirm");
		
		String nextPage = "user/playlist/modify_playlist";
		List<PlayListVo> playListVos = songService.onlyPlaylist(p_id);
		
		
		model.addAttribute("playListVos", playListVos);
		
		return nextPage;
	}
	
	@PostMapping("/modifyPlaylistConfirm")
	public String modifyPlaylistConfirm(PlayListVo playListVo, @RequestParam("file")
										MultipartFile file, HttpSession session) {
		String nextPage = "user/playlist/modify_playlist_ok";
		
		UserMemberVo loginedMemberVo = (UserMemberVo) session.getAttribute("loginedMemberVo");
		//System.out.println("사용자 정보 가져오기" + userMemberVo.getU_m_no());
		
		if(!file.getOriginalFilename().equals("")) {
			String savedFileName = uploadFileService.upload(file);
			if(savedFileName != null)
				playListVo.setS_u_thumbnail(savedFileName);
		} 
		
		System.out.println("플레이 리스트 번호 확인" + playListVo.getS_u_no());
		
		int result = songService.modifyPlaylistConfirm(playListVo, loginedMemberVo.getU_m_no());
		
		if(result <= 0)
			nextPage = "user/playlist/modify_playlist_ng";
		
		return nextPage;
	}
	
	
}
