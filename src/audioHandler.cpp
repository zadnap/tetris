#include "../include/audioHandler.h"

std::string getAssetPath(const std::string &filename)
{
    fs::path basePath = fs::current_path();
    return (basePath / "assets" / "audio" / filename).string();
}

AudioHandler::AudioHandler()
{
    InitAudioDevice();
}

AudioHandler::~AudioHandler()
{
    for (auto &[key, music] : musicMap)
        UnloadMusicStream(music);
    for (auto &[key, sound] : soundMap)
        UnloadSound(sound);
    CloseAudioDevice();
}

void AudioHandler::loadMusic(const string &name, const string &filepath)
{
    musicMap[name] = LoadMusicStream(getAssetPath(filepath).c_str());
}

void AudioHandler::loadSound(const string &name, const string &filepath)
{
    soundMap[name] = LoadSound(getAssetPath(filepath).c_str());
}

void AudioHandler::playBackgroundMusic(const string &name, float volume)
{
    if (musicMap.find(name) != musicMap.end())
    {
        currentMusic = &musicMap[name];
        SetMusicVolume(*currentMusic, volume);
        PlayMusicStream(*currentMusic);
    }
}

void AudioHandler::stopBackgroundMusic()
{
    StopMusicStream(*currentMusic);
}

void AudioHandler::playSoundEffect(const string &name, float volume)
{
    if (soundMap.find(name) != soundMap.end())
    {
        PlaySound(soundMap[name]);
        SetSoundVolume(soundMap[name], volume);
    }
}

void AudioHandler::update()
{
    if (currentMusic)
    {
        UpdateMusicStream(*currentMusic);
    }
}
