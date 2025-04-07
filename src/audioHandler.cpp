#include "../include/audioHandler.h"

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
    musicMap[name] = LoadMusicStream(filepath.c_str());
}

void AudioHandler::loadSound(const string &name, const string &filepath)
{
    soundMap[name] = LoadSound(filepath.c_str());
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
