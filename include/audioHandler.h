#pragma once
#include <raylib.h>
#include <string>
#include <unordered_map>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

class AudioHandler
{
public:
    AudioHandler();
    ~AudioHandler();
    void playBackgroundMusic(const string &name, float volume = 1.0f);
    void stopBackgroundMusic();
    void pauseBackgroundMusic();
    void resumeBackgroundMusic();
    void playSoundEffect(const string &name, float volume = 1.0f);
    void update();
    void loadMusic(const string &name, const string &filepath);
    void loadSound(const string &name, const string &filepath);

private:
    unordered_map<string, Music> musicMap;
    unordered_map<string, Sound> soundMap;
    Music *currentMusic = nullptr;
};
