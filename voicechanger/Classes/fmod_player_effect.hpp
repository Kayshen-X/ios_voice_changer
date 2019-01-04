//
//  fmod_player_effect.hpp
//  Pods-VoiceDemo
//
//  Created by kayshen on 2019/1/4.
//

#ifndef fmod_player_effect_hpp
#define fmod_player_effect_hpp

#include <stdio.h>
#include "fmod.hpp"

void fmod_set_audio_effect(int flag, FMOD_SYSTEM *fmod_system, FMOD_CHANNEL *fmod_channel, FMOD_DSP *fmod_dsp);

#endif /* fmod_player_effect_hpp */
