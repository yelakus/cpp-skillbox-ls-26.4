#include <iostream>
#include <string>
#include <vector>

/*
    {"Enemy", "Bones", "Radioactive", "Thunder"};
    {"2021", "2022", "2013", "2017"};
    {214, 186, 202, 197};
*/

class Track
{
public:
    std::string musicTitle;
    std::string creationDate;
    int duration;

    Track(const std::string& musicTitle, const std::string& creationDate, int duration)
    : musicTitle(musicTitle), creationDate(creationDate), duration(duration) {}

    void displayInfo() const {
    std::cout << "Music Title: " << musicTitle << "\n"
              << "Creation Date: " << creationDate
              << "Duration: " << duration << " seconds\n";
    }
};

class Player
{
    std::vector<Track> tracks;
    bool isPlaying = false;
    bool isPaused = false;
    int currentTrackIndex = -1;

public:
    void addTrack(const Track& track) {
        tracks.push_back(track);
    }

    void playMusic() {
        std::string inputMusic;
        std::cout << "Enter music title" << std::endl;
        std::cin >> inputMusic;

        if (isPlaying) return;

        for (const auto track : tracks){
            if(inputMusic == track.musicTitle){
                std::cout << inputMusic << " is playing" << std::endl;
                isPlaying = true;
                isPaused = false;
            }
        }
    }

    void pauseMusic(){
        if (!isPlaying || isPaused) return;
        
        std::cout << "Paused" << std::endl;
    }

    void nextMusic(){
        currentTrackIndex = rand() % tracks.size();
        isPlaying = true;
        isPaused = false;
        std::cout << "Next song:" << std::endl;
        tracks[currentTrackIndex].displayInfo();
    }

    void stop() {
        if (!isPlaying) return;

        isPlaying = false;
        isPaused = false;
        std::cout << tracks[currentTrackIndex].musicTitle << " stopped." << std::endl;
        currentTrackIndex = -1;
    }
    
};

int main()
{
    Player* player = new Player();

    player->addTrack(Track("Enemy", "2021", 214));
    player->addTrack(Track("Bones", "2022", 186));
    player->addTrack(Track("Radioactive", "2013", 202));
    player->addTrack(Track("Thunder", "2017", 197));

    std::string inputComand;

    while(true)
    {
        std::cout << "Enter comand(play, pause, next, stop or exit):" << std::endl;
        std::cin >> inputComand;

        if (inputComand == "play") player->playMusic();
        else if (inputComand == "pause") player->pauseMusic();
        else if (inputComand == "next") player->nextMusic();
        else if (inputComand == "stop") player->stop();
        else if (inputComand == "exit") break;
        else std::cout << "Unknown command. Try again.\n";
    }

    delete player;
}