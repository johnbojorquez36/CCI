#include <map>
#include <vector>
#include <queue>
#include <string>

class Artist;
class Album;

class Song {
  std::string title;
  Artist* artist;
  Album* album;
  int year;

public:
  Song(std::string title, Artist* artist, Album* album, int year);
  std::string getTitle();
  Artist* getArtist();
  Album* getAlbum();
  int getYear();
};

class Album {
  std::string title;
  Artist* artist;
  int year;
  std::vector<Song*> songs;

public:
  Album(std::string title, Artist* artist, int year, std::vector<Song*> songs);
  std::string getTitle();
  Artist* getArtist();
  int getYear();
  std::vector<Song*>::iterator begin();
  std::vector<Song*>::iterator end();
};

class Artist {
  std::string name;
  std::vector<Album*> albums;

public:
  Artist(std::string title, Artist* artist, int year, std::vector<Album*> albums);
  std::string getName();
  std::vector<Album*>::iterator begin();
  std::vector<Album*>::iterator end();
};

class Playlist {
  Song* playing;
  std::queue<Song*> songs;

public:
  void addSong(Song* song) {
    if (!playing) playing = song;
    else songs.push(song);
  }

  Song* getPlaying() {
    return playing;
  }

  Song* getNextSong() {
    return songs.front();
  }

  void advanceSong() {
    playing = songs.front();
    songs.pop();
  }
};

class Jukebox {
  Playlist playlist;
  /* May have multiple songs/albums/artists with same name */
  std::map<std::string, std::vector<Song*>> songs;
  std::map<std::string, std::vector<Album*>> albums;
  std::map<std::string, std::vector<Artist*>> artists;
  
public:
  void addToPlaylist(Song* s);
  void addToPlaylist(Album* s);
  std::vector<Song*> searchSongs(std::string title);
  std::vector<Album*> searchAlbums(std::string title);
  std::vector<Artist*> searchArtists(std::string title);
};

